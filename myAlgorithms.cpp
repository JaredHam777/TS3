//
// Created by JaredHam777 on 11/3/2018.
//

#include "myAlgorithms.h"

using namespace std;


location findCenter(vector<location> locations)
{
    double minX = 2000; //arbitraly large number
    double minY = 2000; //same
    double maxX = 0;
    double maxY = 0;


    for(int i=0; i<locations.size(); i++)
    {
        if(locations[i].x > maxX){maxX = locations[i].x; }
        if(locations[i].x < minX){minX = locations[i].x; }
        if(locations[i].y > maxY){maxY = locations[i].y; }
        if(locations[i].y < minY){minY = locations[i].y; }
    }
    location l;
    l.x = (minX + maxX)/2;
    l.y = (minY + maxY)/2;
    return l;

}

location findFurthestLoc(vector<location> locations, location center)   //finds the furthest location from the center
{
    double maxDist = 0;
    location returnLoc;

    for(int i=0; i<locations.size(); i++)
    {
        double d = distanceBetween(locations[i], center);
        if(d>maxDist){maxDist = d; returnLoc=locations[i];}
    }

    return returnLoc;
}

bool vectorContains(vector<location> locations, location l)     //returns true if vector contains l
{

    for(int i=0; i<locations.size(); i++)
    {
        if(locations[i].equals(l)){ return true;}
    }
    return false;
}

location greatestAngle(vector<location> allLocs, location activeLoc, location center, vector<location> exLocs, vector<location> outerLocs)  //very hard to describe.  A step used in finding the outer convex polygon
{
    location bass = subtract(activeLoc, center);
    location prev;
    if(outerLocs.size()>1){prev = subtract(activeLoc, outerLocs[outerLocs.size()-2]);}

    location maxAngleLoc;
    double maxAngle =0;
    for(int i=0; i<allLocs.size(); i++)
    {
        location p = allLocs[i];
        if(!vectorContains(exLocs, p))
        {
            location arm = subtract(activeLoc, p);
            double armBassAngle = angle(arm, bass);
            double bassPrevAngle = 360;  //arbitrarily high value
            double armPrevAngle = 360; //same as above
            if(outerLocs.size()>1){bassPrevAngle = angle(bass, prev); armPrevAngle=angle(arm,prev); }
            if(armBassAngle>maxAngle && bassPrevAngle <= armPrevAngle){maxAngle=armBassAngle; maxAngleLoc = p; }
        }
    }
    return maxAngleLoc;


}

location findNextInnerLoc(vector<location>& containingLocs, vector<location>& innerLocs)    //containingLocs analyzes innerLocs to see which point to extend to with the lowest distance cost
{
    double Mincost = 2000;     //arbitrarily high number
    location returnLoc;
    int placementIndex=0;

    for(int i=0; i<containingLocs.size(); i++)
    {
        location a = containingLocs[i];
        location b = containingLocs[(i+1)%containingLocs.size()];
        double subtractedDist = distanceBetween(a,b);

        for(int j=0; j<innerLocs.size(); j++)
        {
            if(!innerLocs[j].equals(a) && !innerLocs[j].equals(b))
            {
                double distA = distanceBetween(a, innerLocs[j]);
                double distB = distanceBetween(b, innerLocs[j]);
                double cost = (distA + distB)-subtractedDist;
                if(cost < Mincost){Mincost = cost; returnLoc = innerLocs[j]; placementIndex=i; }

            }
        }
    }
    containingLocs.insert(containingLocs.begin()+placementIndex+1, returnLoc);
    innerLocs.erase(innerLocs.begin()+indexOf(returnLoc, innerLocs));
    return returnLoc;

}





int indexOf(location loc, vector<location> locations)   //returns the number placement value (index) of loc within locations
{
    for(int i=0; i<locations.size(); i++)
    {
        if(locations[i].equals(loc)){return i;}
    }
    return -1;
}