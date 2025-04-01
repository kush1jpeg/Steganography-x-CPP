#ifndef CPP_H
#define CPP_H


// got to know that header guards are capital case shit!
#include <vector>
using namespace std;
#include <string>

std::vector<int> toBinary(std::string msg); 
vector<int> furtherWorking(vector <int> & img , vector<int> &message);
vector <int> decryptWorking(vector<int>img);
vector<char> mssg(vector<int> Output);
string xorDecrypt(vector<char> encDec ,int pass);
string xorEncrypt(string msg ,int pass);
#endif 
