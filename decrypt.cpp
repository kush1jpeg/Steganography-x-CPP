#include <iostream>
#include <vector>
#include <string>
#include "cpp.h"
#include <algorithm>

using namespace std;

vector<int> decryptWorking(vector<int> img) {
    vector<int> no;

    for (int i = 0; i < img.size(); i += 3) {
        int small = 255;
        for (int j = 0; j < 3; j++) {
            if (small > img[i + j]) {
                small = img[i + j];
            }
        }

        cout << "Pixel Value: " << small << ", Extracted Bit: " << (small % 10) << endl; // Debugging line

        int bit = small % 10;
        if (bit == 0 || bit == 1) {
            no.push_back(bit);
        } else {
            cout << "Stopped at invalid bit: " << bit << endl;
            break;
        }
    }
    cout<< "checking the no vector - ";
for(int n:no){
    cout << n ;
}
    return no;
}
