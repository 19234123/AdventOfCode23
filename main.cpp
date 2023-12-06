#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <list>
#include <unordered_map>
#include "Functions.h"
#include "ConversionMap.h"

using std::vector;
using std::list;
using std::string;
using std::cout;
using std::endl;

string filePath = R"(C:\Dev\Text_files\input.txt)";

int main() {
    vector<string> rawInput = readFile(filePath);

    // Get seed ranges
    vector<string> seedRanges = splitLineToString(rawInput[0], ' ');
    seedRanges.erase(seedRanges.begin());
    rawInput.erase(rawInput.begin(),rawInput.begin()+2);

    // Get input mapRanges
    vector<vector<string>> inputRanges;
    vector<string> currentRange;
    for (const auto& line: rawInput){
        if (!line.empty()) {
            currentRange.push_back(line);
        } else {
            inputRanges.push_back(currentRange);
            currentRange.clear();
        }
    }
    inputRanges.push_back(currentRange);

    // Setup range maps
    std::unordered_map<string, ConversionMap*> rangeMaps;
    for (const auto& range: inputRanges){
        string mapName = strip(range[0], {' ', ':', '-'});
        auto *conversionMap = new ConversionMap(range);
        rangeMaps[mapName] = conversionMap;
    }

    long long maxLowestLocation = 400000000;
    bool found = false;
    for (long long location=0; location<maxLowestLocation; location++) {
        long long seed, soil, fertilizer, water, light, temperature, humidity;

        if (location % 1000000 == 0){
            cout << "Count(millions): " << location/1000000 << endl;
        }

        humidity = rangeMaps["humiditytolocationmap"]->getReverseMapValue(location);
        temperature = rangeMaps["temperaturetohumiditymap"]->getReverseMapValue(humidity);
        light = rangeMaps["lighttotemperaturemap"]->getReverseMapValue(temperature);
        water = rangeMaps["watertolightmap"]->getReverseMapValue(light);
        fertilizer = rangeMaps["fertilizertowatermap"]->getReverseMapValue(water);
        soil = rangeMaps["soiltofertilizermap"]->getReverseMapValue(fertilizer);
        seed = rangeMaps["seedtosoilmap"]->getReverseMapValue(soil);

        for (long long i=0; i<seedRanges.size(); i+=2){
            long long minSeed = std::stoll(seedRanges[i]);
            long long maxSeed = minSeed + std::stoll(seedRanges[i+1])-1;

            if (seed>=minSeed && seed<=maxSeed){
                cout << "Seed " << seed << " found at location " << location << endl;
                found = true;
                break;
            }
        }

        if (found){
            break;
        }
    }

    return 0;
}