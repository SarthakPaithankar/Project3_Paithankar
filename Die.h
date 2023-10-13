#ifndef Die_h
#define Die_h
#include "Property.h"
#include "Player.h"
#include "Die.h"

#include <iostream>
/*
Creates dies that roll a number between 1 and 6 inclusive
also creates a random number generator that generates a # between 0 and number given
*/
class Die{
    public:
    Die(); //Defaullt constructor
    //~Die();  //Destructor
    int dieRoll(); //generates a number between 1 an 6 inclusive
    int randomness_calc(int max_num); //creates a random number generator that generates a # between 0 and number given

    private:
    int max_value;  //upper bound for number generation
    int result; //random num returned
    int random_result;  //resul of randomness_calc
};
#endif