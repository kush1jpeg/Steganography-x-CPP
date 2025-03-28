#include "cpp.h"
#include <iostream>
#include <cstdio>  // For popen, fread
#include <vector>
#include <string>
#include <cstdio> 
using namespace std;

vector<unsigned char> convertImg(const string& file) {
    vector<unsigned char> ppmData;
    
    // Command to run ImageMagick
    string command = "magick " + file + " -compress none -depth 8 -colorspace RGB  ppm:-";

    
    // Open a pipe to capture the output
    FILE* pipe = popen(command.c_str(), "r");
    if (!pipe) {
        cerr << "Failed to open pipe!" << endl;
        return ppmData;
    }

    // wasnt able to do this so gpt's code this is
    size_t bytesRead; //temporary storage area to hold the data read from the pipe.
    char buffer[4096];
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), pipe)) > 0) {
        ppmData.insert(ppmData.end(), buffer, buffer + bytesRead);//buffer + bytesRead ensures that only valid bytes are inserted (not garbage data from uninitialized memory).
    }

    // Close the pipe
    pclose(pipe);
    
    return ppmData;
}
