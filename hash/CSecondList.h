#ifndef CSECONDLIST_H
#define CSECONDLIST_H
#include "List.hpp"
#include "CPair.h"

template <class T1, class T2>
class CSecondaryList{
    int selector;
    CList<CPair<T1, T2> > pairList;

public:
    CSecondaryList(){}
    CSecondaryList(int _selector){
        selector = _selector;
    }

    int getSelector() {return selector;}

    void add(T1 key, T2 value){
        CPair<T1, T2> pair(key, value);
        pairList.push_front(pair);
    }
};

#endif // CSECONDLIST_H
