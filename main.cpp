#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <sstream>

using std::vector;
using std::string;
using std::cout;
using std::endl;

string filePath = R"(C:\Dev\Text_files\input.txt)";
vector<string> readFile();
vector<string> splitLine(const string& line, const char& delimiter);
string trim(const string& str);

// part 2

int main() {
    vector<string> rawInput = readFile();

    string roundDataRaw;
    int minimumCubes;
    int sumCubes = 0;

    for (auto const &line: rawInput){
        string delimiter = ":";
        int delimiterIndex = line.find(delimiter);

        // round data
        roundDataRaw = line.substr(delimiterIndex+2);
        vector<string> gameSplit = splitLine(roundDataRaw, ';');

        int maxRed = 1;
        int maxGreen = 1;
        int maxBlue = 1;

        vector<string> currentRoundSplit;
        for (const auto &game: gameSplit) {
            currentRoundSplit = splitLine(game, ',');

            // current round
            for (const auto &round: currentRoundSplit) {

                vector<string> currentRoundData = splitLine(round, ' ');
                int cubeCount = std::stoi(currentRoundData.at(0));
                string cubeColour = currentRoundData.at(1);

                if (cubeColour == "red") {
                    if (cubeCount > maxRed){
                        maxRed = cubeCount;
                    }
                } else if (cubeColour == "green") {
                    if (cubeCount > maxGreen){
                        maxGreen = cubeCount;
                    }
                } else if (cubeColour == "blue") {
                    if (cubeCount > maxBlue){
                        maxBlue = cubeCount;
                    }
                }
            }
        }
        minimumCubes = maxRed * maxBlue * maxGreen;
        sumCubes += minimumCubes;
    }

    cout << sumCubes;

    return 0;
}

// Part 1
//int main() {
//    vector<string> rawInput = readFile();
//
//    string gameNumberRaw;
//    int gameNumber;
//    string roundDataRaw;
//    int gameIDSum = 0;
//
//    for (auto const &line: rawInput){
//        bool validGame = true;
//        string delimiter = ":";
//        int delimiterIndex = line.find(delimiter);
//
//        // game number
//        gameNumberRaw = line.substr(0, delimiterIndex);
//        gameNumber = std::stoi(gameNumberRaw.substr(5));
//
//        // round data
//        roundDataRaw = line.substr(delimiterIndex+2);
//        vector<string> gameSplit = splitLine(roundDataRaw, ';');
//
//        vector<string> currentRoundSplit;
//        for (const auto &game: gameSplit) {
//            currentRoundSplit = splitLine(game, ',');
//
//            int redCubes = 0;
//            int greenCubes = 0;
//            int blueCubes = 0;
//
//            // current round
//            for (const auto &round: currentRoundSplit) {
//
//                vector<string> currentRoundData = splitLine(round, ' ');
//                int cubeCount = std::stoi(currentRoundData.at(0));
//                string cubeColour = currentRoundData.at(1);
//
//                if (cubeColour == "red") {
//                    redCubes = cubeCount;
//                } else if (cubeColour == "green") {
//                    greenCubes = cubeCount;
//                } else if (cubeColour == "blue") {
//                    blueCubes = cubeCount;
//                }
//            }
//
//            if (redCubes > 12 || greenCubes > 13 || blueCubes > 14) {
//                validGame = false;
//                break;
//            }
//        }
//
//        if (validGame){
//            gameIDSum += gameNumber;
//        }
//
//    }
//
//    cout << gameIDSum;
//
//    return 0;
//}

vector<string> splitLine(const string& line, const char& delimiter){
    vector<string> splitString;

    std::stringstream stream(line);

    string currentLine;
    while (stream.good()) {
        std::getline(stream, currentLine, delimiter);
        if (!currentLine.empty()) {
            splitString.push_back(trim(currentLine));
        }
    }

    return splitString;
}

string trim(const string& str)
{
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last-first+1));
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