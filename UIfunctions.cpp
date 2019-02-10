//
// Created by JaredHam777 on 11/3/2018.
//

#include "UIfunctions.h"
using namespace std;

void printLocation(location l, bool endline)    //e.g. "(17,41)"
{
    if(endline){cout<<"("<<l.x<<", "<<l.y<<")"<<endl;}
    else{cout<<"("<<l.x<<", "<<l.y<<")";}
}

void printGroupLocations(vector<location> locations)    //prints a series of above separated by commas
{
    for(int i=0; i<locations.size(); i++)
    {
        printLocation(locations[i], false);
        cout<<", ";
    }
    cout<<endl;
}