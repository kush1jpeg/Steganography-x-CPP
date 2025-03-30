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

    if (e == 'e') {
        cout << "Enter the msg to be hidden: " << "\n";
        getline(cin >> ws, msg);
        Message = toBinary(msg);  // Convert msg to binary
    }

    string file;
    cout << "Enter the file name: " << '\n';
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
        cout << "Converting " << file << " to PPM..." << endl; //removed the functioning of the converting.cpp cuz of my impotency to use pipes and handle memory 
                                                          //     SKILL ISSUE it is called..
        // png to ppm 
        string ppmFile = "convertPPM.ppm";
        string convertCmd =  //gpt said to change the png to bmp first and then to ppm cuz JPG lossily compresses images, so LSB-based steganography will break because pixel values slightly change. PNG might also modify some values, depending on how it's handled.
        e=='e'?
        "magick \"" + file + "\" -compress none -depth 8 -set colorspace RGB -define jpg:bit-depth=8 -define jpg:color-type=2 -clamp -compress none -alpha Off BMP3:temp.bmp && "
        "magick temp.bmp -compress none -depth 8 -set colorspace RGB -alpha Off PPM:convertPPM.ppm"
              :
         "magick \""+file+"\" -compress none -depth 8 -set colorspace RGB -alpha Off PPM:convertPPM.ppm";
    ;
        int status = system(convertCmd.c_str());

        if (status != 0) {
            cerr << "Error: Conversion to PPM failed!" << endl;
            return 1;
        }

        // Opening the ppm file
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
            if (e == 'd') {
                Output = decryptWorking(img);
                mssg(Output);
            }
            Output = furtherWorking(img, Message);
        } else {
            cerr << "Failed to process converted PPM data!" << endl;
            return 1;
        }
    } else {
        inFile >> width >> height >> maxVal;
        cout << "Processing PPM: Width = " << width << ", Height = " << height << ", Format = " << format << endl;

        vector<int> img;
        int pixel;
        while (inFile >> pixel) {
            img.push_back(pixel);
        }
        Output = furtherWorking(img, Message);
    }

    // Saving in ppm
    ofstream Outfile("output.ppm");
    Outfile << "P3\n" << width << " " << height << "\n255\n";

    for (int i = 0; i < Output.size(); i++) {
        Outfile << Output[i] << " ";  
        
        if ((i + 1) % (width * 3) == 0) {  
            Outfile << "\n";  
        }
    }
    Outfile.close();

    // ppm to bmp 
    if (e == 'e') {
        int result = system("magick output.ppm -compress none -depth 8 -type TrueColor BMP3:output.bmp");
        if (result == 0) {
            cout << "Image saved as output.bmp" << endl;
        }
    }

    return 0;
}
