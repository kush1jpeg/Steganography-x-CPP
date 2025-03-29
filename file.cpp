#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include "cpp.h"
#include<cstdio>

using namespace std;

int main()
{     cout<<"Encrypt(e) or Decrypt(d)";
            char e;
            cin >> e;
    vector<int> Output ;
    vector<int> Message ;
    string msg;
    if(e=='e'){
    cout << "Enter the msg to be hidden- " << "\n";
    getline( cin >>ws, msg);
    Message = toBinary( msg );}    //msg in binary form
    string file;
    cout << "Enter the file name- " << '\n';
    cin >> file;

    ifstream inFile(file);
    if (!inFile) {
        cerr << "Error: File cannot be opened!" << endl;
        return 1;
    }

    string format;
    string comment;
    int width, height, maxVal;

    inFile >> format;
    while (inFile.peek() == '#') {
        getline(inFile, comment);
        cout << "Skipping comment: " << comment << endl;
    }

    if (format != "P3") {
        cout << "Converting " << file << " to PPM..." << endl;
        
        // Converting PNG/JPG to PPM 
        string ppmFile = "convertPPM.ppm";
        string convertCmd = "magick " + file + " -compress none -depth 8 -colorspace RGB -define \"ppm:format=p3\" " + ppmFile;
        int status = system(convertCmd.c_str());

        if (status != 0) {
            cerr << "Error: Conversion to PPM failed!" << endl;
            return 1;
        }

        //open the converted PPM file
        ifstream ppmInFile(ppmFile);
        if (!ppmInFile) {
            cerr << "Error: Failed to open converted PPM file!" << endl;
            return 1;
        }

        ppmInFile >> format >> width >> height >> maxVal;
        cout << "Converted to PPM: Width = " << width << ", Height = " << height << ", Format = " << format << endl;

        if (!ppmFile.empty()) {
             vector<int> img;
        int pixel;
        while (ppmInFile >> pixel) {
            img.push_back(pixel);
        }
            if(e=='d')
            {
              Output = decryptWorking(img) ; 
              mssg(Output);
              
            }
            Output = furtherWorking(img, Message);
        } else {
            cerr << "Failed to process converted PPM data!" << endl;
            return 1;
        }
    }  else {
        // If the input file is already PPM (P3), process it directly
        inFile >> width >> height >> maxVal;
        cout << "Processing PPM: Width = " << width << ", Height = " << height << ", Format = " << format << endl;

        vector<int> img;
        int pixel;
        while (inFile >> pixel) {
            img.push_back(pixel);
        }
        Output = furtherWorking(img, Message);
    }

    // Save the processed image in PPM format as well
    
    ofstream Outfile("output.ppm");
    Outfile << "P3\n" << width << " " << height << "\n255\n";
    
    for (int i = 0; i < Output.size(); i++) {
        Outfile << Output[i] << " ";  
        
        if ((i + 1) % (width * 3) == 0) {  
            Outfile << "\n";  
        }
    }
    Outfile.close();
    // Convert back to PNG
    if(e=='e'){
    int result;
    result = system("magick output.ppm output.png");
    if (result == 0) {
       cout << "Image saved as output.png" << endl;
    }
}
    return 0;
}
