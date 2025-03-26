#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include "cpp.h"
#include <algorithm>
using namespace std ;
vector<int> furtherWorking(vector<int> &img, vector<int> Message)
{
 int counter = 0;

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
img[smallestIndex] = img[smallestIndex] - (img[smallestIndex] % 2);
newValue += Message[counter];
img[smallestIndex] = newValue ;
            counter++;
        }
    }
    return img;
}