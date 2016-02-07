#include "scientificcalculator.h"
#include "calculator.h"


ScientificCalculator::ScientificCalculator(void)
{

}


ScientificCalculator::~ScientificCalculator(void)
{
}

ScientificCalculator::ScientificCalculator(std::string inputExpression,std::map<std::string,double> parameters):Calculator()
{
        AddMathematicalOperation();
        tokens = SplitExpressionToTokens(inputExpression,parameters);
}


void ScientificCalculator::AddMathematicalOperation()
{
    sh.SetOperators(assocs);
        sh.SetFunctons(funcs);
        tree.SetOperators(assocs);
        tree.SetFunctons(funcs);
}
double ScientificCalculator::CalculateMathematicalExpression()
{

        tree.SetOperators(assocs);
        return tree.GetExpressionResult();
}
std::vector<std::string> ScientificCalculator::CalculateRPN()
{

  tokens = sh.InfixToRevercePolishNotation(tokens);
  return tokens;
}
void ScientificCalculator::CreateTree()
{
        tree.Create(tokens);
}

