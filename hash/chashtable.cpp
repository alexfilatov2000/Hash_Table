#include "chashtable.h"
#include "CSecondList.h"
#include <cstdio>
#include <cstring>

CHashTable::CHashTable()
{

}

void CHashTable::Add(string key, string value)
{
    int idx = key[0] - 'A';
    CList<CSecondaryList<string, string> > &firstList = table[idx];

    int keyLen = key.length();

    bool found = false;
    for (int i=0; i<firstList.getSize(); i++)
    {
        if (firstList[i].getSelector() == keyLen) found = true;
    }

    if (!found) firstList.push_back(CSecondaryList<string, string>(keyLen));

    CSecondaryList<string, string>* sl = nullptr;
    for (int i=0; i<firstList.getSize(); i++)
    {
        if (firstList[i].getSelector() == keyLen){
            sl = &firstList[i];
        }
    }

    sl->add(key, value);
}
