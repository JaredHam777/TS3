//
// Created by JaredHam777 on 11/3/2018.
//

#include "location.h"
#include <vector>
#include "math functions.h"
#include <iostream>
#include "UIfunctions.h"
using namespace std;
#ifndef SFML_TEMPLATE_MYALGORITHMS_H
#define SFML_TEMPLATE_MYALGORITHMS_H

location findCenter(vector<location> locations);
location findFurthestLoc(vector<location> locations, location center);
bool vectorContains(vector<location>, location);
location greatestAngle(vector<location>, location activeLoc, location center, vector<location> exLocs, vector<location> outerLocs);
location findNextInnerLoc(vector<location>& containingLocs, vector<location>& innerLocs);

int indexOf(location loc, vector<location> locations);


#endif
