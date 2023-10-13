#include "Property.h"
#include "Player.h"
#include "chance.h"
#include "Monopoly.h"
#include <iostream>
#include <fstream>
/*
declare all count variables
for loop counts number of times seperator appears
if occurence is 0 the string is set to array 0 and 1 is returned
if occurence is greater than 0 for loop is entered
if seperator is equal to string [i] a substring is created and entered into an array
num is incremented by 1 and start of substring is set to i+1
end if
if the last occurence is reached the process of making a substring is repeated
end if
end if
end for
if occurence is greater or equal to array size then num_index=0; is returned
else num_index is returned
end if
else return 0;
*/
int split(string input_string,char separator,string arr[],int arr_size)
{
    //array index
    int num_index=0;
    //start of subtring
    int start=0;
    //num of times seperator appears
    int occurence=0;
    //checks if string is empty
    if(!input_string.empty())
    {
        //checks numbers of appearences of seperator
        for(int i=0;i<input_string.length();i++)
        {
            if(input_string[i]==separator)
            {
                occurence++;
            }
        }
        //returns 0 if seperator doesn't appear
        if(occurence==0)
        {
            arr[0]=input_string;
            return 1;
        }else 
        //Algorithms which splits string if seperator is found and stores in array
        if(occurence>0)
        {
            if(occurence>=arr_size)
            {
                return -1;
            }
            for(int j=0;j<=input_string.length();j++)
            {
                if(separator==input_string[j])
                {
                    arr[num_index]=input_string.substr(start,(j-start));
                    num_index++;
                    start=j+1;
                    if(occurence+1==num_index+1)
                    {
                        //stores last string
                        arr[num_index]=input_string.substr(start,(j-start)-1);
                        num_index++;
                    }
                }
            }
            //checks if arrau is large enough to fit all substrings
    
                return num_index;
        }
    }else
    {
        return 0;
    }
    return 0;
}

//sets all players, property, and chance int to 0, string =""
Monopoly::Monopoly()
{
    for(int i=0;i<44;i++)
    {
        map_properties[i]=Property(0,"",0,0,0,true);
    }
    for(int j=0;j<4;j++)
    {
        players[j]=Player("",0,map_properties,false,0);
    }
    for(int i=0;i<16;i++)
    {
        cards[i]=chance("",0,"");
    }
};
//returns property at given index
Property Monopoly::getProperty(int index)
{
    return map_properties[index];
}

/*
declare all variables
while loop runs till end of file
 getline gets all lines in properties file
 splits line into 4 indexes
 store Property with split values to M array
close file
*/
void Monopoly :: makeProperties(Property M[44])
{
    //declare all variables
    ifstream input_file;
    input_file.open("Properties.txt");
    string arr[4];
    char seperator=',';
    string line;
    int count=0;
    //while loop runs till end of file
    while(!input_file.eof())
    {
        //getline gets all lines in properties file
        getline(input_file,line);
        //splits line into 4 indexes
        split(line,seperator,arr,4);
        //split: name,price,$perhouse,Rent
        //Property: rent,name,price,num_houses,price_house,availability
        //store Property with split values to M array
        M[count]={(Property(stoi(arr[3]),arr[0],stoi(arr[1]),0,stoi(arr[3]),true))};
        count++;
    }
    //close file
    input_file.close();
};
//return chance at given index
chance Monopoly::getChance(int index)
{
    return cards[index];
}
/*
declare all varibles
while loop runs till array is filled
 get line gets all text line form file
 splits line into 3 indexes
 store chance array with chance object with split values
close file
*/
void Monopoly :: makeChance(chance C[16])
{
    //declare all varibles
    ifstream inputf; string liner; int end=0;
    inputf.open("chance.txt");
    string arr2[3];
    char seperator1=',';
    int test=0;
    //while loop runs till array is filled
    while(!inputf.eof()&&end<16){
        //get line gets all text line form file
        getline(inputf,liner);
        //splits line into 3 indexes
        split(liner,seperator1,arr2,3);
        //store chance array with chance object with split values
        //Chance: string ouput(You get $200), integer value(200), string determinate(+,-)
        C[end]=chance(arr2[0],stoi(arr2[1]),arr2[2]);
        end++;
    }
    //close file
    inputf.close();
}

