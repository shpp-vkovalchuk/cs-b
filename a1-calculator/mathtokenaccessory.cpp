#include "mathtokenaccessory.h"

#include <string>

#include <sstream>

using namespace std;

MathTokenAccessory::MathTokenAccessory(void)
{
}


MathTokenAccessory::~MathTokenAccessory(void)
{
}

bool MathTokenAccessory::IsTokenLeftAssociative(string token)
{

     const std::pair<int,int> p = _operators.find(token)->second;
     return p.second == LEFT_ASSOC;
}

bool MathTokenAccessory::IsTokenOperator(string token)
{
     for(std::map<string,std::pair< int,int >>::iterator iter = _operators.begin(); iter != _operators.end(); ++iter)
        {
         string key =  iter->first;
            if (key.compare(token) == 0)
            {
                return true;
            }
        }
    return false;

}

bool MathTokenAccessory::IsTokenFunction(string token)
{
    for ( int i = 0; i < (int) _functions.size(); ++i )
        {
         string function=_functions.at(i);
            if (function.compare(token) == 0)
            {
                return true;
            }
        }
        return false;

}

bool MathTokenAccessory::IsTokenDigit(string token)
{
   std::istringstream i(token);
   double x;
   if (!(i >> x))
     return false;
    return true;
}

bool MathTokenAccessory::IsTokenParameter(std::string token,std::map<std::string,double> parameters)
{
    for (std::map<string,double>::iterator iter = parameters.begin(); iter != parameters.end(); ++iter)
    {
        string keyOperator =  iter->first;
        if (token.compare(keyOperator)==0)
        {
            return true;
        }
    }
    return false;
}
