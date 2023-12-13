#include "Functions.h"
#include "SequenceProcessor.h"

string filePath = R"(C:\Dev\Text_files\input.txt)";

int main() {
    vector<string> rawInput = readFile(filePath);

    vector<SequenceProcessor*> sequencesToProcess;
    for (const auto& line: rawInput) {
        vector<string> splitLine = splitLineToString(line, ' ');
        vector<int> springsInSequence = splitLineToInt(splitLine[1], ',');

        sequencesToProcess.push_back(new SequenceProcessor(splitLine[0], springsInSequence));
    }

    long totalArrangements = 0;
    for (const auto& sequence: sequencesToProcess) {
        totalArrangements += sequence->arrangements;
    }

    cout << totalArrangements << endl;
 return 0;
}