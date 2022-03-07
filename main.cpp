/*
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include "MetroSim.h"

using namespace std;

int main(int argc, char *argv[])
{
    //initialize a metro sim
    MetroSim sim;
    //pre-simulation, user types in on command line
    //error message if arguments is greater than 4 or less than 3
    if(argc < 3 || argc > 4){
        cerr << "Usage: ./Metrosim stationsFile outputFile [commandsFile]" <<
        endl;
        exit(EXIT_FAILURE);
    }
    //run if the number of files is only 2
    if(argc == 3){
        sim.run(argv[1], argv[2]);
    }
    //run if the number of files is 3
    else if(argc == 4){
        sim.run(argv[1], argv[2], argv[3]);
    }
    
}

