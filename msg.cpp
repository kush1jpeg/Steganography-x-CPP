#include <iostream>
using namespace std;
#include <vector>
  
void mssg(vector<int>Output){
for(int i = 0 ; i<Output.size() ; i+=8){
  int sum=0;
  for(int j=0 ; j<8 ;j++)
    sum+=Output[i+j];
    cout << static_cast<char>(sum);
}
}