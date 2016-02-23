#ifndef BODYPROPORTIONRECOGNIZERALGORITHM_H
#define BODYPROPORTIONRECOGNIZERALGORITHM_H
#include "humanpartsextractor.h"
#include <QImage>
#include <QColor>
class BodyProportionRecognizerAlgorithm: public HumanPartsExtractor
{
public:
    BodyProportionRecognizerAlgorithm();
    ~BodyProportionRecognizerAlgorithm();
    BodyProportionRecognizerAlgorithm(ExtractedObject* humanBody);

    bool ExtractBodyPart(bodyParts part);

    bool HighlightHead();
    bool HighlightCorpus();
    bool HighlightLegs();

private:
    double BlackPixelsCount();
};

#endif // BODYPROPORTIONRECOGNIZERALGORITHM_H
