#include "cpp.h"
#include <iostream>
using namespace std;
#include <vector>
vector<int>toBinary(string msg)
{
    vector<int>Store ;
    for (char ch : msg)            //conversion of the character to binary 
    {
       int ascii = (int)ch; // Typecasting shitt basically
       Store.push_back(ascii) ;
    }
    return Store ;
}