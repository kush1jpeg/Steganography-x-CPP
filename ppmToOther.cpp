#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include "cpp.h"


int ppmToOther(vector<int>Output, FILE* pipe,  int width, int height){

  // Writing the  PPM header
    fprintf(pipe, "P6\n %d %d \n 255 \n", width, height);
    
       // You are writing binary data (P6), but Output is an std::vector<int>The fwrite() 
       //function writes raw bytes, but std::vector<int> stores 4-byte integers instead of 1-byte unsigned char values
    vector<unsigned char> binaryOutput;
    for (int pixel : Output) {
      if (pixel < 0) pixel = 0;     // Clamp values between 0-255
      if (pixel > 255) pixel = 255; 
      binaryOutput.push_back(static_cast<unsigned char>(pixel));
  }

    // Writing pixel data
    fwrite(binaryOutput.data(), 1, binaryOutput.size(), pipe);// Writing pixel data

return 0;
}