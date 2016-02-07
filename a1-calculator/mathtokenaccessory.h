#ifndef MATHTOKENACCESSORY_H
#define MATHTOKENACCESSORY_H
#include <map>
#include <queue>
#include <stack>
#include <string>
#include "Utils.h"

class MathTokenAccessory: public Utils
{
public:
    MathTokenAccessory(void);
    ~MathTokenAccessory(void);

protected:
     std::map< std::string, std::pair< int,int > > _operators;
    std::vector<std::string> _functions;
     bool IsTokenDigit(std::string);
    bool IsTokenFunction(std::string);
    bool IsTokenOperator(std::string token);
    bool IsTokenLeftAssociative(std::string token);
    bool IsTokenParameter(std::string token,std::map<std::string,double> parameters);
};

#endif // MATHTOKENACCESSORY_H
