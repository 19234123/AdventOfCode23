
#ifndef ADVENTOFCODE23_FUNCTIONS_H
#define ADVENTOFCODE23_FUNCTIONS_H
#include <string>
#include <vector>
#include <map>
#include <unordered_set>
using std::string;
using std::vector;

struct Node {
    string name;
    Node* left;
    Node* right;
};

vector<string> readFile(const string& filePath);
vector<string> splitLineToString(const string& line, const char& delimiter);
vector<int> splitLineToInt(const string& line, const char& delimiter);
vector<long long> splitLineToLongLong(const string& line, const char& delimiter);
string trimWhitespace(const string& input);
string stripCharacters(const string& input, const std::unordered_set<char>& charsToRemove);
void setRange(const vector<string>& rangeData, std::map<long long, long long>& map);
vector<long long> quickSort(vector<long long> numbers);
bool binarySearch(const vector<long long>& sortedArray, long long target);

#endif //ADVENTOFCODE23_FUNCTIONS_H