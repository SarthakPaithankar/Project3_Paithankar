#include "Property.h"
#include "Player.h"
#include "Die.h"
#include <ctime>
#include <iostream>
using namespace std;
//Default constructor sets max value to 6 and other integers to 0
Die :: Die()
{
    max_value=6;
    result=0;
    random_result=0;
};

/*
set result equal to random num mod 6 plus 1
*/
int Die ::dieRoll()
{
    result=rand()%max_value+1;
    return result;
};
/*
set random_result equal to random num mod number given plus 1
*/
int Die:: randomness_calc(int max_num){
    random_result=rand()%max_num;
    return random_result;
}
