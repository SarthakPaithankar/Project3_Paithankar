#ifndef Player_h
#define Player_h
#include "Property.h"
using namespace std;
//This class creates and controls players and their properties
class Player
{
    public:
    //default constructor 
    Player();
    Player(string name,int money,Property properties[],bool jail,int position);// parameterized constructor

    //gets and sets name
    string getName();
    void setName(string name);
    
    //gets and sets money
    void setMoney(int money);
    int getMoney();
    
    //adds money for players
    void addMoney(int money);
    
    //removes money for players
    void removeMoney(int money);

    //prints all properties a player has
    void printAllProperties();

    int getNumProps();
    
    //gets and sets owned properties
    Property getProperty(int index);
    void setProperty(Property properties);
    void sellProp(int index);
    //gets and sets jail status
    bool getJail(string name);
    void setJail(string name);
    //gets and sets player position 
    int getPosition();
    void setPosition(int roll);

    void addHouse(int index);

    private:

    string name;
    int money;
    vector <Property> properties;
    bool jail;
    int position;
};
#endif