/*
 * MetroSim.h
 * 
 * COMP 15 homework 2
 * by Blake Watabe, Oct 2021
 * 
 * Stores a passenger queue vector as the train, as well as a passenger queue
 * vector to represent each station
*/

#ifndef _METROSIM_H_
#define _METROSIM_H_

#include "Passenger.h"
#include "PassengerQueue.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

// Put any other structs you need here

class MetroSim
{
    public:
        /* constructors */
        //standard Metrosim constructor
        MetroSim();
        
        void move_train(ofstream &output);
        
        //runs simulation
        void run(string file1, string file2);
        void run(string file1, string file2, string file3);
        
        //reading the station in function
        void readStations(string filename);
        void read_commandline(string commands_file, ofstream &output);
        //add a passenger at a station
        void add_passenger_at_station(int start, int end);
        void add_passenger_to_train(int id, int start, int end);
        
        //remove passenger from train
        void remove_passenger_from_train(ofstream &output);
        
        void command_loop(ofstream &output);
        
        void print_sim();
        void print_train();
        void print_station();
        
    private:
        
        //station struct
        struct Station
        {
            string name;
            int station_num;
            PassengerQueue stationQueue;
            
            Station()
            {
                name = " ";
            }
            Station(int new_name)
            {
                name = new_name;
            }
        };
        
        int number_of_stations;
        
        //vector of passenger queues, each index is a station
        vector<Station> stations;
        //vector of passenger queues, each index is a car sorted by destin.
        vector<PassengerQueue> train;
        int passenger_count;
        int train_index;
        
        

        
        



};

#endif
