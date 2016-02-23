#ifndef HUMANPARTSEXTRACTOR_H
#define HUMANPARTSEXTRACTOR_H
#include "extractedobject.h"

class HumanPartsExtractor
{
public:
    HumanPartsExtractor();
    ~HumanPartsExtractor();
     enum bodyParts {Head, Corpus, Legs};
    bool ExtractBodyPart(bodyParts part);
protected:
    ExtractedObject* _humanBody;
    virtual bool HighlightHead() = 0;
    virtual bool HighlightCorpus() = 0;
    virtual bool HighlightLegs() = 0;
};

#endif // HUMANPARTSEXTRACTOR_H
