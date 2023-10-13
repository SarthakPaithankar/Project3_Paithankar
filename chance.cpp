#include <iostream>
#include <fstream>
#include "Property.h"
#include "chance.h"
using namespace std;
//Defaiult contstructor sets all string to "" and ints to 0
chance :: chance(){
    card="";
    value=0;
    luck=" ";
};
//Parameterized contructor set the values of the card to given values
chance::chance(string card1,int value1,string luck1){
    card=card1;
    value=value1;
    luck=luck1;
};
//returns the string output of card
string chance :: getcard(){
    return card;
};
//returns the in value of amount to be added or subtracted
int chance :: getvalue(){
    return value;
};
//return the determinator from card
string chance :: getluck(){
    return luck;
};
