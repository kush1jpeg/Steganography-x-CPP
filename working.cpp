#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include "cpp.h"
#include <algorithm>
using namespace std ;
vector<int> furtherWorking(vector<int> &img, vector<int> &Message)
{
    cout <<"\033[3;34mBeginning the encryption ..... \033[0m"<<"\n" ;
 int counter = 0;  
 int j = Message.back() == 0? j = 1 : j = 0 ;
   for (int i = 0 ; i < 8 ; i++) {
        Message.push_back(j);
    }                            //terminator logic to identify that the message has ended basically exit the
                                //decryption whenver you encounter eight 0 next to each other  

    for (int i = 0; i < img.size(); i += 3) {
        int smallest = 255;
        int smallestIndex = -1; 

        // Find the smallest value in the RGB triplet
        for (int j = 0; j < 3; j++) {
            if (img[i + j] < smallest) {
                smallest = img[i + j];
                smallestIndex = i + j;
            }
        }

        if (counter < Message.size()) {
            int newValue  = 0;
// shoving the msg up the lsb's azz
cout << "\033[3;34mValue " << img[smallestIndex] << " ------------> " ;
// img[smallestIndex] = img[smallestIndex] - (img[smallestIndex] % 10);
// newValue += Message[counter];
// img[smallestIndex] += newValue ;
//or
img[smallestIndex] = (img[smallestIndex] / 10) * 10 + Message[counter];  //gpt's so short bruh
cout << "\033[3;34m newValue " << img[smallestIndex] << "\033[0m\n";
            counter++;
        }
    }
    cout <<"\033[3;34mEncryption completed \033[0m" << "\n";
    cout <<endl ;
    cout <<"\033[0;33m......  Processing the image  ......\033[0m" << "\n";
    cout <<endl ;
    return img;
}