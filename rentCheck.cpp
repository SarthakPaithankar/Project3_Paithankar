#include "Property.h"
#include "chance.h"
#include "Player.h"
#include "Die.h"
#include <iostream>
using namespace std;
/*
declares all variables
if property is unavailable
 for loop runs for length of property array that player holds
 if player that rolls hold the property then player_own is set to true
if player own is true
 for loop iterates through players
  for loops iterates through player properties
   if property name is equal to the property the player is on 
    target_player is set to the index of player and loop is broken
 prompts player which player owns the property and how much they need to pay  
 remove the rent amount from the player and return true
else return false 
*/

bool rentCheck(Player player[4],int turn,Property properties[44]){
    //declares all variables
    int numPlayer=0; bool player_own=false; int target_player=0;
    //if property is unavailable
    if(properties[player[turn].getPosition()].get_availability()==false){
        //for loop runs for length of property array that player holds
        for(int i=0;i<32;i++){
            //if player that rolls hold the property then player_own is set to true
            if(player[turn].getProperty(i).get_Name()==properties[player[turn].getPosition()].get_Name()){
                player_own=true;
            }
        }
    }
    //checks which player own the property
    if(!player_own){
        //for loop iterates through players
        for(int i=0;i<4;i++){
            //for loops iterates through player properties
            for(int j=0;j<32;j++){
                //if property name is equal to the property the player is on 
                if(player[i].getProperty(j).get_Name()==properties[player[turn].getPosition()].get_Name()){
                    //target_player is set to the index of player and loop is broken
                    target_player=i;
                    break;
                }
            }
        }
        //prompts player which player owns the property and how much they need to pay
        cout << player[target_player].getName() <<" owns this property"<<endl;
        cout <<"You need to pay "<<player[target_player].getName()<< " $"<<properties[player[turn].getPosition()].get_Rent()<<endl;
        //remove the rent amount from the player and return tru
        player[turn].removeMoney(properties[player[turn].getPosition()].get_Rent());
        player[target_player].addMoney(properties[player[turn].getPosition()].get_Rent());
        cout<< "You have $"<<player[turn].getMoney()<< " and are at "<< properties[player[turn].getPosition()].get_Name()<<endl;
        return true;
    }
    return false;
}