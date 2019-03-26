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

CList<CPair<string, string> > CHashTable::getByKey(string key)
{
    int idx = key[0] - 'A';
    CList<CSecondaryList<string, string> > &firstList = table[idx];

    int keyLen = key.length();

    bool found = false;
    for (int i=0; i<firstList.getSize(); i++)
    {
        if (firstList[i].getSelector() == keyLen) found = true;
    }

    if (found){
        CSecondaryList<string, string>* sl = nullptr;
        for (int i=0; i<firstList.getSize(); i++)
        {
            if (firstList[i].getSelector() == keyLen){
                sl = &firstList[i];
            }
        }

        return sl->search(key);
    }


    CList<CPair<string, string> > list;
    return list;
}

void CHashTable::LoadFromFile(char *fileName)
{
    FILE* f = fopen(fileName, "rt");
    if (!f) {
        cout << "File not found" << endl;
        return;
    }

    char s[20000]={0};
    char key[1000]={0};
    char _key[1000]={0};
    int cnt = 0;
    while(fgets(s, sizeof(s), f)){
        int j=0;
        while (s[j]!=';') {key[j] = s[j]; j++; if (j>500) break;}
        key[j] = 0;
        strcpy(_key, key);

        //удаляем ведущие небуквы из ключа
        int key_len = strlen(key);
        while(key_len>0 && !isalpha(key[0])) {
            for(int i=0; i<key_len; i++) key[i]=key[i+1];
            key_len--;
        }

        //если от ключа еще что нибудь осталось
        if (key_len!=0)
        {
            int pos=strchr(s,';')-s;
            Add(key, s+pos);
            cnt++;
            //if (cnt%100==0) cout << cnt << endl;
            //cout << cnt << " " << key << endl;
        }else{
            cout << cnt << " key-error: \"" << _key << "\"" << endl;
        }
    }
    fclose(f);
}


