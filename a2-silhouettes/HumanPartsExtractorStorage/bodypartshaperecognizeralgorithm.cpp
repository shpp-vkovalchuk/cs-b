#include "bodypartshaperecognizeralgorithm.h"

BodyPartShapeRecognizerAlgorithm::BodyPartShapeRecognizerAlgorithm()
{
}

BodyPartShapeRecognizerAlgorithm::~BodyPartShapeRecognizerAlgorithm()
{
}

BodyPartShapeRecognizerAlgorithm::BodyPartShapeRecognizerAlgorithm(ExtractedObject *humanBody)
{
    this->_humanBody = humanBody;
}

bool BodyPartShapeRecognizerAlgorithm::ExtractBodyPart(bodyParts part)
{
   return HumanPartsExtractor::ExtractBodyPart(part);
}

bool BodyPartShapeRecognizerAlgorithm::HighlightHead()
{
    int currentColumn=0;
    bool distanceBetweenBlackPixels =false;
    int thisRowPixelsCount = 0;
    int previousRowPixelsCount = 0;
    int rowsFits = 0;
    int headYmaxPoint = _humanBody-> height / 32;
    if(headYmaxPoint < 5)
    {
        return false;
    }
    for (int y = 0; y <= headYmaxPoint; y++)
    {
        for (int x = 0; x < _humanBody->width; x++)
        {
            if(_humanBody->_extractedObjectPixels[y][x] == 1)
            {
                thisRowPixelsCount++;
                if(distanceBetweenBlackPixels && currentColumn==y)
                {
                    return false;
                }
            }
            else if(thisRowPixelsCount!=0 && _humanBody->_extractedObjectPixels[y][x] == 0)
            {
                currentColumn=y;
                distanceBetweenBlackPixels=true;
            }
        }
        if(y!=0 && previousRowPixelsCount < thisRowPixelsCount)
        {
            rowsFits++;
        }
        previousRowPixelsCount = thisRowPixelsCount;
        thisRowPixelsCount=0;
        distanceBetweenBlackPixels=false;
    }
    if((2 * headYmaxPoint / 3) <= rowsFits)
    {
         return true;
    }
    return false;
}

bool BodyPartShapeRecognizerAlgorithm::HighlightCorpus()
{
    int rowsFits = 0;
    double thisRowPixelsCount = 0;
    int corpusYminPoint = _humanBody-> height / 4;
    int corpusYmaxPoint = _humanBody-> height / 2;
    if(corpusYmaxPoint- corpusYminPoint < 5)
    {
        return false;
    }
    double corpusPixelsWidthMidValue= GetCorpusPixelsWidthMidValue(corpusYmaxPoint,corpusYminPoint);
    for (int y = corpusYminPoint; y <= corpusYmaxPoint; y++)
    {
        for (int x = 0; x < _humanBody->width; x++)
        {
            if(_humanBody->_extractedObjectPixels[y][x] == 1)
            {
                thisRowPixelsCount++;
            }
        }
        if(thisRowPixelsCount/corpusPixelsWidthMidValue > 0.95)
        {
            rowsFits++;
        }
        thisRowPixelsCount=0;
    }
    if((2 *(corpusYmaxPoint- corpusYminPoint) / 3) <= rowsFits)
    {
         return true;
    }
    return false;
}

bool BodyPartShapeRecognizerAlgorithm::HighlightLegs()
{
    int distances=0;
    bool leftLegFound = false;
    bool rightLegFound = false;
    int legsYminPoint = 2 *_humanBody-> height / 3;
    int legsYmaxPoint = _humanBody-> height;
    if(legsYmaxPoint- legsYminPoint < 5)
    {
        return false;
    }
    for (int y = legsYminPoint; y < legsYmaxPoint; y++)
    {
        for (int x = 0; x < _humanBody->width; x++)
        {
            if(!leftLegFound && _humanBody->_extractedObjectPixels[y][x] == 1)
            {
                distances++;
                leftLegFound=true;
            }
            else if(leftLegFound && _humanBody->_extractedObjectPixels[y][x] == 0)
            {
                rightLegFound=true;
            }
            else if(rightLegFound && _humanBody->_extractedObjectPixels[y][x] == 1)
            {
                distances++;
                rightLegFound=false;
            }
        }
        if(distances==2)
        {
            return true;
        }
        distances=0;
    }
    return false;
}

double BodyPartShapeRecognizerAlgorithm::GetCorpusPixelsWidthMidValue(int corpusYmaxPoint,int corpusYminPoint)
{
    double midValue = 0;
    for (int y = corpusYminPoint; y <= corpusYmaxPoint; y++)
    {
        for (int x = 0; x < _humanBody->width; x++)
        {
            if(_humanBody->_extractedObjectPixels[y][x] == 1)
            {
                midValue++;
            }
        }
    }

    return midValue/(corpusYmaxPoint-corpusYminPoint);
}
