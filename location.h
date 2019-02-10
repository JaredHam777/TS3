//
// Created by JaredHam777 on 11/3/2018.
//
#include <random>
#include <ctime>
#include <vector>
using namespace std;
#ifndef SFML_TEMPLATE_LOCATION_H
#define SFML_TEMPLATE_LOCATION_H


class location {
public:
    double x;   //x position on the map
    double y;   //y position on the map
    void randomize(int min, int max)    //randomizes x and y, within specified range
    {
        x=rand()%(max-min)+min;
        y=rand()%(max-min)+min;
    }
    bool equals(location l)     //checks location equivalence according to their x and y values
    {
        if (x == l.x && y == l.y){ return true;}else{return false;}     //be careful with this, as it will consider two separate locations of the same coordinates equivalent
    }

};

void randomizeLocations(vector<location>&, int, int);
void initializeLocations(vector<location>&, int);
#endif //SFML_TEMPLATE_LOCATION_H
