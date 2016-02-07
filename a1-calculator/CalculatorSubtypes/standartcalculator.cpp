#include "standartcalculator.h"

StandartCalculator::StandartCalculator()
{

}
StandartCalculator::~StandartCalculator(void)
{
}

StandartCalculator::StandartCalculator(std::string inputExpression,std::map<std::string,double> parameters) : Calculator()
{
    AddMathematicalOperation();
    tokens = SplitExpressionToTokens(inputExpression,parameters);
}


void StandartCalculator::AddMathematicalOperation()
{

    tokenGenerator.SetOperators(assocs);
    sh.SetOperators(assocs);

    tree.SetOperators(assocs);


}

double StandartCalculator::CalculateMathematicalExpression()
{
    return tree.GetExpressionResult();
}

std::vector<std::string> StandartCalculator::CalculateRPN()
{

  tokens = sh.InfixToRevercePolishNotation(tokens);
  return tokens;
}

void StandartCalculator::CreateTree()
{
    tree.Create(tokens);
}
