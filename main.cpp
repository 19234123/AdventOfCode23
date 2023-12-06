#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>
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

    // Get seed numbers
    vector<string> seedNumbers = splitLineToString(rawInput[0], ' ');
    seedNumbers.erase(seedNumbers.begin());
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

    /*
     * seedtosoilmap
     * soiltofertilizermap
     * fertilizertowatermap
     * watertolightmap
     * lighttotemperaturemap
     * temperaturetohumiditymap
     * humiditytolocationmap
     */

    // Setup range maps
    std::unordered_map<string, ConversionMap*> rangeMaps;
    for (const auto& range: inputRanges){
        string mapName = strip(range[0], {' ', ':', '-'});
        auto *conversionMap = new ConversionMap(range);
        rangeMaps[mapName] = conversionMap;
    }

    long long lowestLocation = LONG_LONG_MAX;
    //Seed 79, soil 81, fertilizer 81, water 81, light 74, temperature 78, humidity 78, location 82.
    for (const auto& seedString: seedNumbers){
        long long seed, soil, fertilizer, water, light, temperature, humidity, location;
        seed = std::stoll(seedString);

        soil = rangeMaps["seedtosoilmap"]->getMapValue(seed);
        fertilizer = rangeMaps["soiltofertilizermap"]->getMapValue(soil);
        water = rangeMaps["fertilizertowatermap"]->getMapValue(fertilizer);
        light = rangeMaps["watertolightmap"]->getMapValue(water);
        temperature = rangeMaps["lighttotemperaturemap"]->getMapValue(light);
        humidity = rangeMaps["temperaturetohumiditymap"]->getMapValue(temperature);
        location = rangeMaps["humiditytolocationmap"]->getMapValue(humidity);

        cout << "Seed " << seed << ", " << "soil " << soil << ", " << "fertilizer " << fertilizer << ", "
             << "water " << water << ", " << "light " << light << ", " << "temperature " << temperature << ", "
             << "humidity " << humidity << ", " << "location " << location << "." << endl;

        if (location < lowestLocation){
            lowestLocation = location;
        }

        //Seed 79, soil 81, fertilizer 81, water 81, light 74, temperature 78, humidity 78, location 82.
    }
    cout << "Lowest location: " << lowestLocation;

    return 0;
}