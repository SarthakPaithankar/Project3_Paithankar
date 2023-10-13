#include "Property.h"
#include "Player.h"
#include "Die.h"
#include "Monopoly.h"
#include <iostream>
using namespace std;

/*
initialize all variables
for loop iterates through every index in Board
 finds all instance of C and stores their indexes in chance array
 finds all instance of T and stores their indexes in tax array
 finds all instance of P and stores their indexes in park array
for loop iterates through every index in Properties
 swaps all instances of chance with indexes stored in chance array so they have the same index of C in map array
 swaps all instances of tax with indexes stored in tax array so they have the same index of T in map array
 swaps all instances of park with indexes stored in properties array so they have the same index of P in map array
Sets start to index 0 in properties array
Sets start to index 11 in properties array
*/
void randomizeProperties(Property properties[44],vector <char> board){
    //initialize all variables
    int chance[4]; int tax[3]; int park[3]; 
    //counters
    int park_count=0; int tax_count=0; int test=0; int tester=0; int test1=0;  int chance_count=0;
    //finds all instance of C and stores their indexes in chance array
    for(int i=0;i<44;i++){
        if(board[i]=='C'){ 
            chance[chance_count]=i;
            chance_count++;
        }
    //finds all instance of T and stores their indexes in tax array
        if(board[i]=='T'){
            tax[tax_count]=i;
            tax_count++;
        }
    //finds all instance of P and stores their indexes in park array
        if(board[i]=='P'){
            park[park_count]=i;
            park_count++;
        }
    }
    //swaps all instances of chance so they have the same index of C in map array
    for(int i=0;i<44;i++){
        if(properties[i].get_Name()=="Chance"&&test<4){
            swap(properties[i],properties[chance[test]]);
            test++;
        }
    //swaps all instances of tax so they have the same index of T in map array
        if(properties[i].get_Name()=="Tax"&&tester<3){
            swap(properties[i],properties[tax[tester]]);
            tester++;
        }
    //swaps all instances of park so they have the same index of P in map array
        if(properties[i].get_Name()=="Park"&&test1<3){
            swap(properties[i],properties[park[test1]]);
            test1++;
        }
    //Sets start to index 0 in properties array
        if(properties[i].get_Name()=="Start"){
            swap(properties[i],properties[0]);
        }
    //Sets start to index 11 in properties array
        if(properties[i].get_Name()=="Jail"){
            swap(properties[i],properties[11]);
        }
    }
}