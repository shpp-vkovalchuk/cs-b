#include "extractedobject.h"

ExtractedObject::ExtractedObject()
{

}

ExtractedObject::~ExtractedObject()
{
    for(int i=0; i < height; i++)
    {
        delete _extractedObjectPixels[i];
    }
    delete[]_extractedObjectPixels;
}

