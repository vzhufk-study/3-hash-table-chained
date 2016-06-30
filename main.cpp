///24.06.2016 10:59
#include <iostream>

#include <fstream>

#include <additivedictionary.h>
using namespace std;

int main(int argc, char *argv[])
{
    AdditiveDictionary S;
    S.addValueFromFile("50.txt");
    S.findValue("Hey", 1);
    return 0;
}
