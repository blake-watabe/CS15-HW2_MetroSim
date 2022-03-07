/*
 * PassengerQueue.h
 * 
 * COMP 15 homework 2
 * by Blake Watabe, Oct 2021
 * 
 * One implementation of the queue data structure. Will hold a vector containing
 * passengers
 */
 
 #ifndef __PASSENGER_QUEUE_H__
 #define __PASSENGER_QUEUE_H__
 
 #include "Passenger.h"
 #include <iostream>
 #include <vector>
 
 using namespace std;
 
 class PassengerQueue {
    public:
        /* constructors */
        //standard PassengerQueue constructor
        PassengerQueue();
    
        /* non-modifying functions */
        //function to return the passenger at front of queue
        Passenger front();
        //function to return size of the Queue
        int size();
        //function to print the passengers in the queue
        void print(ostream &output);
        //function to remove the passenger at the front of the queue
        
        /* modifying functions */
        void dequeue();
        //function to add a passenger at the back of the queue
        void enqueue(const Passenger &new_passenger);
        
    private:
        //vector of passengers
        vector<Passenger> passengerQueueVector;
        
 };
 
 #endif