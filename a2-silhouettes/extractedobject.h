#ifndef EXTRACTEDOBJECT_H
#define EXTRACTEDOBJECT_H


class ExtractedObject
{
public:
    ExtractedObject();
    ~ExtractedObject();
    int** _extractedObjectPixels;
    int height;
    int width;
};

#endif // EXTRACTEDOBJECT_H
