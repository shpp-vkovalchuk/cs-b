#ifndef SCIENTIFICCALCULATOR_H
#define SCIENTIFICCALCULATOR_H
#include "CalculatorSubtypes/calculator.h"

class ScientificCalculator: public Calculator
{
public:
    ScientificCalculator(void);
    ~ScientificCalculator(void);
    ScientificCalculator(std::string inputExpression,std::map<std::string,double> parameters);
    void AddMathematicalOperation();
    std::vector<std::string> CalculateRPN();
    double CalculateMathematicalExpression();
    void CreateTree();

};
#endif // SCIENTIFICCALCULATOR_H
