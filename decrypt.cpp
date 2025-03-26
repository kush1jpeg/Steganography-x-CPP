#include <iostream>
#include <vector>
#include <string>
#include "cpp.h"

using namespace std;

vector<int> decryptWorking(vector<int> img) {
    vector<int> no;

    for (int i = 0; i < img.size(); i += 3) {
        int small = 255;

        // Find the smallest RGB value in the triplet
        for (int j = 0; j < 3; j++) {
            if (small > img[i + j]) {
                small = img[i + j];
            }
        }

      
        if (small % 10 == 0 || small % 10 == 1) {
            no.push_back(small % 10);
        } else {
            return no;
        }
    }

    return no;
}

