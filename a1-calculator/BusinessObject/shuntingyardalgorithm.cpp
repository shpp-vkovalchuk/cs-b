#include "shuntingyardalgorithm.h"
#include <string>
#include <sstream>

using namespace std;


ShuntingYardAlgorithm::ShuntingYardAlgorithm(void)
{
}


ShuntingYardAlgorithm::~ShuntingYardAlgorithm(void)
{
}


vector<string> ShuntingYardAlgorithm::InfixToRevercePolishNotation(std::vector<string> inputTokens)
{
    vector<string> outputRPN;
    stack<string> operatorStack;
    for ( int i = 0; i < (int) inputTokens.size(); ++i )
    {
         string token=inputTokens.at(i);

        if(IsTokenDigit(token))
        {
            outputRPN.push_back(token);
        }
        else if (IsTokenFunction(token))
        {
            operatorStack.push(token);
        }
        else if (IsTokenOperator(token))
        {
            while (operatorStack.size()!= 0)
            {
                if (IsTokenFunction(operatorStack.top()))
                {
                    outputRPN.push_back(operatorStack.top());
                    operatorStack.pop();
                    continue;
                }

                if (IsTokenOperator(operatorStack.top()) && IsTokenLeftAssociative(token) && ComaprePrecedence(token, operatorStack.top()) >= 0 ||
                    IsTokenOperator(operatorStack.top()) && !IsTokenLeftAssociative(token) && ComaprePrecedence(token, operatorStack.top()) > 0)
                {
                    outputRPN.push_back(operatorStack.top());
                    operatorStack.pop();
                    continue;
                }
                break;
            }
            operatorStack.push(token);
        }
        else if (token.compare("(")==0)
        {
            operatorStack.push(token);
        }
        else if (token.compare(")")==0)
        {
            while (operatorStack.size() != 0 && operatorStack.top().compare("(")!=0)
            {
                outputRPN.push_back(operatorStack.top());
                operatorStack.pop();
            }
            if(operatorStack.size()==0)
            {
                HandleError("Too many tokens ')' occuerance. Mismatched parentheses !!!");
            }
            operatorStack.pop();
        }
        else if (token.compare(",")==0)
        {
            while (operatorStack.size() != 0 && operatorStack.top().compare("(")!=0)
            {
                outputRPN.push_back(operatorStack.top());
                operatorStack.pop();
            }
            if(operatorStack.size()==0)
            {
                HandleError("Too many tokens '(' occuerance. Mismatched parentheses !!!");
            }
        }
    }

    while (operatorStack.size() != 0)
    {
        outputRPN.push_back(operatorStack.top());
        if(operatorStack.top().compare("(")==0 ||operatorStack.top().compare(")")==0)
        {
            HandleError("Mismatched parentheses !!!");
        }
        operatorStack.pop();
    }

    return outputRPN;
}


int ShuntingYardAlgorithm::ComaprePrecedence(string token, string operatorFromStack)
{
      const std::pair<int,int> currentToken = _operators.find(token)->second;
      const std::pair<int,int> topStackToken = _operators.find(operatorFromStack)->second;
      if(currentToken.first > topStackToken.first)
      {
        return -1;
      }
      else if(currentToken.first == topStackToken.first)
      {
        return 0;
      }
      return 1;
}



