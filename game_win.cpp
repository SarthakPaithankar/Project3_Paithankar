#include <iostream>
#include <fstream>
using namespace std;
/*
initialize variable
open file
write given string to file
*/
void win(string name){
    //initialize variable
    ofstream won;
    //open leaderboard file and store given name
    won.open("leaderboard.txt");
    won<<name<<".\n"<<endl;
    won.close();
}