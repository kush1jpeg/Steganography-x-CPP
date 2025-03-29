#ifndef CPP_H
#define CPP_H


// got to know that header guards are capital case
#include <vector>
using namespace std;
#include <string>

std::vector<int> toBinary(std::string msg); 
vector<unsigned char>convertImg(const std::string& file);
vector<int> furtherWorking(vector <int> & img , vector<int> &message);
int ppmToOther(vector<int>Output, FILE* pipe,  int width, int height);
vector <int> decryptWorking(vector<int>img);
void mssg(vector<int> Output);
#endif 
