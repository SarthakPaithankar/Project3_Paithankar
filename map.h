#ifndef Map_H
#define Map_H
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
//This class creates and randomizes the board that will be used for the game
class Map
{
private:
    //Map vector
    vector <char> board_property;
    
public:
    //creates map
    Map();
    //returns map vector
    vector<char> getBoard();
    //displays the map on screen
    void displayMap();
};

#endif