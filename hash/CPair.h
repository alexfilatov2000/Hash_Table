#ifndef CPAIR_H
#define CPAIR_H

template <class T1, class T2>
struct CPair{
    T1 key;
    T2 value;
    CPair(){}
    CPair(T1 _key, T2 _value){
        key = _key;
        value = _value;
    }
};

#endif // CPAIR_H
