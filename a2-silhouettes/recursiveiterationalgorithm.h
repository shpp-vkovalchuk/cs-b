#ifndef RECURSIVEITERATIONALGORITHM_H
#define RECURSIVEITERATIONALGORITHM_H

#include <QImage>
#include <QColor>
#include <stack>

#include "extractedobject.h"

class RecursiveIterationAlgorithm
{
public:
    RecursiveIterationAlgorithm();
    ~RecursiveIterationAlgorithm();
    RecursiveIterationAlgorithm(QImage *image);
    ExtractedObject *GetExtractedObjectArray(int startPointX,int startPointY);
    void IterativeRecursion(int startPointX, int startPointY);

private:
    QImage *_image;
    int** _blackWhitePixels;
    ExtractedObject* ExtractObjectArray();
    int** CopyArray(int minXWidth, int maxXWidth, int minYHeight, int maxYHeight);
    void GetExtractedObjectSize(int& minXWidth, int& maxXWidth, int& minYHeight, int& maxYHeight);
};

#endif // RECURSIVEITERATIONALGORITHM_H
