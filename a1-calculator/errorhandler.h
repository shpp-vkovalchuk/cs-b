#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H

#include <string>
class ErrorHandler
{
public:
    ErrorHandler(void);
    ~ErrorHandler(void);

    protected:
        void HandleError(std::string errorMessage);
};

#endif // ERRORHANDLER_H
