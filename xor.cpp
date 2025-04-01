#include "cpp.h"
#include <iostream>
using namespace std;
#include <vector>

string xorEncrypt(string msg, int pass)
{
    string enc;
    for (char ch : msg)
    { //^ this return 0 if both the binary are 0 and 1 if not;
        // A ^ Key = Encrypted
        // Encrypted ^ Key = A
        ch = ch ^ pass;
        cout << "\033[3;34m" << ch << "\033[0m \n";
        enc.push_back(ch);
    }
    cout << "XOR Encryption successful \n";
    return enc;
}

string xorDecrypt(vector<char> encDec, int pass)
{
    cout << "\033[0;33m Beginning the XOR-decryption \033[0m" << endl;
    string dec;
    for (char ch : encDec)
    { //^ this return 0 if both the binary are 0 and 1 if not;
        cout << "\033[3;34m" << ch << "\033[0m \n";
        ch = ch ^ pass;
        dec.push_back(ch);
    }
    cout << "\033[0;33mXOR Decryption successful\033[0m";
    return dec;
}