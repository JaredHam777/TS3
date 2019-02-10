//
// Created by JaredHam777 on 11/3/2018.
//

#include "location.h"
#include <vector>

void randomizeLocations(vector<location>& locations, int min, int max)  //randomly assigns a vector of this class location's x and y values
{
    for(int i=0; i<locations.size(); i++)
    {
        locations[i].randomize(min, max);
    }
}
void initializeLocations(vector<location>& locations, int size)  //locations must be an empty list--fills the given list
{
    for(int i=0; i<size; i++)
    {
        location l;
        locations.push_back(l);
    }
}
