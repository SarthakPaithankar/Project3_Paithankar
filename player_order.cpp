#include <iostream>
#include "Property.h"
#include "Player.h"
#include "Die.h"
#include <ctime>
using namespace std;
/*
while loop runs till all player roll die
  if player enters 1 
    A die object is called with rollDie to generate number between 1-6
  Two vector with all rolls are filled
vect is sorted in ascending order
 Nested for loops creates array with players names in order and change the players array so its in order of turns
Player turns are printed in order
*/
void playerOrder(int num_players,Player players[4])
{
    //Declares all variables
    int count =0;  int counter=0;  //counter variables
    int roll=0; int input=0; //roll and player input variables
    vector <int> vect; vector <int> temp; //Vectors that hold rolls that will be sorted
    string arr[4];  string arr_temp[4];  string places[4]={"first","second","third","fourth"}; 
    cout << "Each Player needs to roll the die to determine player order(Lowest roll goes first)"<<endl;
    while(count<num_players){
        Die d; //Die object
        do{ //Propmpts player to enter 1 to roll
        cout << "Press 1 to roll a die"<<endl;
        cin >>input;
        if(input!=1){ //checks for valid input
            cout << "Invalid input. " << players[0].getName()<< " needs to roll a die to continue!" << endl;
        }
        }while(input!=1);
        if(input==1){
            roll=d.dieRoll();
        }
        cout << players[count].getName() << " rolled a " << roll <<endl;
        //stores rolls in vectors
        vect.push_back(roll);
        temp.push_back(roll);
        //stores player names in arr_temp
        arr_temp[count]=players[count].getName();
        count++;
    }
    //sorts vector in ascending order
    sort(temp.begin(),temp.end());
    //Checks for largest number and sets that number to 10000 and sets arr[i] to username of player with greatest roll
    for(int i=0;i<num_players;i++){
        for(int j=0;j<num_players;j++){
            if(temp[i]==vect[j]){
                vect[j]=10000;
                arr[i]=arr_temp[j];
                break;
            }
        }
    }
    //while counter is less than num of players
    while(counter<num_players){
        //prints player and there turn
        cout << arr[counter] << " is " << places[counter] <<endl;
        //sets players array in order
        players[counter].setName(arr[counter]);
        counter++;
    }
}
