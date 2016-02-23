#include <QApplication>
#include <iostream>
#include <QImage>
#include <QColor>
#include <QFileDialog>
#include "extractedobject.h"
#include "recursiveiterationalgorithm.h"
#include "HumanPartsExtractorStorage/humanpartsextractor.h"
#include "HumanPartsExtractorStorage/bodypartshaperecognizeralgorithm.h"
#include "humansilhouetteprobability.h"

QImage ConvertToBlackWhite(QImage image);
void ShowPeoples(std::vector<double> peoples);

int main(int argc, char **argv)
{
    QApplication a(argc, argv);
    QString fileName = QFileDialog::getOpenFileName(0, "Select image from file", QDir::homePath(), "Files (*.png *.jpg *.jpeg *.bmp)");
    QImage image = QImage(fileName, "PNM");
    image = ConvertToBlackWhite(image);

    std::vector<double> peoples;  
    for (int y = 0; y <image.height(); y++)
    {
       for (int x = 0; x < image.width(); x++)
       {
            QColor clrCurrent(image.pixel(x, y));
            if((int)clrCurrent.blue() == 0)
            {
                HumanSilhouetteProbability * humanSilhouettes = new HumanSilhouetteProbability(&image);
                humanSilhouettes->SetObjectCoordinate(x,y);
                humanSilhouettes->CalculateHumanHeadProbability();
                humanSilhouettes->CalculateHumanCorpusProbability();
                humanSilhouettes->CalculateHumanLegsProbability();
                double percentageSimilarity = humanSilhouettes->GetResult();
                if(percentageSimilarity!=0)
                {
                     peoples.push_back(percentageSimilarity);
                }
                delete humanSilhouettes;
            }
       }
    }
    ShowPeoples(peoples);
    return a.exec();
}

void ShowPeoples(std::vector<double> peoples)
{
    int totalHuman=0;
    std::cout<<std::endl;
    for(int i = 0; i < peoples.size(); i++)
    {
        std::cout<<"object #"<< (i+1) <<" people similarity : "<< peoples[i]<< "%" << std::endl;
        if(peoples[i] > 50)
        {
            totalHuman++;
        }
    }
    std::cout<<"------------------------------------" << std::endl;
    std::cout<<"Humans : "<<totalHuman << std::endl;
}


QImage  ConvertToBlackWhite(QImage image)
{
    QImage imageExit=QImage(image.width(),image.height(),QImage::Format_ARGB32_Premultiplied);
    for (int y = 0; y <image.height(); y++)
    {
       for (int x = 0; x < image.width(); x++)
       {
          QColor clrCurrent(image.pixel(x, y));
            if((int)clrCurrent.red()<122 || (int)clrCurrent.green()<122 || (int)clrCurrent.blue()<122)
            {
                 imageExit.setPixel(x,y, QColor(Qt::black).rgb());
            }
            else
            {
                 imageExit.setPixel(x,y, QColor(Qt::white).rgb());
            }
       }
   }
    return imageExit;
}
