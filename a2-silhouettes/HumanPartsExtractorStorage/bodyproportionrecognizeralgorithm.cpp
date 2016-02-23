#include "bodyproportionrecognizeralgorithm.h"

BodyProportionRecognizerAlgorithm::BodyProportionRecognizerAlgorithm()
{
}

BodyProportionRecognizerAlgorithm::~BodyProportionRecognizerAlgorithm()
{
}
BodyProportionRecognizerAlgorithm::BodyProportionRecognizerAlgorithm(ExtractedObject *humanBody)
{
    this->_humanBody = humanBody;
}

bool BodyProportionRecognizerAlgorithm::HighlightHead()
{
    int headPixelsCount=0;
    int headYmaxPoint = _humanBody-> height / 8;
    if(headYmaxPoint < 5)
    {
        return false;
    }
    for (int y = 0; y < headYmaxPoint; y++)
    {
        for (int x = 0; x < _humanBody->width; x++)
        {
            if(_humanBody->_extractedObjectPixels[y][x] == 1)
            {
                headPixelsCount++;
            }
        }
    }
    double headToTotalCorrelation=headPixelsCount * 100/BlackPixelsCount();
    if(headToTotalCorrelation<15 && headToTotalCorrelation > 7)
    {
        return true;
    }
    return false;

}

bool BodyProportionRecognizerAlgorithm::HighlightCorpus()
{
    int corpusPixelsCount=0;
    int corpusYminPoint = _humanBody-> height / 8;
    int corpusYmaxPoint = _humanBody-> height / 2;
    if(corpusYmaxPoint- corpusYminPoint < 5)
    {
        return false;
    }
    for (int y = corpusYminPoint; y < corpusYmaxPoint; y++)
    {
        for (int x = 0; x < _humanBody->width; x++)
        {
            if(_humanBody->_extractedObjectPixels[y][x] == 1)
            {
                corpusPixelsCount++;
            }
        }
    }
    double corpusToTotalCorrelation=corpusPixelsCount * 100/BlackPixelsCount();
    if(corpusToTotalCorrelation<60 && corpusToTotalCorrelation > 40)
    {
        return true;
    }
    return false;
}

bool BodyProportionRecognizerAlgorithm::HighlightLegs()
{   
    int legsPixelsCount=0;
    int legsYminPoint = _humanBody-> height / 2;
    int legsYmaxPoint = _humanBody-> height;
    if(legsYmaxPoint- legsYminPoint < 5)
    {
        return false;
    }
    for (int y = legsYminPoint; y < legsYmaxPoint; y++)
    {
        for (int x = 0; x < _humanBody->width; x++)
        {
            if(_humanBody->_extractedObjectPixels[y][x]==1)
            {
                legsPixelsCount++;                
            }
        }
    }  
    double legsToTotalCorrelation=legsPixelsCount * 100/BlackPixelsCount();
    if(legsToTotalCorrelation < 50 && legsToTotalCorrelation > 25)
    {
        return true;
    }
    return false;
}

double BodyProportionRecognizerAlgorithm::BlackPixelsCount()
{
    double totalBlackPixelsCount = 0;
    for (int y = 0; y <_humanBody->height; y++)
    {
        for (int x = 0; x < _humanBody->width; x++)
        {
            if(_humanBody->_extractedObjectPixels[y][x]==1)
            {
                totalBlackPixelsCount++;
            }
        }
    }
    return totalBlackPixelsCount;
}

bool BodyProportionRecognizerAlgorithm::ExtractBodyPart(bodyParts part)
{
   return HumanPartsExtractor::ExtractBodyPart(part);
}
