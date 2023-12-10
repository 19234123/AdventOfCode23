#include "Functions.h"

string filePath = R"(C:\Dev\Text_files\input.txt)";

int main() {
    vector<string> rawInput = readFile(filePath);

    int x = std::stoi("-1");


    long long totalValue = 0;
    for (const auto& line: rawInput) {
        vector<int> splitLine = splitLineToInt(line, ' ');

        long long nextInt = getNextSequenceValue(splitLine);
        totalValue += nextInt;
    }

    cout << totalValue;
    return 0;
}