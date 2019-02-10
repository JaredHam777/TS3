//
// Created by JaredHam777 on 11/3/2018.
//

#include <vector>
#include "location.h"
#include "myAlgorithms.h"
#include <SFML/Graphics.hpp>
#include "UIfunctions.h"
#ifndef SFML_TEMPLATE_MAP_H
#define SFML_TEMPLATE_MAP_H

using namespace sf;
class Map {
public:
    location center;    //average of the point's ranges (sorta like a centroid, but not by definition)
    vector<location> allLocations;  //All Location instances seen on the map
    vector<location> containingLocations;   //Initially the outer convex polygon, converges into innerLocs throughout execution process
    vector<location> exclusionLocs;     //dynamically updated list of points to exclude in certain steps
    vector<location> innerLocs;     // AllLocations excluding containingLocations


    int outerPathIteration = 0;
    RenderWindow renderWindow;


    void getCenter()
    {
        center = findCenter(allLocations);
    }

    void initializeRenderWindow(unsigned int w, unsigned int h, string displayName)
    {
        renderWindow.create(VideoMode(w,h), displayName);
    }
    bool drawOuterPath()
    {
        if(containingLocations.size()<1)
        {
            location l = findFurthestLoc(allLocations, center);
            containingLocations.push_back(l);
            innerLocs.erase(innerLocs.begin()+indexOf(l, innerLocs));
        }
        updateExclusionLocs();
        location l = greatestAngle(allLocations, containingLocations[containingLocations.size()-1], center, exclusionLocs, containingLocations);
        containingLocations.push_back(l);

        outerPathIteration+=1;
        if(containingLocations[0].equals(containingLocations[containingLocations.size()-1])){return true;}
        else{innerLocs.erase(innerLocs.begin()+indexOf(l, innerLocs)); return false;}

    }
    bool addInnerPoint()    //returns true if all inner points have been added
    {
        if(innerLocs.size()>0) {
            location l = findNextInnerLoc(containingLocations, innerLocs);
           // findNextInnerLoc(containingLocations, innerLocs, allLocations);
            //cout << "added location: ";
            //printLocation(l, true);
            return false;
        } else{ return true;}

    }
    void updateExclusionLocs()
    {
        exclusionLocs.clear();
        exclusionLocs.push_back(containingLocations[containingLocations.size()-1]);
        if(containingLocations.size()>1){exclusionLocs.push_back(containingLocations[containingLocations.size()-2]);}
    }



};


#endif //SFML_TEMPLATE_MAP_H
