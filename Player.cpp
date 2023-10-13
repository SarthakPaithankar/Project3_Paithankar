#include "Property.h"
#include "Player.h"
#include <vector>
#include <iostream>
using namespace std;
    //Default Constructor sets all values to "",false,0 , and money is set to 1500
    Player :: Player()
    {
        
        name="";  money=1500;
        for (int i=0;i<32;i++){
            properties.push_back(Property(0,"",0,0,0,false));
        }
        jail=false;  position=0;
    };
    //Parameterized Constructor sets Player values to given parameters
    Player::Player(string name1,int money1,Property properties1[],bool jail1,int position1){
        name=name1;   money=money1;
        for(int i=0;i<32;i++){
            properties.push_back(properties1[i]);
        }
        jail=jail1;   position=position1;
    };
    //returns name of player
    string Player :: getName(){
        return name;
    };
    //sets player name
    void Player :: setName(string name_){
        name=name_;
    };
    //Gets player money
    int Player :: getMoney(){
        return money;
    };
    //adds money to player
    void Player:: addMoney(int amount){
        money+=amount;
    }

    //removes money from player
    void Player:: removeMoney(int amount){
        money-=amount;
    }
    void Player:: setMoney(int amount){
        money=amount;
    }
    //prints all properties player has
    void Player :: printAllProperties(){
        //iterates through players properties array and prints all bought properties
        for(int i=0;i<32;i++){
            if(properties[i].get_Name()!=""){
                cout<< i+1<<". " << properties[i].get_Name() << endl;
            }
        }
    } 
    
    //gets property in property array
    Property Player :: getProperty(int index)
    {
        return properties[index];
    };
    
    //sets property
    void Player :: setProperty(Property Property)
    {
        //iterates through players properties array and sets property at next available index
        for(int i=0;i<32;i++){
            if(properties[i].get_Name()==""){
                properties[i]={Property};
                //breaks after property is set
                break;
            }
        }
    };
    //sets sold property as blank
    void Player :: sellProp(int index){
        properties[index]={Property(0,"",0,0,0,false)};
    }

    int Player :: getNumProps(){
        int count=0;
        //iterates through players properties array and return the number of props a player owns
        for(int i=0;i<32;i++){
            if(properties[i].get_Name()!="") count++;
        }
        return count;
    }

    //gets player jail status
    bool Player :: getJail(string name)
    {
        return false;
    };
    //sets player jail status
    void setJail(string name);
    //gets player position
    int Player :: getPosition()
    {
        return position;
    };
    //sets player position
    void Player :: setPosition(int roll){
        position+=roll;
        //if position is greater than 44 its is set to 0 and recounted from 0
        if(position>44){
            position=(position-44);
            money+=200;
        }
    };
    //Adds a house for a property that a player holds
    void Player :: addHouse(int i){
        properties[i].set_num_House();
    }