#ifndef CHASHTABLE_H
#define CHASHTABLE_H
#include "List.hpp"
#include "CSecondList.h"
#include <string>

using namespace std;

class CHashTable
{
    CList<CSecondaryList<string, string> > table[26];
public:
    CHashTable();
    void Add(string key, string value);
};

#endif // CHASHTABLE_H
