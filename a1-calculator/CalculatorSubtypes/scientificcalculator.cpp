#include "scientificcalculator.h"

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
    tokenGenerator.SetFunctons(funcs);
    tokenGenerator.SetOperators(assocs);
    sh.SetOperators(assocs);
    sh.SetFunctons(funcs);
    tree.SetOperators(assocs);
    tree.SetFunctons(funcs);
}
double ScientificCalculator::CalculateMathematicalExpression()
{
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
