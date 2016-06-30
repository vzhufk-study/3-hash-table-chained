#include "additivedictionary.h"

#include <fstream>

AdditiveDictionary::AdditiveDictionary()
{

}



unsigned hash_function(ADWord *A){
    return A->getAmount();
}

bool comp(ADWord A,ADWord B){
    return A.getAmount() > B.getAmount();
}

bool equal(ADWord* A, ADWord* B){
    return (A->getValue().compare(B->getValue()) == 0);
}



bool  AdditiveDictionary::addValue(std::string value, unsigned amount){
   ADWord V(value, amount);
   HTChained::add(&V, hash_function);
   return true;
}

bool  AdditiveDictionary::addValueFromFile(std::string file_name){
    std::ifstream file;
    file.open(file_name);

    std::string word;
    while (file>>word) {
        unsigned amount;
        file>>amount;
        addValue(word, amount);
    }
    return true;
}


bool  AdditiveDictionary::findValue(std::string value, unsigned amount){
    ADWord V(value, amount);
    HTChained::find(&V, hash_function, equal);
    return true;
}

bool  AdditiveDictionary::delValue(std::string, unsigned){

}
