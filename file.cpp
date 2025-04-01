#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include "cpp.h"
#include <cstdio>
#include <algorithm>
#include <cctype>
#include <cmath>
using namespace std;

int main()
{
    cout << "\033[1;31m" << u8R"(  
  _____ _               _       ____ 
 / ____(_)             | |     |___ \
| |     _  ___ __ _  __| | __ _  __) |
| |    | |/ __/ _` |/ _` |/ _` ||__ <  
| |____| | (_| (_| | (_| | (_| |___) |                    
 \_____|_|\___\__,_|\__,_|\__,_|___ a ripOff by kush-                                                                  
)" << "\033[0m";
cout << "\033[2;32m"
"-------------------------------------------------\n \033[0m"
"\033[3;36mA mysterious steganography tool inspired by the\033[0m\n"
"\033[3;36mlegendary Cicada 3301 puzzles. Hide secrets in\033[0m\n"
"\033[3;36mplain sight, encrypt messages inside images for\033[0m\n"
"\033[3;36mthe world to never notice.\033[0m\n"
"\033[2;33m    Not everything should be revealed...\033[0m\n";

    cout << "\033[2;32m    =====================================\033[0m\n";
    cout << "\033[1;32m       Encrypt (e)  |  Decrypt (d)       \033[0m\n";
    cout << "\033[2;32m ===================================\033[0m                ";
    char e;
    cin >> e;
    e = tolower(e);
    if (e != 'd' && e != 'e')
    {
        cout << "\n";
        cout << "\033[1;31mPls don't be a \"vegan bitch\" \033[0m " << endl;
        return 0;
    }
    vector<int> Output;
    vector<int> Message;
    string msg;
    string file;
    cout << "\n\033[1;32mEnter the file name: \033[0m";
    cin >> file;
    cin.ignore();  // Ignore leftover newline character
    ifstream inFile(file);
    cout << "Trying to open the file"  ;
    if (!inFile)
    {
        cerr << "\033[0;35mError: File does not exist or cannot be opened! \033[0m" << endl;
        return 1;
    }

    string format;
    string comment;
    int width, height, maxVal;

    inFile >> format;
    while (inFile.peek() == '#')
    {
        getline(inFile, comment);
        // cout << "Skipping comment: " << comment << endl;    for debug
    }

    if (format != "P3")
    {
        cout << "\n \033[3;34mConverting " << file << " to PPM...\n\033[0m" << endl; // removed the functioning of the converting.cpp cuz of my impotency to use pipes and handle memory
                                                                                     //      SKILL ISSUE it is called..
        // png to ppm
        string ppmFile = "convertPPM.ppm";
        string convertCmd = // gpt said to change the png to bmp first and then to ppm cuz JPG lossily compresses images, so LSB-based steganography will break because pixel values slightly change. PNG might also modify some values, depending on how it's handled.
            e == 'e' ? "magick \"" + file + "\" -compress none -depth 8 -set colorspace RGB -define jpg:bit-depth=8 -define jpg:color-type=2 -clamp -compress none -alpha Off BMP3:temp.bmp && "
                                            "magick temp.bmp -compress none -depth 8 -set colorspace RGB -alpha Off PPM:convertPPM.ppm"
                     : "magick \"" + file + "\" -compress none -depth 8 -set colorspace RGB -alpha Off PPM:convertPPM.ppm";
        ;
        int status = system(convertCmd.c_str());

        if (status != 0)
        {
            cerr << "\033[0;35mError: Conversion to PPM failed!\033[0m" << endl;
            return 1;
        }

        // Opening the ppm file
        ifstream ppmInFile(ppmFile);
        if (!ppmInFile)
        {
            cerr << "\033[0;35mError: Failed to open converted PPM file!\033[0m" << endl;
            return 1;
        }

        ppmInFile >> format >> width >> height >> maxVal;
        cout << "\033[0;33m** Converted " << file << " to PPM: Width = " << width << ", Height = " << height << ", Format = " << format << "  **\n\033[0m" << endl;
        int pass = ceil(((width))% 395 + 1) ; 
        // cout << "PASSWORD    -" << pass ;
        if (e == 'e')
        {
            cout << "\n\033[1;32mEnter the msg to be hidden: \033[0m";
            getline(cin >> ws, msg);
            cout << "\033[0;33m Beginning the XOR-encryption \033[0m" << endl ;
            string msgg = xorEncrypt(msg , pass) ;
            Message = toBinary(msgg); // Convert msg to binary
        }    
        if (!ppmFile.empty())
        {
            vector<int> img;
            int pixel;
            while (ppmInFile >> pixel)
            {
                img.push_back(pixel);
            }
            if (e == 'd')
            {
                Output = decryptWorking(img);
                vector<char> encDecrypted = mssg(Output);
                string Decrypted = xorDecrypt(encDecrypted , pass);
                ppmInFile.close();
                cout<<"\033[3;34mRemoving temp files..... \n";
            remove("convertPPM.ppm");
            cout<<"Removed convertPPM.ppm \n\033[0m";
            cout << endl;
           if(Decrypted.empty()){
                    cout << "\033[2;31m      =====================================\033[0m\n";
                    cout << "\033[1;31m **      No message encrypted :(      **\033[0m\n";
                    cout << "\033[2;31m===================================\033[0m";
                    return 0;
                }
                cout << "\033[3;31m The message decrypted is - \033[0m\n";
                cout << "\033[2;31m      =====================================\033[0m\n";
                cout << "🗝️ \033[1;31m **       " + Decrypted + "      **\033[0m 🗝️" << endl;
                cout << "\033[2;31m===================================\033[0m";
                return 0;
            }
            Output = furtherWorking(img, Message);
        }
        else
        {
            cerr << "\033[0;35mFailed to process converted PPM data!\033[0m" << endl;
            return 1;
        }
    }
    else
    {
        inFile >> width >> height >> maxVal;
        cout << "\033[2;33mProcessing PPM: Width = " << width << ", Height = " << height << ", Format = " << format << "\033[0m" << endl;
        int pass = ceil(((width+height))% 195 + 2) ; 
       // cout << "PASSWORD    -"  <<pass ;
        vector<int> img;
        int pixel;
        while (inFile >> pixel)
        {
            img.push_back(pixel);
        }
        string msgg = xorEncrypt(msg , pass) ;
        Message = toBinary(msgg); // Convert msg to binary
        Output = furtherWorking(img, Message);
    }

    // Saving in ppm
    ofstream Outfile("output.ppm");
    Outfile << "P3\n"
            << width << " " << height << "\n255\n";

    for (int i = 0; i < Output.size(); i++)
    {
        Outfile << Output[i] << " ";
        if ((i + 1) % (width * 3) == 0)
        {
            Outfile << "\n";
        }
    }
    cout << "\033[3;34mProcessing completed//\033[0m" << endl;
    Outfile.close();

    // ppm to bmp
    if (e == 'e')
    {
        int result = system("magick output.ppm -compress none -depth 8 -type TrueColor BMP3:enc.bmp");
        if (result == 0)
        {   
            inFile.close();
            cout<<"\033[3;34mRemoving temp files..... \n";
            remove("convertPPM.ppm");
            cout<<"Removed convertPPM.ppm \n";
            remove("output.ppm");
            cout<<"Removed output.ppm \n";
            remove("temp.bmp");
            cout<<"Removed temp.bmp \033[0m\n\n";

cout << "\033[0;33m......   Saving the image   ......\033[0m\n\n"   ;         
            cout << "\033[2;32m      ||==============================================\033[0m\n";
            cout << "🔒 \033[1;31m**       Image saved as enc.bmp      **\033[0m 🔒" << endl;
            cout << "\033[2;32m  ==========================================||\033[0m                    ";
        }
    }

    return 0;
}
