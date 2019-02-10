//Title: Final Project: Traveling Salesman
//Author: Jared Hamilton
//Date: 11/3/2018
//Note: Class files (location and Map) do not designate all their functions in its cpp file, as I had not yet learned the common educate of separate header and cpp files for classes.

//Classes:
//  Location
//      Description: represents each location on a 2D map, as per the setting of the TSP problem.
//      Note: I should have named this class "Point", as that naming convention cooperates with many of the algorithms in this program.
//  Map
//      Description: represents the virtual canvas the locations are to be plotted on.
//Source Files:
//  myAlgorithms
//      Description: The more abstract operations that are applied to the lists of locations.
//  UIfunctions
//      Description: customized console output commands, aids in debugging.
//
//  math functions
//      Description: Advanced mathematical operations that I was too lazy to import.  Mostly 2D vector operations.





#include <iostream>
#include <random>
#include <ctime>
#include "location.h"
#include "UIfunctions.h"
#include <vector>
#include "drawingFunctions.h"
#include "Map.h"
#include "myAlgorithms.h"
using namespace std;

#include <SFML/Graphics.hpp>
using namespace sf;

int main() {
    int numLocations;   //number of locations to randomly generate

    //introduction
    cout<<"Welcome to my Traveling Salesman solver!  If you have not done so yet, please read my final project proposal for more information."<<endl;
    cout<<"Enter the number of points (positive integer) you want me to randomly plot on the canvas, and I'll plot a sub-optimal route, according to my heuristic solving abilities. Note: anything over 1000 will take longer than ~10 seconds"<<endl;
    cout<<"Number of points:"<<endl;
    cin>>numLocations;  //user enters number of locations

    srand(time(0));


    vector<location> testLocations;
    Map testMap;
    testMap.initializeRenderWindow(1000,1000,"Test Map");   //opens testMap's render window

    initializeLocations(testLocations, numLocations); //fills list "testLocations" with location instances
    randomizeLocations(testLocations, 0, 1000);     //assigns each item's location's coordinates to a random value that fits the render window
    testMap.allLocations=testLocations;
    testMap.innerLocs=testLocations;
    testMap.getCenter();    //gets the averaged center of across the range placements of each location in testMap.allLocations





    drawLocations(testMap.allLocations,  testMap.renderWindow, 10);     //see drawLocations function in Map.h


    bool done = testMap.drawOuterPath();
    while(!done){done = testMap.drawOuterPath();}
    //draws whole outer path
    done = false;
    while(!done){ done = testMap.addInnerPoint();}




    drawCircuit(testMap.containingLocations, testMap.renderWindow, 4);
    testMap.renderWindow.display();




    cout<<"Done! you can see the route I plotted in the render window."<<endl;
    cout<<"Here is the circuit's order of locations: "<<endl;

    printGroupLocations(testMap.containingLocations);

    while(testMap.renderWindow.isOpen()) {
        //mainWindow.display();
        Event event;
        while( testMap.renderWindow.pollEvent(event) ) {
            if( event.type == Event::Closed ) {
                testMap.renderWindow.close();
            }

        }
    }






    return EXIT_SUCCESS;                        // report our program exited successfully
}