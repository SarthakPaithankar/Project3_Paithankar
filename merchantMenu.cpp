#include "Property.h"
#include "Player.h"
#include "map.h"
#include "Die.h"
using namespace std;
// Prints out the Prompt for merchant menu
// Uses arguments to print out unique value for menu do each player
void displayMerchant(int turn,Player players[4], Property properties[44]){
    cout <<"===========MERCHANT==========="<<endl;
    cout <<"=="<<properties[players[turn].getPosition()].get_Name()<<"=="<<"Property price:$" <<properties[players[turn].getPosition()].get_property_price() << "==" << endl;
    cout << "Hello customer! I can help you with buying or selling your properties!"<<endl;
    cout << "Press 1 to sell your properties."<<endl;
    cout <<"Press 2 to buy this property."<<endl;
    cout <<"Press 3 to build on a property"<<endl;
    cout <<"Press 4 to exit."<<endl;
}
/*
declare variables
do while loop runs till the user inputs 4
 display menu and cin input
 if input is 1 Menu for selling properties is displayed
   if player has any properties to sell
    print out all properties the player owns
    do while loop till player enter 0
     prompt player to sell property
     remove property from the player's property array and sets it available for resale
     adds money from property sale to player 
 end
 if input is 2 Menu for buying properties is displayed
  if property is for sale
   if player has enough money to buy the property
    remove money from player
    set the property as unavailble for sale
    set property into player's property array
   else player cant buy property
  else player cant buy property
 else player cant buy property
 end
 if input is 3 Menu for buying houses is displayed
   
  
*/
void merchantMenu(int turn,Player players[4], Property properties[44]){
    //declare variables
    int chance=0; 
    Die d; 
    Property temp; 
    int count=0;  int counter=0; 
    //user inputs
    string user="";  bool sum=false; string sell=""; string house;
    chance=d.randomness_calc(10);
    //do while loop runs till the user inputs 4
    do{
    //display menu and cin input
    displayMerchant(turn, players, properties);
    getline(cin,user);
    //Menu for selling properties
    if(user=="1"){
        //checks if player has any properties to sell
        if(players[turn].getNumProps()==0){
            cout << "You don't have any properties to sell!"<<endl;
        }else{
            //print out all properties the player owns
            cout<<"You own the following properties"<<endl;
            players[turn].printAllProperties();
            //do while loop till player enter 0
            do{
            //prompt player to sell property
            cout << "Enter the number of the property you would like to sell. Press 0 to exit menu"<<endl;
            getline(cin,sell);
            if(sell!="0"){
                //sells property by removing property from the player's property array and sets it available for resale
                properties[players[turn].getPosition()].set_availability(false);
                players[turn].sellProp(stoi(sell)-1);
                //adds money from property sale to player 
                players[turn].addMoney(properties[players[turn].getPosition()].get_property_price());
                cout <<players[turn].getMoney()<<endl;
            }
            }while(sell!="0"&&players[turn].getNumProps()>0);
        }

    }
    //menu for buying properties
    else if(user=="2"){
        //checks if property is for sale
        if (properties[players[turn].getPosition()].get_availability()==false){
            cout <<"Someone owns this property already!"<<endl;
        }//check if player has enough money to buy the property
        else if(players[turn].getMoney()>=properties[players[turn].getPosition()].get_property_price()){
            //remove money from player
            if(properties[players[turn].getPosition()].get_Name()!="Start"&&properties[players[turn].getPosition()].get_Name()!="Jail"){
            players[turn].removeMoney(properties[players[turn].getPosition()].get_property_price());
            cout <<properties[players[turn].getPosition()].get_Name()<<endl;
            cout <<"You have $"<<players[turn].getMoney()<<endl;
            //set the property as unavailble for sale
            properties[players[turn].getPosition()].set_availability(true);
            //set property into player's property array
            players[turn].setProperty(properties[players[turn].getPosition()]);
            cout << "You have successfully bought this property"<<endl;
            }else{
                cout<< "This property is not for sale"<<endl;
            }
        }else{
            cout<< "You dont have enough money to buy this property"<<endl;
        }
    //menu to build on property
    }else if(user=="3"){
        if(players[turn].getNumProps()>0){
        do{
        cout<<"Which property would you like to build on? Press 0 to exit"<<endl;
        players[turn].printAllProperties();
        getline(cin,house);
        if(house !="0"){
            players[turn].addHouse(stoi(house)-1);
            properties[players[turn].getPosition()].set_num_House();
            properties[players[turn].getPosition()].set_Rent(players[turn].getProperty(stoi(house)-1).get_num_House());
            players[turn].getProperty(stoi(house)-1).set_price_house(players[turn].getProperty(stoi(house)-1).get_num_House());
        }
        }while(house!="0");
        }else{cout <<"You dont own any Properties"<<endl;}

    }else if(user=="4"){
        cout <<"Thanks for visiting!"<<endl;
    }
    }while(user!="4");
}
