#ifndef STANDARTCALCULATOR_H
#define STANDARTCALCULATOR_H
#include "calculator.h"

class StandartCalculator:public Calculator
{
public:
    StandartCalculator(void);
    ~StandartCalculator(void);

    StandartCalculator(std::string inputExpression,std::map<std::string,double> parameters);

    void AddMathematicalOperation();
    std::vector<std::string> CalculateRPN();
    double CalculateMathematicalExpression();
    void CreateTree();
};

#endif // STANDARTCALCULATOR_H
