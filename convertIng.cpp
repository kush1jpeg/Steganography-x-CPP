#include <cpp.h>
#include <iostream>
using namespace std;
#include <boost/process/system.hpp>
#include <boost/process/io.hpp>

#include <vector>
vector<unsigned char> convertImg(string file){
 
    boost::process::ipstream pipe_stream;
    // Capture output from ImageMagick
    std::vector<unsigned char> ppmData;
    boost::process::child process("magick " + file + " ppm:-", boost::process::std_out > pipe_stream);
    // bp::child starts the ImageMagick cmd
    // ppm:- tells ImageMagick to output the PPM data directly to stdout (instead of a file).
    // bp::std_out > pipe_stream redirects this output into pipe_stream, so we can read it.    -> https://www.geeksforgeeks.org/pipe-system-call/?ref=ml_lbp
    char ch;
    while (pipe_stream.get(ch))
    {
        ppmData.push_back(ch);
    }
    return ppmData;
}
