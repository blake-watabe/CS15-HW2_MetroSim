/*
 * MetroSim.h
 * 
 * COMP 15 homework 2
 * by Blake Watabe, Oct 2021
 * 
 * Stores a passenger queue vector as the train, as well as a passenger queue
 * vector to represent each station
*/

#include "MetroSim.h"
#include "Passenger.h"
#include "PassengerQueue.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

/********************************************************************\
*                       Constructor                     *
\********************************************************************/

/* Purpose: initializes an empty Metrosim instance */
/* Arguments: none                                 */
/* Returns: none                                   */
MetroSim::MetroSim()
{
    //don't need to initialize trainor stations, have standard constructors
   passenger_count = 0;
   train_index = 1;
   number_of_stations = 0;
}

/********************************************************************\
*                              Run                                   *
\********************************************************************/
/* Description: Runs the simulation if only given 2 arguments */
/* Purpose: Runs the simulation                            */
/* Arguments: 2 file names                                 */
/* Returns: none                                           */
void MetroSim::run(string file1, string file2)
{
    //read in the stations from argv[1]
    readStations(file1);
    print_sim();
    //create an outfile to open argv[2]
    ofstream outfile;
    outfile.open(file2);
    //error checking
    if(! outfile.is_open()){
        cerr << "Error: could not open file " << endl;
        exit(EXIT_FAILURE);
        }
    //run the command loop
    // cout << "command?";
    // string i1,i2,i3;
    // cin >> i1 >> i2 >> i3;
    // while(i1 != "m" && i3 != "f"){
        command_loop(outfile);
    // }
    outfile.close();
}
/* Description: Runs the simulation if only given 3 arguments */
/* Purpose: Runs the simulation                            */
/* Arguments: 3 file names                                 */
/* Returns: none                                           */
void MetroSim::run(string file1, string file2, string file3)
{
    //read in the stations from argv[1]
    readStations(file1);
    //create an outfile to open argv[2]
    ofstream outfile;
    outfile.open(file2);
    //error checking
    if(! outfile.is_open()){
        cerr << "Error: could not open file " << endl;
        exit(EXIT_FAILURE);
    }
    //run the command file
    read_commandline(file3, outfile);
    outfile.close();
}

/********************************************************************\
*                              Reading files                      *
\********************************************************************/
/* Description: Read stations function */
/* Purpose: Function to read in and populate the number of stations */
/* as well the train                                                */
/* Arguments: a string for the file name                           */
/* Returns: none                                                   */
void MetroSim::readStations(string filename)
{
    //declare the ifstream
    ifstream filestream;
    //set the file name equal to the first argument in command line
    string stations_filename = filename;
    //open the file
    filestream.open(stations_filename);
    //error checking
    if(! filestream.is_open()){
        cerr << "Error: could not open file" << stations_filename << endl;
        exit(EXIT_FAILURE);
        }
        
    string station_name;
    //read through file
    while(getline(filestream, station_name)){
        number_of_stations++;
        //creates a new_station
        Station new_station;
        new_station.name = station_name;
        new_station.station_num = number_of_stations;
        //add number of stations
        stations.push_back(new_station);
        //add number of cars in train
        train.push_back(new_station.stationQueue);
        }
        
    //close file
    filestream.close();
}
/* Description: read commands function */
/* Purpose: function to read in the commands file          */
/* Arguments: a command file and output stream             */
/* Returns: none                                           */
void MetroSim::read_commandline(string commands_filename, ofstream &output)
{
    //declare the ifstream
    ifstream filestream;
    //set the file name equal to the third argument in command line
    //open the file
    string filename = commands_filename;
    filestream.open(filename);
    //error checking
    if(! filestream.is_open()){
        cerr << "Error: could not open file " << filename << endl;
        exit(EXIT_FAILURE);
        }
    
    string command, i1, i2, i3;
    while(getline(filestream, command)){
        stringstream s(command);
        s >> i1 >> i2 >> i3;
        if(i1 == "p"){
            add_passenger_at_station(stoi(i2), stoi(i3));
        }
        else if(i1 == "m" && i2 == "m"){
            move_train(output);
        }
        else if(i1 == "m" && i2 == "f")
        {
            cout << "Thanks for playing MetroSim. Have a nice day!" << endl;
            exit(EXIT_SUCCESS);
        }
        print_sim();
    }
    filestream.close();
}

/********************************************************************\
*                           Modifiers                   *
\********************************************************************/
/* Description: Add passenger at station function  */
/* Purpose: inserts a passenger at the station             */
/* Arguments: a command file and output stream             */
/* Returns: none                                           */
void MetroSim::add_passenger_at_station(int start, int end)
{
    //assign a sequential ID
    passenger_count++;
    int id = passenger_count;
    
    //create a new passenger with sequential ID,
    Passenger new_passenger(id,start,end);
    stations.at(start-1).stationQueue.enqueue(new_passenger);
}
/* Description: A function to move the train  */
/* Purpose: moves the train and adds/removes people from the train     */
/* Arguments: an output stream                                         */
/* Returns: none                                                       */
void MetroSim::move_train(ofstream &output)
{
    //Pick up passengers and place on train
    while(stations.at(train_index - 1).stationQueue.size()!= 0){
        int start = stations[train_index -1].stationQueue.front().from;
        // cerr << "start is" << start << endl;
        int end = stations[train_index -1].stationQueue.front().to;
        // cerr << "end is" << end << endl;
        int iD = stations[train_index -1].stationQueue.front().id;
        add_passenger_to_train(iD, start, end);
        }
        
    //Increment train index, loop back to one if over 26
    train_index++;
    if(train_index > number_of_stations){
        train_index = train_index % number_of_stations;
    }
    
    //Remove passengers from train
    while(train.at(train_index - 1).size() != 0){
        remove_passenger_from_train(output);
    }
    
}
/* Description: A function to add a passenger to the train  */
/* Purpose: moves the train and adds/removes people from the train     */
/* Arguments: 3 integers: the passenger id, start station, end station */
/* Returns: none                                                       */
void MetroSim::add_passenger_to_train(int id, int start, int end)
{
    //dequeue from station
    stations.at(start-1).stationQueue.dequeue();
    //enqueue on train
    Passenger p(id, start, end);
    // if(train_index == start){
        train.at(end-1).enqueue(p);
    // }
}
/* Description: A function to remove a passenger to the train  */
/* Purpose: removes people from the train     */
/* Arguments: an output stream */
/* Returns: none  */
void MetroSim::remove_passenger_from_train(ofstream &output)
{
    //condition if train index matches station number
    for(int i = 0; i < number_of_stations; i++){
        if(train_index - 1 == i){
            while(train[i].size() != 0){
                output << "Passenger " << train[i].front().id <<
                 " left train at station " << stations.at(i).name 
                 << endl;
                //dequeue from station
                train.at(i).dequeue();
            }
        }
    }
}
/********************************************************************\
*                           Command Loop                             *
\********************************************************************/
/* Description: A function to run a command loop if there is no command file */
/* Purpose: takes in input from the command line and executes function     */
/* Arguments: an output stream */
/* Returns: none  */
void MetroSim::command_loop(ofstream &output)
{
    string command, i1, i2, i3;
    cout << "Command? ";
    while(getline(cin, command)){
        stringstream s(command);
        s >> i1 >> i2 >> i3;
        if(i1 == "p"){
            add_passenger_at_station(stoi(i2), stoi(i3));
            print_sim();
            command_loop(output);
        }
        else if(i1 == "m" && i2 == "m"){
            move_train(output);
            remove_passenger_from_train(output);
            print_sim();
            command_loop(output);
        }
        else if(i1 == "m" && i2 == "f")
        {
            cout << "Thanks for playing MetroSim. Have a nice day!" << endl;
            exit(EXIT_SUCCESS);
        }
    }
}


/********************************************************************\
*                           PRINT                                    *
\********************************************************************/
/* Description: A function to print out the simulation */
/* Arguments: none */
/* Returns: none   */
void MetroSim::print_sim()
{
    cout << "Passengers on the train: "; print_train();
    cout << endl;
    print_station();
}
/* Description: A function to print out the train */
/* Arguments: none */
/* Returns: none   */
void MetroSim::print_train()
{
    cout << "{";
    int train_size = train.size();
    for(int i = 0; i < train_size; i++)
    {
        train.at(i).print(cout);
    }
    cout << "}";
}
/* Description: A function to print out the stations */
/* Arguments: none */
/* Returns: none   */
void MetroSim::print_station()
{
    for(int i = 0; i < number_of_stations; i++){
        if(i == train_index - 1){
            cout << "Train: ";
        }
        else
        cout << "       ";
        cout << "[" << i + 1 << "] " << stations[i].name;
        //print out queues
        cout << " {";
        stations.at(i).stationQueue.print(cout);
        cout << "}";
        cout << endl;
    }
}

