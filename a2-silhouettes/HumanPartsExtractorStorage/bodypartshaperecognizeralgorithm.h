#ifndef BODYPARTSHAPERECOGNIZERALGORITHM_H
#define BODYPARTSHAPERECOGNIZERALGORITHM_H
#include"humanpartsextractor.h"

class BodyPartShapeRecognizerAlgorithm: public HumanPartsExtractor
{
public:
    BodyPartShapeRecognizerAlgorithm();
    ~BodyPartShapeRecognizerAlgorithm();
    BodyPartShapeRecognizerAlgorithm(ExtractedObject* humanBody);

     bool ExtractBodyPart(bodyParts part);

     bool HighlightHead();
     bool HighlightCorpus();
     bool HighlightLegs();

private:
     double GetCorpusPixelsWidthMidValue(int corpusYmaxPoint,int corpusYminPoint);
};

#endif // BODYPARTSHAPERECOGNIZERALGORITHM_H
