#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>

using std::vector;
using std::string;
using std::cout;

vector<string> readFile();
int lineValue(const string& line);
string convertStringToDigit(const string& line);
string convertStringToDigitOrg(const string& line);

string filePath = R"(C:\Dev\Text_files\input.txt)";



int main() {
    vector<string> rawInput = readFile();

    int sum = 0;
    for (auto const &line: rawInput){
        // Part 1
        //sum += lineValue(line);

        // Part 2
        string lineAsDigits = convertStringToDigit(line);
        sum += lineValue(lineAsDigits);
    }

    std::cout << sum;

    return 0;
}


string convertStringToDigit(const string& line){
    std::map<string, char> digitMap;
    digitMap["one"] = '1';
    digitMap["two"] = '2';
    digitMap["thr"] = '3';
    digitMap["fou"] = '4';
    digitMap["fiv"] = '5';
    digitMap["six"] = '6';
    digitMap["sev"] = '7';
    digitMap["eig"] = '8';
    digitMap["nin"] = '9';

    string digits;
    for (int i=0; i<line.size(); i++){
        char currentChar = line[i];

        if (isdigit(currentChar)){
            digits += currentChar;
        } else {
            string testString = line.substr(i, 3);
            auto iterator = digitMap.find(testString);
            if (iterator != digitMap.end()) {
                digits += iterator->second;
            }
        }
    }
    return digits;
}


string convertStringToDigitOrg(const string& line){
    string digits;
    for (int i=0; i<line.size(); i++){
        char currentChar = line[i];

        if (isdigit(currentChar)){
            digits += currentChar;
        } else {
            char nextChar = line[i+1];
            char nextNextChar = line[i+2];
            switch (currentChar){
                case 'o':
                    if (nextChar == 'n' && nextNextChar == 'e'){
                        digits += '1';
                    }
                    break;
                case 't':
                    if (nextChar == 'w' && nextNextChar == 'o'){
                        digits += '2';
                    } else if (nextChar == 'h' && nextNextChar == 'r'){
                        digits += '3';
                    }
                    break;
                case 'f':
                    if (nextChar == 'o' && nextNextChar == 'u'){
                        digits += '4';
                    } else if (nextChar == 'i' && nextNextChar == 'v'){
                        digits += '5';
                    }
                    break;
                case 's':
                    if (nextChar == 'i' && nextNextChar == 'x'){
                        digits += '6';
                    } else if (nextChar == 'e' && nextNextChar == 'v'){
                        digits += '7';
                    }
                    break;
                case 'e':
                    if (nextChar == 'i' && nextNextChar == 'g'){
                        digits += '8';
                    }
                    break;
                case 'n':
                    if (nextChar == 'i' && nextNextChar == 'n'){
                        digits += '9';
                    }
                    break;
            }
        }
    }

    return digits;
}


int lineValue(const string& line){
    char firstDigit = '\0';
    char lastDigit = '\0';
    for (char currentChar : line){
        if (isdigit(currentChar)){
            if (firstDigit){
                lastDigit = currentChar;
            } else {
                firstDigit = currentChar;
            }
        }
    }

    if (!lastDigit){
        lastDigit = firstDigit;
    }

    string lineNumber;
    lineNumber += firstDigit;
    lineNumber += lastDigit;

    return std::stoi(lineNumber);
}


vector<string> readFile(){
    vector<string> rawInput;

    std::ifstream file(filePath);

    if (file.is_open()) {
        string line;
        while(std::getline(file, line)) {
            rawInput.push_back(line);
        }
    } else {
        std::cout << "Unable to open file";
    }
    return rawInput;
}