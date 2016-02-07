#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <string>
#include <map>
#include <utils.h>
#include <BusinessObject/shuntingyardalgorithm.h>
class Calculator : public Utils
{
public:
    Calculator();   
    std::vector<std::string> tokens;
    ShuntingYardAlgorithm sh;
    virtual void AddMathematicalOperation() = 0;
    virtual void CalculateRPN() = 0;
    virtual void CalculateMathematicalExpression() = 0;
    virtual void CreateTree() = 0;
protected:
    std::vector<std::string> SplitExpressionToTokens(std::string inputExpression, std::map<std::string,double> parameters);
};

#endif // CALCULATOR_H
