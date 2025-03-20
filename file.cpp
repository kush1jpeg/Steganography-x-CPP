#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include "cpp.h"
#include<cstdio>

using namespace std;

int main()
{
    vector<int> Output;
    string msg;
    cout << "Enter the msg to be hidden- " << "\n";
    getline( cin >>ws, msg);
    vector<int> Message = toBinary(msg);    //msg in binary form
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
        string convertCmd = "magick " + file + " -compress none -depth 8 -colorspace sRGB -format ppm " + ppmFile;
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

        vector<unsigned char> ppmData = convertImg(ppmFile);
        if (!ppmData.empty()) {
            vector<int> newPPMdata(ppmData.begin(), ppmData.end());
            Output = furtherWorking(newPPMdata, Message);
            cout << "PPM processing complete!" << endl;
        } else {
            cerr << "Failed to process converted PPM data!" << endl;
            return 1;
        }
    } else {
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

    // Convert back to PNG
    FILE* pipe = _popen("magick PPM:- output.png", "wb");
    if (!pipe) {
        cerr << "Error: Failed to open pipe to ImageMagick" << endl;
        return 1;
    }
    
    int result = ppmToOther(Output, pipe, width, height);
    if (result == 0) {
        cout << "Image saved as output.png" << endl;
    }
    _pclose(pipe);

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
    

    return 0;
}
