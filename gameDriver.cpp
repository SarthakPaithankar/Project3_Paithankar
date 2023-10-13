#include "Property.h"
#include "Player.h"
#include "Die.h"
#include "Monopoly.h"
#include "chance.h"
#include "player_order.cpp"
#include "merchantMenu.cpp"
#include "makeProperties.cpp"
#include "specialSpaces.cpp"
#include "game_win.cpp"
#include "rentCheck.cpp"
#include "map.h"
#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <fstream>
#include <random>

using namespace std;

//Prompts start menu
void menu()
{
    cout <<"=============MONOPOLY=============="<<endl;
    cout <<"Destroy the competition. Own it all"<<endl;
    cout << "Enter 1 to start game"<<endl;
    cout <<"Enter 2 to read game rules"<<endl;
    cout << "Enter 3 to view the leaderboard"<<endl;
    cout <<"Enter 4 to quit"<<endl;

}
//Prompts game menu
void game_menu()
{
    cout << "=============MONOPOLY==============" << endl;
    cout <<"Enter 1 to roll die"<<endl;
    cout << "Enter 2 to talk to merchant" <<endl;
    cout << "Enter 3 to View your Properties"<<endl;
    cout << "Enter 4 to end your turn" <<endl;
}
/*
Declare all variables
Make properties and chance cards with Monopoly class
randomize the map vector
while loop runs turn player inputs 4 or game_On is false
 Propmpt menu
 if input is 1 prompt player for number of player and username
  do while loop till Player enters valid number of players
  store and set usernames
  turn on game
  Order players in play order
 if input is 2 then rules of the game are outputted
 if input is 3 then output the leaderboard
 if input is 4 then exit the game
while loop initiates when Game_on is true and runs till gameWon is true
 calculate player turn
 prompt player their money and whose turn it is
 get menu and display the map
 if game input is 1 the roll the die
  set player position
  prompt player what they rolled and prompt space they landed on
  check if the player landed on a special tile else ouput normal menu
  if player lands on a chance tile then special output is displayed
  if player lands on a Park tile then special output is displayed
  if player lands on a Jail tile then special output is displayed
if player input is 2 then display the merchant
if player input is 3 then all properties that the player owns are displayed
if player input is 4 then end the current player turn by incrementing turn
if gameWon is true and there is only one person left then game ends
 for loop iterates through all players
 if a player has greater than 0 money then winner is set to i
*/

int main()
{
    //Declare all variables
    srand(time(0));
    Player players[4]; Monopoly M; Property properties[44]; Map m; chance chance_cards[16]; Die jail_prob; int n; bool has_rolled=false; int temp=false;
    ofstream leader;
    //Make properties and chance cards with Monopoly class
    M.makeProperties(properties); M.makeChance(chance_cards);
    //randomize the map vector
    randomizeProperties(properties,m.getBoard());
    string input=""; string game_Input="*";  int turn=0;
    int count=1; 
    int num=0; int num_roll=0;
    bool game_On=false;  bool gameWon=false;
    string num_players=""; 
    ifstream input_file; string line2; string line; ifstream input_file1; string arr[4]; string Username; 
    //while loop runs turn player inputs 4 or game_On is false
    while(input !="4" || game_On==false)
    {
        //Propmpt menu
        menu();
        getline(cin,input);
        //if input is 1 prompt player for number of player and username
        if(input=="1"){
            //do while loop till Player enters valid number of players
            do{
            cout << "Please Enter number of players. You can have between 2 and 4 players."<<endl;
            getline(cin,num_players);
            if(stoi(num_players)!=2&&stoi(num_players)!=3&&stoi(num_players)!=4) cout << "Enter valid input"<<endl;
            }while(stoi(num_players)!=2&&stoi(num_players)!=3&&stoi(num_players)!=4);
            do{
                cout<< "Please enter a username for Player "<< count <<endl;
                getline(cin,Username);
                //store and set usernames
                arr[num]=Username;
                players[num].setName(Username);
                count++; num++;
            }while(count <stoi(num_players)+1);
            //Order players in play order
            playerOrder(stoi(num_players),players);
            //turn on game
            game_On=true;
            break;
        }
        //if input is 2 then rules of the game are outputted
        else if(input =="2"){
            input_file.open("rules.txt");
            while(getline(input_file,line)){
                cout << line <<endl;
            }
        }
        //if input is 3 then output the leaderboard
        else if(input=="3"){
            input_file1.open("leaderboard.txt");
            while(getline(input_file1,line2)){
                cout << line2<<endl;
            }
        //if input is 4 then exit the game
        }else if(input=="4")
        {
            cout << "Goodbye!"<<endl;
            break;
        }
    }
    //while loop initiates when Game_on is true and runs till gameWon is true
    while(game_On&&!gameWon)
    {
        temp=false;
        //calculate player turn
        turn=(turn)%stoi(num_players);
        //prompt player their money and whose turn it is
        cout<<"========================="<<endl;
        if(!temp){
            cout<< "Its is now "<<players[turn].getName()<<"'s turn"<<endl;
            cout<< "You have $"<<players[turn].getMoney()<< " and are at "<< properties[players[turn].getPosition()].get_Name()<<endl;
        }
        if(players[turn].getMoney()<0){
            gameWon=true;
            num_players="1";
        }
        //prompt the game menu
        game_menu();
        getline(cin,game_Input);
        //get menu and display the map
        m.displayMap();
        //if game input is 1 the roll the die
        if((game_Input=="1"&&!has_rolled)||game_Input=="*"){
            Die d;
            num_roll=d.dieRoll();
            cout<<"========================="<<endl;
            cout<< "Its is now "<<players[turn].getName()<<"'s turn"<<endl;
            cout<< "You have $"<<players[turn].getMoney()<< " and are at "<< properties[players[turn].getPosition()].get_Name()<<endl;
            //set player position
            players[turn].setPosition(2);
            has_rolled=true;
            //prompt player what they rolled and prompt space they landed on
            cout<< "you rolled a "<< num_roll<<endl;
            //check if the player landed on a special tile else ouput normal menu
            if(has_rolled&&!properties[players[turn].getPosition()].get_availability()){
            temp=rentCheck(players,turn,properties);
            }
            //if player lands on a chance tile then special output is displayed
            if(properties[players[turn].getPosition()].get_Name()=="Chance"){
                players[turn].setMoney(chanceSpace(properties[players[turn].getPosition()],chance_cards,players[turn])); turn++; 
                has_rolled=false;
            }
            //if player lands on a Tax tile then special output is displayed
            if(properties[players[turn].getPosition()].get_Name()=="Tax"){
                players[turn].removeMoney(taxSpace(players[turn])); turn++;  
                has_rolled=false; 
            }
            //if player lands on a Park tile then special output is displayed
            if(properties[players[turn].getPosition()].get_Name()=="Park"){
                parkSpace(turn); turn++;  
                has_rolled=false;
            }
            //if player lands on a Jail tile then special output is displayed
            if(properties[players[turn].getPosition()].get_Name()=="Jail"){
                n=jail_prob.randomness_calc(2);  
                if(n==1){
                    jail(); turn++;
                }else{
                cout << "Thanks for visiting. You can now continue your game.You can continue your game" << endl;
                }
                has_rolled=false;
            }
        //if player input is 2 then display the merchant
        }else if (game_Input=="2"){
            merchantMenu(turn,players, properties);
        //if player input is 3 then all properties that the player owns are displayed
        }else if (game_Input=="3"){
            players[turn].printAllProperties(); 
        //if player input is 4 then end the current player turn by incrementing turn
        }else if (game_Input=="4"){
            turn++;
            has_rolled=false;
        //if player input
        }else{
            if(game_Input!="*") cout <<"Invalid Input"<<endl;
        }
    }
    //if gameWon is true and there is only one persin left then game ends
    if(gameWon&&stoi(num_players)==1){
        int winner=0;
        //for loop iterates through all players
        for(int i=0;i<4;i++){
            //if a player has greater than 0 money then winner is set to i
            if(players[i].getMoney()>0) winner=i;
            break;
        }
        cout <<"Congrats You have Won"<<endl;
        win(players[winner].getName());
    }
}