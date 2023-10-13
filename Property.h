#ifndef Property_h
#define Property_h
#include "map.h"
#include <string>
using namespace std;
/*
This is the class the controls Properties for player and the map
*/
class Property
{
    public:
    Property(); //Default constructor
    Property(int rent_p,string property_n,int property_p,int num_houses,int p_house,bool available); //parameterized constructor
    
    //Gets and sets rent
    int get_Rent(); 
    void set_Rent(int house);
    
    //gets property names
    string get_Name();
    
    //get and sets property price
    int get_property_price();
    void set_property_price();
    
    //gets and sets num of houses on property

    int get_num_House();
    void set_num_House();

    //gets and sets house prices
    int get_price_house();
    void set_price_house(int house_);

    //gets and set availabilty
    bool get_availability();
    void set_availability(bool bought);

    protected:
    int rent_price;  //rent price of the property
    string Property_name;  //Property name
    int property_price;  //property price
    int num_house;  //number of houses on property
    int price_House;  // price to build a house
    bool available;  //availability of property
};
#endif