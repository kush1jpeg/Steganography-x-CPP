#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <bin.cpp>

vector<int> furtherWorking(vector<int> img, vector<int> Message)
{
    int counter = 0;

    for (int i = 0; i < img.size(); i += 3)
    {
        int smallest = 255;
        int smallestIndex = 255;
        vector<int> store; // to store the binary of the smallest value inside rgb values
        for (int j = 0; j < 3; j++)
        {
            if (img[i + j] < smallest)
            {
                smallest = img[j + i];
                smallestIndex = i+j ;
            }
        }
        while (smallest > 0) // smallest no in rgb to binary                     remember to do this is input in reverse
        {
            if (smallest % 2 == 0)
            {
                store.push_back(0);
            }
            else
            {
                store.push_back(1);
            }
            smallest = smallest >> 1; // shifts the bit bruh this is faster than dividing by 2
        }
        if (counter < Message.size())
        {
            store.pop_back();
            store.push_back(Message[counter]);
            counter++;
        }

        // converting store to binary
        int value = 0;
        for (int i = 0; i < store.size(); i++)
        {
            value = (value << 1) | store[i];
        }
        img[smallestIndex] = value ;

    }
             return img;
}