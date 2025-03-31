#include "cpp.h"
#include <iostream>
#include <vector>
using namespace std;

vector<int> toBinary(string msg)
{
    vector<int> Store;
    cout << endl ;
    for (char ch : msg)    
     {
        vector<int> binary(8);
        for (int i = 7; i >= 0; i--)
        {
            binary[i] = ch % 2; //% of ascii of ch;
            ch /= 2;
        }

        Store.insert(Store.end(), binary.begin(), binary.end());

        cout <<"\033[3;34m"<< ch << " -> ";
        for (int bit : binary)
            cout << bit;
        cout << endl;
    }
cout <<"\033[0m";
    return Store;
}