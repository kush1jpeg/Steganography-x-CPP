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
    cin >> file ;
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
      std::vector<unsigned char> ppmData = convertImg(file);
         if (!ppmData.empty()) {
            vector<int> newPPMdata(ppmData.begin() , ppmData.end())  ;          ///CONVERTS the unsigned char vector to int vector 
        std::cout << "PPM conversion successful! Data size: " << ppmData.size() << " bytes\n";
        furtherWorking(newPPMdata,Message) ;
    } else {
        std::cerr << "Failed to convert image.\n";
    }
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
//created a funct for simplification and optimization for both the ppdData and img vector`
 furtherWorking(img , Message); 
}