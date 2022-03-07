/*
 * Passenger.cpp
 * 
 * COMP 15 homework 2
 * by Blake Watabe, Oct 2021
 * 
 * Stores a unique sequential passenger ID number (starting at 1), as well as 
 * an arrival station and a departure station. 
*/

#include <iostream>
#include <string>
#include "Passenger.h"

using namespace std;

/* Description: A function to print out the passenger
/* Arguments: none */
/* Returns: none   */
void Passenger::print(std::ostream &output)
{
        //print passenger information to the output stream as
        //described in the homework specification
        output << "[" << id << ", " << from << "->" << to << "]";
}
