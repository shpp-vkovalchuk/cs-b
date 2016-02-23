#include "humansilhouetteprobability.h"

HumanSilhouetteProbability::HumanSilhouetteProbability()
{

}

HumanSilhouetteProbability::~HumanSilhouetteProbability()
{
    delete body;
    delete shapeRecogn;
    delete proportionRecogn;
    delete recursion;
}

HumanSilhouetteProbability::HumanSilhouetteProbability(QImage* image)
{
     recursion = new RecursiveIterationAlgorithm(image);
}

void HumanSilhouetteProbability::SetObjectCoordinate(int x, int y)
{
    sum = 0;
    body = recursion->GetExtractedObjectArray(x,y);
    shapeRecogn=new BodyPartShapeRecognizerAlgorithm(body);
    proportionRecogn=new BodyProportionRecognizerAlgorithm(body);
}

void HumanSilhouetteProbability::CalculateHumanHeadProbability()
{
    bool headShape=  shapeRecogn->ExtractBodyPart(shapeRecogn->Head);
    if(headShape)
    {
       sum+=16.5;
       bool headProportion=proportionRecogn->ExtractBodyPart(proportionRecogn->Head);
       if(headProportion)
       {
           sum+=16.5;
       }
    }
}

void HumanSilhouetteProbability::CalculateHumanCorpusProbability()
{  
    bool corpusShape=  shapeRecogn->ExtractBodyPart(shapeRecogn->Corpus);
    if(corpusShape)
    {
       sum+=16.5;
    }
    bool corpusProportion=proportionRecogn->ExtractBodyPart(proportionRecogn->Corpus);
    if(corpusProportion)
    {
        sum+=16.5;
    }
}

void HumanSilhouetteProbability::CalculateHumanLegsProbability()
{
    bool legsShape=  shapeRecogn->ExtractBodyPart(shapeRecogn->Legs);
    if(legsShape)
    {
       sum+=16.5;
    }
    bool legsProportion=proportionRecogn->ExtractBodyPart(proportionRecogn->Legs);
    if(legsProportion)
    {
        sum+=16.5;
    }
}

double HumanSilhouetteProbability::GetResult()
{
    return sum;
}

