#ifndef chance_h
#define chance_h
#include <string>
using namespace std;
//This class controls chance cards 
class chance{
    public:
    //default chance constructor 
    chance();
    //paramerterized chance constructor
    chance(string card,int value,string luck);
    //returns ouput of chance card
    string getcard();
    //gets the value of the chance card that will either be deducted or added to player money
    int getvalue();
    //gets the determinator which decide if the card is good or bad
    string getluck();
    //chance getCard();

    private:
    //ouput of chance card
    string card;
    //value that will be dedeucted or added
    int value;
    // determinate that decided if card is good or bad
    string luck;
};
#endif