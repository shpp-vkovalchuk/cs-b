#ifndef SCIENTIFICCALCULATOR_H
#define SCIENTIFICCALCULATOR_H
#include "calculator.h"

class ScientificCalculator: public Calculator
{
public:
    ScientificCalculator();
    ScientificCalculator(std::string inputExpression,std::map<std::string,double> parameters):Calculator()
    {       
      tokens=  SplitExpressionToTokens(inputExpression,parameters);
        AddMathematicalOperation();
    }
         void AddMathematicalOperation();
         void CalculateRPN();
         void CalculateMathematicalExpression();
         void CreateTree();

};

#endif // SCIENTIFICCALCULATOR_H
