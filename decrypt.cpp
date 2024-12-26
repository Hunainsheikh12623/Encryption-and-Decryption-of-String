#include <iostream>
#include <string>
#include<conio.h>
#include <map>
using namespace std;

string decrypt() {
    
    map<string, char> decryptMap = {
        {"1", '`'}, {"10", '~'}, {"11", '!'}, {"100", '@'}, {"101", '#'}, {"110", '$'},
        {"111", '%'}, {"1000", '^'}, {"1001", '&'}, {"1010", '*'}, {"1011", '('}, {"1100", ')'},
        {"1101", '_'}, {"1110", '-'}, {"1111", '+'}, {"10000", '='}, {"10001", '{'}, {"10010", '}'},
        {"10011", '['}, {"10100", ']'}, {"10101", '|'}, {"10110", ':'}, {"10111", ';'}, {"11000", '"'},
        {"11001", '?'}, {"11010", '<'}, {"11011", '>'}, {"11100", ','}, {"11101", '.'}, {"11110", '/'},
        {"11111", ' '}, 
        {"10000010", 'Q'}, {"100000", 'q'},
        {"10000110", 'W'}, {"100001", 'w'},
        {"10001010", 'E'}, {"100010", 'e'},
        {"10001110", 'R'}, {"100011", 'r'},
        {"10010010", 'T'}, {"100100", 't'},
        {"10010110", 'Y'}, {"100101", 'y'},
        {"10011010", 'U'}, {"100110", 'u'},
        {"10011110", 'I'}, {"100111", 'i'},
        {"10100010", 'O'}, {"101000", 'o'},
        {"10100110", 'P'}, {"101001", 'p'},
        {"10101010", 'A'}, {"101010", 'a'},
        {"10101110", 'S'}, {"101011", 's'},
        {"10110010", 'D'}, {"101100", 'd'},
        {"10110110", 'F'}, {"101101", 'f'},
        {"10111010", 'G'}, {"101110", 'g'},
        {"10111110", 'H'}, {"101111", 'h'},
        {"11000010", 'J'}, {"110000", 'j'},
        {"11000110", 'K'}, {"110001", 'k'},
        {"11001010", 'L'}, {"110010", 'l'},
        {"11001110", 'Z'}, {"110011", 'z'},
        {"11010010", 'X'}, {"110100", 'x'},
        {"11010110", 'C'}, {"110101", 'c'},
        {"11011010", 'V'}, {"110110", 'v'},
        {"11011110", 'B'}, {"110111", 'b'},
        {"11100010", 'N'}, {"111000", 'n'},
        {"11100110", 'M'}, {"111001", 'm'},
        {"111010", '1'}, {"111011", '2'}, {"111100", '3'}, {"111101", '4'},
        {"111110", '5'}, {"111111", '6'}, {"1000000", '7'}, {"1000001", '8'}, {"1000010", '9'}, {"1000011", '0'}
    };

    string code;
    cout << "Enter the encrypted text to decrypt (binary codes separated by spaces): ";
    getline(cin, code);

    string decodedText = "";
    string currentCode = "";

    // Iterate through the input code
    for (char ch : code) {
        if (ch == ' ') {
            // If a space is encountered, process the current code
            if (decryptMap.find(currentCode) != decryptMap.end()) {
                decodedText += decryptMap[currentCode]; // Append the corresponding character
            } else {
                decodedText += '?'; // Append '?' for unknown codes
            }
            currentCode = ""; // Reset for the next code
        } else {
            // Build the current binary code
            currentCode += ch;
        }
    }

    // Process the last code if any
    if (!currentCode.empty()) {
        if (decryptMap.find(currentCode) != decryptMap.end()) {
            decodedText += decryptMap[currentCode];
        } else {
            decodedText += '?';
        }
    }

    return decodedText;
}

int main() {
    string decryptedText = decrypt();
    cout << "Decrypted text: " << decryptedText << endl;
    getch();
    return 0;
}
   


