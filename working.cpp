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
 int counter = 0;  
 int j = Message.back() == 0? j = 0 : j = 1 ;
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
cout << "value " << img[smallestIndex];
// img[smallestIndex] = img[smallestIndex] - (img[smallestIndex] % 10);
// newValue += Message[counter];
// img[smallestIndex] += newValue ;
img[smallestIndex] = (img[smallestIndex] / 10) * 10 + Message[counter];   //gpt said that it forces the value 0,1 
cout << "newValue " << img[smallestIndex];
            counter++;
        }
    }
    cout << "\n" << "Processing the image" << "\n";
    return img;
}