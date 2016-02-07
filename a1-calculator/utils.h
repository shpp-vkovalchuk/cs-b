#ifndef UTILS_H
#define UTILS_H
#include <map>
#include <string>
#include <vector>

class Utils
{
public:
    Utils(void);
    ~Utils(void);

     int LEFT_ASSOC;
     int RIGHT_ASSOC;
     std::map< std::string, std::pair< int,int > > assocs;
     std::vector<std::string> funcs;

};

#endif // UTILS_H
