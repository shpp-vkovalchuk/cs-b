#include "calculator.h"
#include <string>
using namespace std;

Calculator::Calculator(void)
{

}


Calculator::~Calculator(void)
{
}

vector<string> Calculator::SplitExpressionToTokens(string inputExpression,std::map<std::string,double> parameters)
{
    return sh.SplitString(inputExpression,parameters);;
}
void Calculator::AddMathematicalOperation()
{

}

void Calculator::CreateTree()
{

}

