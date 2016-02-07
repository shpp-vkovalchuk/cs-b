#include "utils.h"

Utils::Utils(void)
{
  int LEFT_ASSOC = 0;
  int RIGHT_ASSOC = 1;
  assocs.insert(std::make_pair("+", std::make_pair( 0, LEFT_ASSOC )));
  assocs.insert(std::make_pair("-", std::make_pair<int,int>( 0, LEFT_ASSOC )));
  assocs.insert(std::make_pair("*", std::make_pair<int,int>( 5, LEFT_ASSOC )));
  assocs.insert(std::make_pair("/", std::make_pair<int,int>( 5, LEFT_ASSOC )));
  assocs.insert(std::make_pair("^", std::make_pair<int,int>( 6, RIGHT_ASSOC )));

  funcs.push_back("sqrt");
  funcs.push_back("cos");
  funcs.push_back("sin");
  funcs.push_back("max");
  funcs.push_back("tan");
}

Utils::~Utils(void)
{
}
