#include "errorhandler.h"
#include <iostream>

ErrorHandler::ErrorHandler(void)
{

}
ErrorHandler::~ErrorHandler(void)
{
}

void ErrorHandler::HandleError(std::string errorMessage)
{
    std::cerr << errorMessage<<std::endl;
    system("pause");
    exit(EXIT_FAILURE);
}
