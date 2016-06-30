#ifndef HTCHAINED_H
#define HTCHAINED_H

#include <deque>
#include <list>
#include <array>

template <class valueType>
class HTChained
{
    std::array<std::list<valueType>, 1> *value;
    unsigned amount;
public:
    HTChained(){
        amount = 0;
    }

    HTChained(unsigned n){
        amount = n;
        value = new std::array<std::list<valueType>, this->amount>;
    }

    bool add(valueType *element, unsigned (*hash_function)(valueType*)){
        unsigned index = hash_function(element);
        index %= amount;
        value->operator [](index).push_front(*element);
        return true;
    }

    valueType *find(valueType *X,  unsigned (*hash_function)(valueType*), bool (*comp)(valueType*, valueType*)){
        unsigned index = hash_function(X);
        index %= amount;
        std::list<valueType> temp = value->operator [](index);
        for (typename std::list<valueType>::iterator it=temp.begin(); it != temp.end(); ++it){
            valueType *tmp = &*it;
               if (comp(tmp, X)){
                   return tmp;
               }
        }
        return NULL;
    }

    bool del(valueType *X,  unsigned (*hash_function)(valueType*), bool (*comp)(valueType*, valueType*)){
        unsigned index = hash_function(X);
        index %= amount;
        std::list<valueType> temp = value[index];
        unsigned i = 0;
        while(!temp.empty()){
            if (comp(X, &temp.front())){
                value[index].erase(value[index].begin() + i);
                return true;
            }
            temp.pop_front();
            ++i;
        }
        return false;
    }
};

#endif // HTCHAINED_H
