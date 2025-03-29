#include <iostream>
#include <vector>
using namespace std;

void mssg(vector<int> Output) {
    cout << "Checking the output vector - ";
    for (int bit : Output) cout << bit;
    cout << "\n";

    cout << "The decrypted message is - ";
    
    for (size_t i = 0; i + 7 < Output.size(); i += 8) {  // Process in 8-bit groups
        int sum = 0;
        bool isTerminator = true;

        cout << "\nProcessing chunk: ";
        for (int j = 0; j < 8; j++) {
            cout << Output[i + j];  // Debug: Show each 8-bit group

            sum = (sum << 1) | Output[i + j]; // Convert binary to decimal

            if (Output[i + j] != 0)  
                isTerminator = false;
        }
        cout << " -> Decimal: " << sum;  // Debug: Show the decimal value

        if (isTerminator) {  
            cout << "\n[Terminator sequence detected. Stopping decryption.]\n";
            break;
        }
        cout << " -> Char: " << static_cast<char>(sum);  // Print decoded character
    }
    cout << endl;
}