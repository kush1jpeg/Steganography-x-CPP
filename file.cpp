#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include "cpp.h"
#include <bin.cpp>
#include<cstdio>

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
    vector<int> img;
    if (!inFile)
    {
        cout << "File cannot be openend";
    }
    int counter = 0;
    string format;
    string comment;
        int width, height, maxVal;
        while (inFile.peek() == '#')
        {
            getline(inFile, comment); // get the line and stores it in comment
        }
        inFile >> format >> height >> width >> maxVal;
    if (format != "P3")
    {
      std::vector<unsigned char> ppmData = convertImg(file); //other to ppm
         if (!ppmData.empty()) {
            vector<int> newPPMdata(ppmData.begin() , ppmData.end())  ;          ///CONVERTS the unsigned char vector to int vector 
        std::cout << "PPM conversion successful! Data size: " << ppmData.size() << " bytes\n";
       img= furtherWorking(newPPMdata,Message) ;
    } else {
        std::cerr << "Failed to convert image.\n";
    }
    }
    inFile >> format;
    
    int pixel;
    while (inFile >> pixel)
    {
        img.push_back(pixel);
    }
//created a funct for simplification and optimization for both the ppdData and img vector`
 vector<int> Output = furtherWorking(img , Message); 
if(format!="P3"){
  FILE* pipe = _popen("convert - output.jpg", "w");
    if (!pipe) {
        std::cerr << "Error: Failed to open pipe to ImageMagick\n";
        return 1;
    }
    int result= ppmToOther( Output ,pipe, width, height);
    if(result==0) {
    std::cout << "Image saved as output.jpg" << std::endl;  
    }
    _pclose(pipe);

}
ofstream Outfile("output.ppm");
for (int value : Output) {
    Outfile << value << " ";
}

Outfile.close();


}