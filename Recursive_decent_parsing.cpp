
#include <iostream>
#include <string>
using namespace std;

class Parser {
    string input;  // The input string to parse
    int pos;       // Current position in the string

public:
    Parser(string s) : input(s), pos(0) {} // Constructor to initialize input and position

    // Match a single expected character at the current position
    bool match(char expected) {
        if (pos < input.length() && input[pos] == expected) {
            pos++; // Move to next character
            return true;
        }
        return false;
    }

    // S → Aa | Ce
    bool S() {
        int save = pos; // Save position in case we need to backtrack

        if (A() && match('a')) // Try Aa
            return true;

        pos = save; // Backtrack
        if (C() && match('e')) // Try Ce
            return true;

        pos = save; // Backtrack again
        return false;
    }

    // A → aaB | aaba
    bool A() {
        int save = pos;

        // Try aaB
        if (match('a') && match('a') && B())
            return true;

        pos = save;

        // Try aaba
        if (match('a') && match('a') && match('b') && match('a'))
            return true;

        pos = save;
        return false;
    }

    // B → bbb
    bool B() {
        int save = pos;
        if (match('b') && match('b') && match('b'))
            return true;

        pos = save;
        return false;
    }

    // C → aaD
    bool C() {
        int save = pos;
        if (match('a') && match('a') && D())
            return true;

        pos = save;
        return false;
    }

    // D → bbd
    bool D() {
        int save = pos;
        if (match('b') && match('b') && match('d'))
            return true;

        pos = save;
        return false;
    }

    // Entry point: parse entire string
    bool parse() {
        return S() && pos == input.length(); // Accept only if full input matches
    }
};
int main() {
    string str = "aabbba"; // Try different inputs here
    Parser parser(str);

    if (parser.parse())
        cout << "Accepted\n";
    else
        cout << "Rejected\n";

    return 0;
}
