#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<char> mssg(vector<int> Output) {
    vector<char> msg;
    cout <<endl;
    cout << "\033[1;34mChecking the output vector - \033[0m";
    // for (int bit : Output) cout << bit;
    
    for (size_t i = 0; i + 7 < Output.size(); i += 8) {  // Process in 8-bit groups
        int sum = 0;
        bool isTerminator = true;
        cout << "\033[3;34m \nProcessing chunk: \033[0m";
        for (int j = 0; j < 8; j++) {
            cout <<"\033[1;34m"<< Output[i + j]<< "\0330m";  // Debug: Show each 8-bit group

            sum = (sum << 1) | Output[i + j]; // Convert binary to decimal using shift operation basically  it shifts the digit to the lft by adding the character and | is like 1 if one is 1

            if (Output[i] != Output[i+j] )   //checking the termination statements which can be eight 0 or eight 1
                isTerminator = false;
        }
        cout << " -> \033[3;34m Decimal: \033[0m" << "\033[3;34m"<<sum << "\033[0m";  // Debug: Show the decimal value
        cout << " -> \033[3;34mChar: \033[0m" <<"\033[1;32m"<< static_cast<char>(sum) <<"\033[0m";  // Print decoded character
        char a=static_cast<char>(sum);
        if (isTerminator) {  
            cout << "\033[3;33m \n[ Terminator detected ]\n \033[0m";
            break;
        }
        if(sum!=0)msg.push_back(a); 
    }
    cout << endl;
    return msg;
}