#include "cpp.h"
#include <iostream>
#include <vector>
using namespace std;

vector<int> toBinary(string msg)
{
    vector<int> Store;
 
    for (char ch : msg)    
     {
        vector<int> binary(8, 0);
        for (int i = 7; i >= 0; i--)
        {
            binary[i] = ch % 2;
            ch /= 2;
        }

        Store.insert(Store.end(), binary.begin(), binary.end());

        cout << ch << " -> ";
        for (int bit : binary)
            cout << bit;
        cout << endl;
    }

    return Store;
}