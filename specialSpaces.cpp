#include "Property.h"
#include "chance.h"
#include "Player.h"
#include "Die.h"
#include <iostream>
using namespace std;
/*
prompt for tax tile
returns 5% of players money
*/
int taxSpace(Player player){
    //prompts player
    cout << "Uncle Sam wants his allowance. Pay 5% of your liquid savings."<<endl;
    //returns 5% of player money
    return (player.getMoney()*.05);
}

/*
initialize variables
Use die object to create random num from 0-16
do while loop until player inputs 1
 prompt player for chance card
if input is 1 then chance card with index of random num is returned
if the chance card is postive money is added to player
if car is negative money is removed according to money specified in chance and amount in returned
*/
int chanceSpace(Property property,chance chance[16],Player player){
    //initialize variables
    Die c; int roll=0;  string s_input="";
    //Use die object to create random num from 0-16
    roll=c.randomness_calc(16);
    //do while loop until player inputs 1
    do{
        //prompt player for chance card
        cout <<"You have landed on a Chance card! Roll the die to get a random chance card."<<endl;
        cout <<"Press 1 to roll the Die"<<endl;
        getline(cin,s_input);
    }while(s_input!="1");
    //if input is 1 then chance card with index of random num is returned
    if(s_input=="1"){
        cout << chance[roll].getcard()<<endl;
    }
    //if the chance card is postive money is added to player
    if(chance[roll].getluck()=="+"){
        //add money with integer in chance card and return the value
        player.addMoney(chance[roll].getvalue());
        return player.getMoney();
    }else{
        //money is removed according to money specified in chance and amount in returned
        player.removeMoney(chance[roll].getvalue());
        return player.getMoney();
    }
}
/*
do while loop that runs till player enters 5
  prompts player park menu
player turn is changed
*/
void parkSpace(int turn){
    string p_input="";
    cout <<"Enjoy a relaxing turn at the park"<<endl;
    //do while loop that runs till player enters 5
    do{
    cout <<"Press 5 to end your turn"<<endl;
    getline(cin,p_input);
    }while(p_input!="5");
    //change player turn
    turn++;
}
//Prompts the jail tile
void jail(){
    cout << "You're in jail. Your turn will be skipped." << endl;
}

