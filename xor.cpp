#include "cpp.h"
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
string xorEncrypt(string msg, int pass)
{   cout <<endl ;
    string enc;
    for (unsigned char ch : msg)
    {   //^ this return 0 if both the binary are 0 and 1 if not;
        // A ^ Key = Encrypted
        // Encrypted ^ Key = A
        
        ch = ch ^ pass;
        if (!isprint(ch))
        {
            // If it's non-printable,  // Wrap it into the printable range (32-126)
            ch = (ch % 95) + 32;         
        }
        cout << "\033[3;34m" << ch << "\033[0m \n";
        enc.push_back(ch);
    }
    cout << "\033[0;33m XOR Encryption successful \033[0m \n";
    return enc;
}

string xorDecrypt(vector<char> encDec, int pass)
{
    cout << "\033[0;33m Beginning the XOR-decryption \033[0m" << endl;
    string dec;
    for (unsigned char ch : encDec)
    { //^ this return 0 if both the binary are 0 and 1 if not;
        ch = ch ^ pass;
        if (!isprint(ch))
        {
            ch = (ch % 95) + 32;  // Wrap it into the printable range (32-126)
        }
           if (isdigit(ch))  // Check if the character is a digit
        {
            ch = (ch - '0') ; //making it integer
            ch = ch^pass ;
        }
        cout << "\033[3;34m" << ch << "\033[0m \n";
        dec.push_back(ch);
    }
    cout << "\033[0;33mXOR Decryption successful\033[0m \n";
    return dec;
}