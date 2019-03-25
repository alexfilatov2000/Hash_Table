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

    CList<CPair<T1, T2> > search(T1 _key){
        CList<CPair<T1, T2> > list;
        int n = pairList.getSize();
        for (int i=0; i<n; i++){
            CPair<T1, T2>& pair = pairList[i];
            if (pair.key==_key) {
                CPair<T1, T2> rez(_key, pair.value);
                list.push_back(rez);
            }
        }
        return list;
    }
};

#endif // CSECONDLIST_H
