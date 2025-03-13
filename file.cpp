#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <cper.h>
#include <bin.cpp>

using namespace std;

int main()
{
    string msg;
    cout << "Enter the msg to be hidden- " << "\n";
    cin >> msg;
    vector<int> Message = toBinary(msg);    //msg in binary form
    string file;
    cout << "Enter the file name- " << '\n';
    ifstream inFile(file);
    if (!inFile)
    {
        cout << "File cannot be openend";
    }
    int counter = 0;
    string format;
    string comment;
    int width, height, maxVal;
    inFile >> format;
    if (format != "P3")
    {
        cout << "Unsupported PPM format" << endl;
        return 1;
    }
    inFile >> format;
    while (inFile.peek() == '#')
    {
        getline(inFile, comment); // get the line and stores it in comment
    }
    vector<int> img;
    int pixel;
    while (inFile >> pixel)
    {
        img.push_back(pixel);
    }

    for (int i = 0; i < img.size(); i += 3)
    { 
        int smallest=0 ;
        vector<int> store; //to store the binary of the smallest value inside rgb values
        for (int j = 0; j < 3; j++)
        {
            if(img[j] < smallest){
                smallest = img[j] ;
            }
        }
        while(smallest/2==0) //smallest no in rgb to binary
        {
            if (smallest%2==0){store.push_back(0) ;}
            else{store.push_back(1) ;}
            smallest = smallest/2 ;
        } 
        if(counter = Message.size()-1)
        { store.pop_back();
         store.push_back( Message[i] ) ;
         counter++ ;
        }

    }
}