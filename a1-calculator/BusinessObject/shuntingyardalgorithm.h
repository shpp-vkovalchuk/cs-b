#ifndef SHUNTINGYARDALGORITHM_H
#define SHUNTINGYARDALGORITHM_H

#include <map>
#include <string>
#include "mathtokenaccessory.h"
#include "errorhandler.h"

class ShuntingYardAlgorithm :public MathTokenAccessory, public ErrorHandler
{
public:
    ShuntingYardAlgorithm(void);
    ~ShuntingYardAlgorithm(void);


    void SetFunctons(std::vector<std::string> functions) {_functions= functions;}
    void SetOperators(std::map<std::string, std::pair< int,int >> operators) {_operators= operators;}
    std::vector<std::string> InfixToRevercePolishNotation(std::vector<std::string> inputTokens);

private:
    int ComaprePrecedence(std::string token, std::string operatorFromStack);
};

#endif // SHUNTINGYARDALGORITHM_H
