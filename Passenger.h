/*
 * Passenger.cpp
 * 
 * COMP 15 homework 2
 * by Blake Watabe, Oct 2021
 * 
 * One implementation of the Passenger class. Stores a unique sequential 
 * passenger ID number (starting at 1), as well as an arrival station and a
 * departure station. 
 */

#ifndef __PASSENGER_H__
#define __PASSENGER_H__

#include <iostream>
using namespace std;

/* Description: A passenger struct to store ID, from station, to station */
struct Passenger
{

        int id, from, to;
        
        Passenger()
        {
                id   = -1;
                from = -1;
                to   = -1;
        }

        Passenger(int newId, int arrivalStation, int departureStation)
        {
                id   = newId;
                from = arrivalStation;
                to   = departureStation;
        }
        //print function to print out passenger as specified in spec
        void print(ostream &output);

};

#endif
