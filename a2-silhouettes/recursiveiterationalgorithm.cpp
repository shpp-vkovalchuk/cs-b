#include "recursiveiterationalgorithm.h"

using namespace std;
RecursiveIterationAlgorithm::RecursiveIterationAlgorithm()
{

}

RecursiveIterationAlgorithm::~RecursiveIterationAlgorithm()
{
    for(int i = 0; i < _image->height(); i++)
    {
        delete _blackWhitePixels[i];
    }
    delete[]_blackWhitePixels;
}

RecursiveIterationAlgorithm::RecursiveIterationAlgorithm(QImage* image)
{
    _blackWhitePixels = new int*[image->height()]();
    for(int i=0; i < image->height(); i++)
    {
        _blackWhitePixels[i]=new int[image->width()]();
    }
    _image= image;
}

ExtractedObject* RecursiveIterationAlgorithm::GetExtractedObjectArray(int startPointX, int startPointY)
{
    _blackWhitePixels[startPointY][startPointX] = 1;
    IterativeRecursion(startPointX,startPointY);
    return ExtractObjectArray();
}

ExtractedObject *RecursiveIterationAlgorithm::ExtractObjectArray()
{
    int minXWidth = _image->width();
    int minYHeight = _image->height();
    int maxXWidth = 0 ,maxYHeight = 0;
    GetExtractedObjectSize(minXWidth, maxXWidth, minYHeight, maxYHeight);

    ExtractedObject* body=new ExtractedObject();
    body->_extractedObjectPixels = CopyArray(minXWidth, maxXWidth, minYHeight, maxYHeight);
    body->width=maxXWidth-minXWidth;
    body->height=maxYHeight-minYHeight;

    return body;
}

void RecursiveIterationAlgorithm::GetExtractedObjectSize(int &minXWidth, int &maxXWidth, int &minYHeight, int &maxYHeight)
{
    for (int y = 0; y <_image->height(); y++)
    {
        for (int x = 0; x < _image->width(); x++)
        {
            if( _blackWhitePixels[y][x]==1)
            {
                if(x < minXWidth)
                {
                    minXWidth=x;
                }
                if(x > maxXWidth)
                {
                    maxXWidth=x;
                }
                if(y < minYHeight)
                {
                    minYHeight=y;
                }
                if(y > maxYHeight)
                {
                    maxYHeight=y;
                }
            }
        }
    }
}

int** RecursiveIterationAlgorithm::CopyArray(int minXWidth,int maxXWidth,int minYHeight,int maxYHeight)
{
    int** blackWhiteExtractedObjectPixels = new int*[(maxYHeight - minYHeight)]();
    for(int i = 0; i < (maxYHeight - minYHeight); i++)
    {
        blackWhiteExtractedObjectPixels[i]=new int[(maxXWidth - minXWidth)]();
    }
    for (int y = minYHeight; y < maxYHeight; y++)
    {
        for (int x = minXWidth; x < maxXWidth; x++)
        {
            blackWhiteExtractedObjectPixels[(y-minYHeight)][(x-minXWidth)]=_blackWhitePixels[y][x];
            if(_blackWhitePixels[y][x] == 1)
            {
                blackWhiteExtractedObjectPixels[(y-minYHeight)][(x-minXWidth)] = 1;
            }
        }
    }
    return blackWhiteExtractedObjectPixels;
}


void RecursiveIterationAlgorithm::IterativeRecursion(int startPointX, int startPointY)
{
    stack< pair<int,int> > myStack;
    myStack.push(make_pair(startPointX,startPointY));

    while(!myStack.empty())
    {
        while(myStack.top().first <_image->width())
        {
            pair<int,int> topPair = myStack.top();
             if((topPair.first+1) <_image->width())
             {
                QColor clrCurrent(_image->pixel((topPair.first+1), topPair.second));
                if((int)clrCurrent.red() == 0 && _blackWhitePixels[topPair.second][(topPair.first+1)] != 1)
                {
                     _image->setPixel((topPair.first+1),topPair.second, QColor(Qt::white).rgb());
                    _blackWhitePixels[topPair.second][(topPair.first+1)] = 1;
                    myStack.push(make_pair((topPair.first+1),topPair.second));
                    continue;
                }
             }
            break;
        }

        while(myStack.top().first != 0)
        {
            pair<int,int> topPair = myStack.top();
            if((topPair.first - 1) != 0)
            {
                QColor clrCurrent(_image->pixel((topPair.first-1), topPair.second));
                if((int)clrCurrent.red() == 0 && _blackWhitePixels[topPair.second][(topPair.first-1)] != 1)
                {
                    _image->setPixel((topPair.first-1),topPair.second, QColor(Qt::white).rgb());
                    _blackWhitePixels[topPair.second][(topPair.first-1)] = 1;
                    myStack.push(make_pair((topPair.first-1),topPair.second));
                    continue;
                }
            }
            break;
        }

        while(myStack.top().second <_image->height())
        {
            pair<int,int> topPair = myStack.top();
            if((topPair.second + 1) < _image->height())
            {
                QColor clrCurrent(_image->pixel(topPair.first, (topPair.second+1)));
                if((int)clrCurrent.red() == 0 && _blackWhitePixels[(topPair.second+1)][topPair.first] != 1)
                {
                   _image->setPixel(topPair.first,(topPair.second+1), QColor(Qt::white).rgb());
                    _blackWhitePixels[(topPair.second+1)][topPair.first] = 1;
                    myStack.push(make_pair(topPair.first,(topPair.second+1)));
                    continue;
                }
            }
            break;
        }

        while(myStack.top().second != 0)
        {
            pair<int,int> topPair = myStack.top();
             if((topPair.second-1) != 0)
             {
                QColor clrCurrent(_image->pixel(topPair.first, (topPair.second-1)));
                if((int)clrCurrent.red() == 0 && _blackWhitePixels[(topPair.second-1)][topPair.first] != 1)
                {
                    _image->setPixel(topPair.first,(topPair.second-1), QColor(Qt::white).rgb());
                    _blackWhitePixels[(topPair.second-1)][topPair.first] = 1;
                    myStack.push(make_pair(topPair.first, (topPair.second-1)));
                    continue;
                }
             }
            break;
        }
        myStack.pop();
    }     
}



