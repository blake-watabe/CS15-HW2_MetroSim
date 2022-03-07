/* 
 * unit_tests.h
 * 
 * CS 15 homework 2
 * by Blake Watabe, October 2021
 * 
 * Uses Matt Russell's unit_test framework to test the Passenger and
 * PassengerQueue.
 */
 
 #include <cassert>
 #include "Passenger.h"
 #include "PassengerQueue.h"
 #include "MetroSim.h"
 #include <iostream>
 #include <fstream>
 #include <vector>
 #include <string>
 #include <sstream>
 
 using namespace std;
 
 /********************************************************************\
 *                       PASSENGER TESTS                        *
 \********************************************************************/
 /* default constructor test
  * Run the Passenger default constructor to make sure there are no runtime
  * errors or memory leaks
  */
void default_constructor_P()
 {
     Passenger testPassenger;
 }
 /* New Passenger constructor test
  * Run the Passenger default constructor to make sure there are no runtime
  * errors or memory leaks
  */
void new_passenger_constructor_P()
{
    int testID = 3;
    int testArrivalStation = 4;
    int testDepartureStation = 5;
    Passenger testPassenger(testID, testArrivalStation, testDepartureStation);
}
/* Passenger print test
 * Run to make sure that prints out the passenger to std out as specificied in
 * the spec
 */
void print_test_P()
{
    int testID = 1;
    int testArrivalStation = 2;
    int testDepartureStation = 3;
    Passenger testPassenger(testID, testArrivalStation, testDepartureStation);
    testPassenger.print(cout);
    //visual test to see if it matches
    cout << "This should be: " << "[" << 1 << ", " << 2 << "->" << 
    3 << "]" << endl;
}
/* Passenger print test 2
 * Run to make sure that prints out the passenger to std out as specificied in
 * the spec
 */
void print_test2_P()
{
    int testID = 20;
    int testArrivalStation = 15;
    int testDepartureStation = 4;
    Passenger testPassenger(testID, testArrivalStation, testDepartureStation);
    testPassenger.print(cout);
    //visual test to see if it matches
    cout << "This should be: " << "[" << 20 << ", " << 15 << "->" << 
    4 << "]" << endl;
}

/********************************************************************\
*                       PASSENGER QUEUE TESTS                        *
\********************************************************************/

/* default constructor test
 * Run the Passenger Queue default constructor to make sure there are no runtime
 * errors or memory leaks
 */
void default_constructor_PQ()
{
    PassengerQueue testPassenger;
}

//Was testing this for the autograder, but a test to print function
 void print_test_autograder_PQ()
 {
     //enqueue a blank queue with 1 passenger
     Passenger Passenger1(1,2,3);
     PassengerQueue testPassengerQueue;
     testPassengerQueue.enqueue(Passenger1);
     //add another
     Passenger Passenger2(2,3,4);
     testPassengerQueue.enqueue(Passenger2);
     Passenger1.print(cout);
     Passenger2.print(cout);
     // testPassengerQueue.enqueue(Passenger3);
     // testPassengerQueue.print(cout);
 }
/* front test
 * Run the front function to make sure that it returns the Passenger at the 
 * front of the queue
 */
void front_test_PQ()
{
    //enqueue a blank queue with 1 passenger
    Passenger Passenger1(1,2,3);
    PassengerQueue testPassengerQueue;
    testPassengerQueue.enqueue(Passenger1);
    //add another
    Passenger Passenger2(2,3,4);
    testPassengerQueue.enqueue(Passenger2);
    //front
    Passenger Passenger3 = testPassengerQueue.front();
    Passenger3.print(cout);
    // testPassengerQueue.enqueue(Passenger3);
    // testPassengerQueue.print(cout);
}
/* Size test
 * Run the size function to make sure that it returns the size of the queue
 */
void size_test_autograder_PQ()
{
     //enqueue a blank queue with 1 passenger
     Passenger Passenger1(1,2,3);
     PassengerQueue testPassengerQueue;
     testPassengerQueue.enqueue(Passenger1);
     //add another
     Passenger Passenger2(2,3,4);
     testPassengerQueue.enqueue(Passenger2);
     //return size
     testPassengerQueue.size();
} 
/* Size test
 * Run the size function to make sure that it returns the size of the queue
 */
void size_test_PQ()
{
     //enqueue a blank queue with 1 passenger
     Passenger Passenger1(1,2,3);
     PassengerQueue testPassengerQueue;
     testPassengerQueue.enqueue(Passenger1);
     //add another
     Passenger Passenger2(2,3,4);
     testPassengerQueue.enqueue(Passenger2);
     //return size
     int size = testPassengerQueue.size();
     cout << size << endl;
     cout << "This should be: 2 " << endl;
}
/* Size test 2
 * Run the size function to make sure that it returns the size of the queue
 * of an empty queue
 */
 void size_test2_PQ()
 {
     PassengerQueue testPassengerQueue;
     //return size
     int size = testPassengerQueue.size();
     cout << size << endl;
     cout << "This should be: 0 " << endl;
 }
/* Size test 3
 * Run the size function to make sure that it returns the size of the queue
 * of an empty queue
 */
void size_test3_PQ()
{
     PassengerQueue testPassengerQueue;
     Passenger Passenger1(1,2,3);
     testPassengerQueue.enqueue(Passenger1);
     //dequeue and take size
     testPassengerQueue.dequeue();
     //return size
     int size = testPassengerQueue.size();
     cout << size << endl;
     cout << "This should be: 0 " << endl;
}
/* Enqueue test
 * Run the Enqueue function to make sure that it adds a passenger to the back
 * of the queue
 */
void enqueue_test_PQ()
{
    //enqueue a blank queue with 1 passenger
    Passenger Passenger1(1,2,3);
    PassengerQueue testPassengerQueue;
    testPassengerQueue.enqueue(Passenger1);
    //add another
    Passenger Passenger2(2,3,4);
    testPassengerQueue.enqueue(Passenger2);

    testPassengerQueue.print(cout);
}
/* Enqueue test 2
 * Run the Enqueue function to make sure that it adds a passenger to the back
 * of a full queue
 */
void enqueue_test2_PQ()
{
    //enqueue a blank queue with 1 passenger
    Passenger Passenger1(1,2,3);
    PassengerQueue testPassengerQueue;
    testPassengerQueue.enqueue(Passenger1);
    //add another
    Passenger Passenger2(2,3,4);
    testPassengerQueue.enqueue(Passenger2);
    //add another
    Passenger Passenger3(3,12,1);
    testPassengerQueue.enqueue(Passenger3);

    testPassengerQueue.print(cout);
}
/* Dequeue test
 * Run the Dequeue function to make sure that it removes a passenger from the
 * front of a queue
 */
void dequeue_test_PQ()
{
    //dequeues a queue with 2 passengers
    Passenger Passenger1(1,2,3);
    PassengerQueue testPassengerQueue;
    testPassengerQueue.enqueue(Passenger1);
    //add another
    Passenger Passenger2(2,3,4);
    testPassengerQueue.enqueue(Passenger2);
    //dequeue
    testPassengerQueue.dequeue();
    //test to see if it worked
    testPassengerQueue.print(cout);
    cout << "This should be " << "[" << 2 << ", " << 3 <<
      "->" << 4 << "]" << endl;
}
/* Dequeue test 2
 * Run the Dequeue function to make sure that it removes a passenger from the
 * front of a queue of size 1
 */
void dequeue_test2_PQ()
{
    //dequeues a queue with 1 passenger
    Passenger Passenger1(1,2,3);
    PassengerQueue testPassengerQueue;
    testPassengerQueue.enqueue(Passenger1);
    //dequeue
    testPassengerQueue.dequeue();
    //test to see if it worked
    testPassengerQueue.print(cout);
    cout << "This should be: " <<  endl;
}
/* Dequeue test 3
 * Run the Dequeue function to make sure that it removes a passenger from the
 * front of a queue of size 0
 */
void dequeue_test3_PQ()
{
    //dequeues an empty queue
    PassengerQueue testPassengerQueue;
    //dequeue
    testPassengerQueue.dequeue();
    //test to see if it worked
    testPassengerQueue.print(cout);
    cout << "This should be: " <<  endl;
}
/* Print test
 * Run the print function to make sure that it prints the list of passengers
 * as specified in the spec
 */
 void print_test_PQ()
 {
     //enqueue a blank queue with 1 passenger
     Passenger Passenger1(1,2,3);
     PassengerQueue testPassengerQueue;
     testPassengerQueue.enqueue(Passenger1);
     //add another
     Passenger Passenger2(2,3,4);
     testPassengerQueue.enqueue(Passenger2);
     //print
     testPassengerQueue.print(cout);
     cout << "This should be: " << "[" << 1 << ", " << 2 <<
      "->" << 3 << "]" << "[" << 2 << ", " << 3 <<
       "->" << 4 << "]" << endl;
 }

/********************************************************************\
*                       METRO SIM TESTS                        *
\********************************************************************/
//standard MetroSim constructor;
void MetroSim_Constructor_test()
{
    MetroSim MetroSim;
}
//test to 
void MetroSim_Train_Print_test()
{
    MetroSim sim;
    sim.readStations("stations.txt");
    sim.print_station();
}

// //Test to print out the simulation after reading in stations file
void MetroSim_Sim_Print_test()
{
    MetroSim sim;
    sim.readStations("stations.txt");
    // sim.print_station();
    ifstream infile;
    //make a file and test
    string filename = "sample_commands.txt";
    infile.open(filename);

    if(! infile.is_open()){
        cerr << "Error: could not open file" << endl;
        exit(EXIT_FAILURE);
        }

    string line, i1, i2, i3;
    while(getline(infile, line)){
        stringstream s(line);
        s >> i1 >> i2 >> i3;

        if(i1 == "p"){
            sim.add_passenger_at_station(stoi(i2), stoi(i3));
        }

    }
    infile.close();
    //add passenger
    // sim.add_passenger_to_train(1,2);

    //check that the move train function can be called and train will loop
    // sim.move_train();
    
    //finally print sim
    sim.print_sim();
}
// // Same Simulation test but make sure it works with another stations file
void MetroSim_Sim_Print_test2()
{
    MetroSim sim;
    sim.readStations("second_stations_list.txt");
    // sim.print_station();
    ifstream infile;
    //make a file and test
    infile.open("sample_commands.txt");

    if(! infile.is_open()){
        cerr << "Error: could not open file" << endl;
        exit(EXIT_FAILURE);
        }
    string line, i1, i2, i3;
    while(getline(infile, line)){
        stringstream s(line);
        s >> i1 >> i2 >> i3;
        if(i1 == "p"){
            sim.add_passenger_at_station(stoi(i2), stoi(i3));
        }
    }
    infile.close();
    //add passenger
    // sim.add_passenger_to_train(1,2);

    //check that the move train function can be called and train will loop
    // sim.move_train();

    sim.print_sim();
}
//test to read in stations and test if the command file read function works
void MetroSim_Short_CommandFile_Print_test()
{
    MetroSim sim;
    sim.readStations("stations.txt");
    // sim.print_station();
    ofstream outfile;
    //make a file and test
    string filename = "sample_commands.txt";
    outfile.open("output.txt");

    if(! outfile.is_open()){
        cerr << "Error: could not open file " << endl;
        exit(EXIT_FAILURE);
        }

    sim.read_commandline(filename, outfile);
    // string line, i1, i2, i3;
    // while(getline(infile, line)){
    //     stringstream s(line);
    //     s >> i1 >> i2 >> i3;
    //     if(i1 == "p"){
    //         sim.add_passenger_at_station(stoi(i2), stoi(i3));
        // }
    outfile.close();
    //add passenger
    // sim.add_passenger_to_train(1,2);

    //check that the move train function can be called and train will loop
    // sim.move_train();
    // sim.move_train();
    // sim.move_train();

    //finally print sim
    sim.print_sim();
}
//test to read in stations and test if the command file read function works
void MetroSim_Commandfile_Sim_Print_test()
{
    MetroSim sim;
    ofstream outfile;
    string outfile_name = "output.txt";
    outfile.open(outfile_name);
    if(! outfile.is_open()){
        cerr << "Error: could not open file " << endl;
        exit(EXIT_FAILURE);
        }
    sim.readStations("stations.txt");
    //make a file and test
    string filename = "test_commands.txt";
    sim.read_commandline(filename, outfile);
    outfile.close();
    //finally print sim
    sim.print_sim();
}
