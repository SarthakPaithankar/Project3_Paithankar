#include <iostream>
#include <fstream>
#include "Property.h"
using namespace std;
    //default constructor
    Property :: Property()
    {
        rent_price=0;
        Property_name="";
        property_price=0;
        num_house=0;
        price_House=0;
        available=true;
    };
    //creates sets variables to properties
    Property :: Property(int rent_p,string property_n,int property_p,int num_houses,int p_house,bool availability)
    {
        rent_price=rent_p;
        Property_name=property_n;
        property_price=property_p;
        num_house=num_houses;
        price_House= p_house;
        available=availability;
    };
    
    //Gets and sets rent
    int Property ::  get_Rent()
    {
        return rent_price;
    };
    //sets rent price according to number of houses on property
    void Property :: set_Rent(int house)
    {
        if(house==1)
        {
            rent_price=(rent_price*1.25);
        }
        else if(house==2)
        {
            rent_price=(rent_price*1.5);
        }else if(house==3)
        {
            rent_price=(rent_price*2);
        }  
    };
    //Gets and sets property name
    string Property :: get_Name()
    {
        return Property_name;
    };

    //gets and sets property price
    int Property :: get_property_price()
    {
        return property_price;
    };
    void Property :: set_property_price()
    {

    };
    
    //gets num of houses on property
    int Property :: get_num_House()
    {
        return num_house;
    };
    void Property :: set_num_House()
    {
        if(num_house < 3)
        {
           num_house++; 
        }
        else
        {
            cout << "You already have the max number of houses!" <<endl;
        }
    };

    int Property :: get_price_house()
    {
        return price_House;
    };

    //sets the price for the houses
    void Property :: set_price_house(int house)
    {
        if(house==1)
        {
            rent_price=(rent_price*1.25);
            price_House=(price_House*1.25);
        }
        else if(house==2)
        {
            rent_price=(rent_price*1.5);
            price_House=(price_House*1.5);
        }else if(house==3)
        {
            rent_price=(rent_price*2);
            price_House=(price_House*2);
        }
    };
    
    //checks if property is available
    bool Property ::  get_availability()
    {
        return available;
    };

    void Property :: set_availability(bool bought)
    {
        if(bought){
            available=false;
        }else if(bought==false){
            available=true;
        }
    };
