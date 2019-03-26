#include <iostream>
#include "chashtable.h"
#include "List.hpp"
#include "CPair.h"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    CHashTable hTable;

    hTable.Add("CAT", "Small night predator");
    hTable.Add("LION", "Big african predator");
    hTable.Add("TIGER", "Big asian forest predator");
    hTable.Add("CAT", "My favorite animal");


    cout << "Loading...  Please wait..." << endl;
    hTable.LoadFromFile("dict_processed.txt");
    cout << "Loading ok" << endl;

    while(true)
    {
        char key[100];
        cout << "key = "; cin.getline(key, sizeof(key));

        CList<CPair<string, string> > rez_list= hTable.getByKey(key);

        for (int i=0; i<rez_list.getSize(); i++){
            CPair<string, string> pair = rez_list[i];
            cout << pair.key << ": " << pair.value << endl;
        }
    }
    return 0;
}

