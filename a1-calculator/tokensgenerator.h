#ifndef TOKENSGENERATOR_H
#define TOKENSGENERATOR_H

#include "utils.h"
#include <string>
#include "MathTokenAccessory.h"
#include "ErrorHandler.h"

class TokensGenerator:public MathTokenAccessory, public ErrorHandler
{
public:
    TokensGenerator(void);
    ~TokensGenerator(void);

    void SetFunctons(std::vector<std::string> functions) {_functions= functions;}
    void SetOperators(std::map<std::string, std::pair< int,int >> operators) {_operators= operators;}

    std::vector<std::string> SplitString(std::string tokens, std::map<std::string, double> parameters);
    std::vector<std::string> ConvertToTokensArray(std::string tokens);
    std::vector<std::string> ReplaceParameters(std::vector<std::string> tokens, std::map<std::string,double> parameters);
    void replaceSubstring(std::string& str, const std::string& from, const std::string& to);
    std::vector<std::string> Split(const std::string &s, char delim);
    bool ExpressionIsValid(std::vector<std::string> tokens, std::map<std::string,double> parameters);
};

#endif // TOKENSGENERATOR_H
