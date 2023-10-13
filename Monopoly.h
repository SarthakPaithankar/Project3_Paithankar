#ifndef Monopoly_h
#define Monopoly_h
#include "Property.h"
#include "Player.h"
#include "chance.h"
#include "Die.h"

using namespace std;

//This class uses text files to create Properties and chance cards with values in file

class Monopoly
{
    public:
    //default constructor 
    Monopoly();
    //makes properties by using property text file
    void makeProperties(Property M[44]);
    //return property at a index
    Property getProperty(int index);
    //makes chance cards by using chance text file
    void makeChance(chance C[16]);
    //gets gets at an index
    chance getChance(int index);
   
    private:
    //array of properties
    Property map_properties[44];
    //array of players
    Player players[4];
    //array of chance cards
    chance cards[16];

};
#endif