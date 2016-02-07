#include "tokensgenerator.h"
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

TokensGenerator::TokensGenerator(void)
{

}

TokensGenerator::~TokensGenerator(void)
{
}

vector<string> TokensGenerator::SplitString(string tokens, std::map<string,double > parameters)
{
      replaceSubstring(tokens," ","");

        for (std::map<string,std::pair< int,int >>::iterator iter = _operators.begin(); iter != _operators.end(); ++iter)
        {
            string keyOperator =  iter->first;
            replaceSubstring(tokens,keyOperator, " " + keyOperator + " ");
        }
        for ( int i = 0; i < (int) _functions.size(); ++i )
        {
             replaceSubstring(tokens,_functions.at(i), _functions.at(i) + " ");
        }
         replaceSubstring(tokens,")", " ) ");
         replaceSubstring(tokens,"(", " ( ");
         replaceSubstring(tokens, ",", " , ");
         replaceSubstring(tokens,".", ",");

        vector<string> tokensArray = ConvertToTokensArray(tokens);
        tokensArray = ReplaceParameters(tokensArray, parameters);
        if(!ExpressionIsValid(tokensArray, parameters))
        {
            HandleError("Unknown qualifier in mathematical expreession!!!");
        }
        return tokensArray;
}

bool TokensGenerator::ExpressionIsValid(std::vector<std::string> tokens, std::map<std::string,double> parameters)
{
    for(int i=0; i<tokens.size(); i++)
    {
        if(!IsTokenDigit(tokens[i]) && !IsTokenFunction(tokens[i]) && !IsTokenOperator(tokens[i]) && !IsTokenParameter(tokens[i],parameters) &&
            tokens[i]!="(" && tokens[i]!=")" && tokens[i]!=",")
        {
            return false;
        }
    }
    return true;
}

vector<string> TokensGenerator::ReplaceParameters(std::vector<string> tokens, std::map<string,double > parameters)
{
    for (int i = 0; i < tokens.size();i++ )
    {
        for (std::map<string,double>::iterator iter = parameters.begin(); iter != parameters.end(); ++iter)
        {
            string keyOperator =  iter->first;
            if (tokens[i].compare(keyOperator)==0)
            {
                tokens[i] =  std::to_string(static_cast<long long>(iter->second));
            }
            else if (tokens[i].compare("-" + keyOperator)==0)
            {
                tokens[i] = "-" + std::to_string(static_cast<long long>(iter->second));
            }
        }
    }
    return tokens;

}


vector<string> TokensGenerator::ConvertToTokensArray(string tokens)
{
    vector<string> tokensVector=Split(tokens,' ');
     for ( int i = 0; i < (int) tokensVector.size(); ++i )
      {
          if(tokensVector.at(i).compare("") == 0)
          {
              tokensVector.erase(tokensVector.begin() + i);
          }
      }

      for ( int i = 0; i < (int) tokensVector.size(); ++i )
      {
          if (tokensVector.at(i).compare("-")==0 && i != 0)
          {
              if (IsTokenOperator(tokensVector.at(i - 1)))
              {
                  tokensVector.at(i + 1) = "-" + tokensVector.at(i - 1);
                  tokensVector.at(i) = "";
              }
             else if (tokensVector.at(i - 1).compare("(")==0)
              {
                  tokensVector.at(i + 1) = "-" + tokensVector.at(i + 1);
                  tokensVector.at(i) = "";
              }
          }
          else if (tokensVector.at(i).compare("-") == 0 && i == 0)
          {
              tokensVector.at(i + 1) = "-" + tokensVector.at(i + 1);
              tokensVector.at(i) = "";
          }
      }

      for ( int i = 0; i < (int) tokensVector.size(); ++i )
      {
          if(tokensVector.at(i).compare("") == 0)
          {
              tokensVector.erase(tokensVector.begin() + i);
          }
      }

      return tokensVector;
}

void TokensGenerator::replaceSubstring(string &str, const string &from, const string &to)
{
       size_t start_pos = 0;
       while((start_pos = str.find(from, start_pos)) != std::string::npos) {
           str.replace(start_pos, from.length(), to);
           start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
       }

}

vector<string>TokensGenerator::Split(const string &s, char delim)
{
        vector<std::string> elems;
        stringstream ss(s);
        string item;
        while (std::getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
}
