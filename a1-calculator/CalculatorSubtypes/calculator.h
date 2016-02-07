#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <string>
#include <map>
#include "BusinessObject/shuntingyardalgorithm.h"
#include "BusinessObject/binarytreealgorithm.h"
#include "TokensGenerator.h"
#include "Utils.h"

class Calculator: public TokensGenerator
{
public:
    Calculator(void);
    ~Calculator(void);
    std::vector<std::string> tokens;
    ShuntingYardAlgorithm sh;
    TokensGenerator tokenGenerator;
    virtual void AddMathematicalOperation() = 0;
    virtual std::vector<std::string> CalculateRPN() = 0;
    virtual double CalculateMathematicalExpression() = 0;
    virtual void CreateTree() = 0;
protected:
    std::vector<std::string> SplitExpressionToTokens(std::string inputExpression, std::map<std::string, double> parameters);
    BinaryTreeAlgorithm tree;
};

#endif // CALCULATOR_H
