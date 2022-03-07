/*
 * PassengerQueue.cpp
 * 
 * COMP 15 homework 2
 * by Blake Watabe, Oct 2021
 * 
 * Queue data structure that stores passenger in a FIFO order. Will use a 
 * std::vector library, which allows me to use a variety of functions. Member
 * variables will be a vector that holds Passenger objects. Member functions 
 * will include: 1) Passenger Queue, which will add a passenger to the back of 
 * the queue, 2) a Passenger Dequeue, which will remove a passenger in FIFO 
 * order, 3) a Front function that will return the passenger at the front of
 * the queue, 4) a Size function that will return the size of the queue,
 * 5) a print function that will print to the outstream the entire queue
 */
 
 #include <iostream>
 #include <string>
 #include <fstream>
 #include "PassengerQueue.h"
 #include "Passenger.h"
 #include <vector>
 
 using namespace std;
 
 /********************************************************************\
 *                       Constructor                     *
 \********************************************************************/

/* Purpose: initializes an empty PassengerQueue */
 PassengerQueue::PassengerQueue()
 {
    //no need for anything since vector library has standard constructor
 }
 
 /********************************************************************\
 *                       Non-modifying functions               *
 \********************************************************************/
 
 /* Purpose: returns the passenger at the front of the queue */
 Passenger PassengerQueue::front()
 {
     if(passengerQueueVector.size() == 0)
     {
         cerr << "Error: cannot return front of empty vector" << endl;
         exit(EXIT_FAILURE);
     }
     else
     return passengerQueueVector.front();
 }
 
/* Purpose: prints out the list of passengers in the queue */
 void PassengerQueue::print(ostream &output)
 {
     int size = passengerQueueVector.size();
     for(int i = 0; i < size; i++)
     {
         passengerQueueVector[i].print(output);
     }
 }
 
/* Purpose: function to return the size of the vector (passenger queue) */
int PassengerQueue::size()
{
    int size = passengerQueueVector.size();
    return size;
}

/********************************************************************\
*                       Modifying functions               *
\********************************************************************/

/* Purpose: removes the passenger at the front of the queue*/
void PassengerQueue::dequeue()
{
    if(passengerQueueVector.size() >= 1)
    {
        passengerQueueVector.erase(passengerQueueVector.begin());
    }
    else
    return;
}

/* Purpose: removes the passenger at the front of the queue*/
void PassengerQueue::enqueue(const Passenger &new_passenger)
{
    passengerQueueVector.push_back(new_passenger);
}


 
