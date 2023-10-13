#include "map.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <random>
using namespace std;

/*
declares all variables
randomize the map vector 
for loop runs for the size of the map vector
 if S is found then set i to start
 if J is found then set i to jail
swap S so its at index 0 in the vector
swap J so it is at index 11 in vector
*/
Map::Map(){
    //declares all variables
    int count=0;
    int start=0;
    int jail=0;
    //Vector with all interactable spaces on map
    board_property = {'C','+','+','+','+','+','+','+','P','+','+','P','+','+','+','T','+','+','+','+','C','+','+','C','+','+','P','+','T','+','+','+','J','+','+','T','+','+','+','+','C','+','+','S'};
    //randomizes the vector 
    shuffle(board_property.begin(),board_property.end(),default_random_engine(time(0)));
    //for loop runs for the size of the map vector
    for(int i=0;i<board_property.size();i++){
        //if S is found then set i to start
        if(board_property[i]=='S') start = i;
        //if J is found then set i to jail
        if(board_property[i]=='J') jail = i;
    }
    //swap S so its at index 0 in the vector
    swap(board_property[start],board_property[0]);
    //swap J so it is at index 11 in vector
    swap(board_property[jail],board_property[11]);
    //32 properties, 3 Parking, 4 Chances, 3 Tax, 1 Jail, 1 start,
};

/*
for loop runs for first 12 indexes of map vector 
 Print row 0 of map 12 across 
end
for loop runs for 10 indexes of map vector 
 Print last 10 indexes on far left and 12-22 on right of map
end
for loop runs for middle 12 indexes in vector
 prints out bottom row of vector
end
*/
void Map ::displayMap(){
    //for loop runs for first 12 indexes of map vector 
    for(int i=0;i<12;i++){
        //Print row 0 of map 12 across 
        cout << setw(2) <<board_property[i];
    }
    cout <<endl;
    //for loop runs for 10 indexes of map vector 
    for(int i=0;i<10;i++){
        //Print last 10 indexes on far left and 12-22 on right of map
        cout << setw(2)<<board_property[43-i] <<"                     " <<board_property[12+i]<<endl;
    }
    //runs for middle 12 indexes in vector
    for(int i=33;i>21;i--){
        //prints out bottom row of vector
        cout <<setw(2)<<board_property[i];
    }
    cout <<"\n";
}

//returns the map vector 
vector <char> Map ::getBoard(){
    return board_property;
} 


