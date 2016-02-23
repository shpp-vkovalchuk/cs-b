#include "humanpartsextractor.h"

HumanPartsExtractor::HumanPartsExtractor()
{
}

HumanPartsExtractor::~HumanPartsExtractor()
{
}

bool HumanPartsExtractor::ExtractBodyPart(bodyParts part)
{
    switch (part) {
    case Head:
      return HighlightHead();
    case Corpus:
       return HighlightCorpus();
    case Legs:
        return HighlightLegs();
    default:
        return false;
    }
}

