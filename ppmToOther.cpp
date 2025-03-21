#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include "cpp.h"


int ppmToOther(vector<int> Output, FILE* pipe, int width, int height) {
  cout << "height= " << height << " width= " << width << endl;
  fprintf(pipe, "P3\n%d %d\n255\n", width, height);

  vector<unsigned char> binaryOutput;
  for (int pixel : Output) {
      binaryOutput.push_back(static_cast<unsigned char>(pixel));
  }

  fwrite(binaryOutput.data(), 1, binaryOutput.size(), pipe);
  fflush(pipe);
  pclose(pipe);

  return 0;
}