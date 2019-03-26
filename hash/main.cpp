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


    return 0;
}

