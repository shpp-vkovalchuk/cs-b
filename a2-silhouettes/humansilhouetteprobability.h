#ifndef HUMANSILHOUETTEPROBABILITY_H
#define HUMANSILHOUETTEPROBABILITY_H
#include <qimage.h>
#include "recursiveiterationalgorithm.h"
#include "HumanPartsExtractorStorage/humanpartsextractor.h"
#include"HumanPartsExtractorStorage/bodypartshaperecognizeralgorithm.h"
#include "HumanPartsExtractorStorage/bodyproportionrecognizeralgorithm.h"

class HumanSilhouetteProbability
{
public:
    HumanSilhouetteProbability();
    ~HumanSilhouetteProbability();
    HumanSilhouetteProbability(QImage * image);
    double sum;
    void SetObjectCoordinate(int x,int y);
    void CalculateHumanHeadProbability();
    void CalculateHumanCorpusProbability();
    void CalculateHumanLegsProbability();
    double GetResult();
private:
    RecursiveIterationAlgorithm * recursion;
    ExtractedObject* body;
    BodyPartShapeRecognizerAlgorithm* shapeRecogn;
    BodyProportionRecognizerAlgorithm* proportionRecogn;
};

#endif // HUMANSILHOUETTEPROBABILITY_H
