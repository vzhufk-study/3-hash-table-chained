#ifndef ADDITIVEDICTIONARY_H
#define ADDITIVEDICTIONARY_H

#include <htchained.h>

#include <string>
#include <adword.h>


class AdditiveDictionary: public HTChained<ADWord>
{
public:
    AdditiveDictionary();
    bool addValue(std::string, unsigned);
    bool findValue(std::string, unsigned);
    bool delValue(std::string, unsigned);

    bool addValueFromFile(std::string);
};

#endif // ADDITIVEDICTIONARY_H
