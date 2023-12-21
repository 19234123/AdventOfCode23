#ifndef ADVENTOFCODE23_MIRRORLANDSCAPE_H
#define ADVENTOFCODE23_MIRRORLANDSCAPE_H
#include "Functions.h"

class MirrorLandscape {
public:
    vector<string> gridRows;
    vector<string> gridColumns {};
    int rowMirrorIndex = -1;
    int rowMatches = 0;
    int columnMirrorIndex = -1;
    int columnMatches = 0;
    int gridValue = 0;

    explicit MirrorLandscape(vector<string>& grid);
    void generateColumns();
    void processList(const vector<string> &list, bool rows);
    void calculateGridValue();


};


#endif //ADVENTOFCODE23_MIRRORLANDSCAPE_H
