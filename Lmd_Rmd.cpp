#include <iostream>
#include <string>
using namespace std;

// Function to perform leftmost derivation
void leftmostDerivation(string input) {
    string str = input;
    cout << "Leftmost Derivations:\n";
    cout << "Step 1: " << str << endl;

    // Replace A (leftmost)
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == 'A') {
            str[i] = 'b'; // A → b
            cout << "Step 2: " << str << endl;
            break;
        }
    }

    // Replace B
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == 'B') {
            str[i] = 'c'; // B → c
            cout << "Step 3: " << str << endl;
            break;
        }
    }
}

// Function to perform rightmost derivation
void rightmostDerivation(string input) {
    string str = input;
    cout << "\nRightmost Derivations:\n";
    cout << "Step 1: " << str << endl;

    // Replace B (rightmost)
    for (int i = str.length() - 1; i >= 0; --i) {
        if (str[i] == 'B') {
            str[i] = 'c'; // B → c
            cout << "Step 2: " << str << endl;
            break;
        }
    }

    // Replace A
    for (int i = str.length() - 1; i >= 0; --i) {
        if (str[i] == 'A') {
            str[i] = 'b'; // A → b
            cout << "Step 3: " << str << endl;
            break;
        }
    }
}

int main() {
    string input = "aAB"; // Initial input string

    // Perform leftmost and rightmost derivations
    leftmostDerivation(input);
    rightmostDerivation(input);

    return 0;
}
