//
// Created by JaredHam777 on 11/3/2018.
//

#include "drawingFunctions.h"



void drawLocations(vector<location> locations, RenderWindow& rw, int size)  //draws the vertices on rw
{
    for(int i=0; i<locations.size(); i++)
    {
        Vertex v;
        v.position.x = static_cast<int>(locations[i].x);
        v.position.y = static_cast<int>(locations[i].y);
        rw.draw(&v, size, Points);
    }

}


void drawLine(location a, location b, RenderWindow& rw, int thickness)  //draws line on rw according to specifications
{
    Vertex vA;
    Vertex vB;
    vA.position.x= static_cast<int>(a.x);
    vA.position.y=static_cast<int>(a.y);
    vB.position.x=static_cast<int>(b.x);
    vB.position.y=static_cast<int>(b.y);
    Vertex line[] = {vA, vB};
    rw.draw(line, thickness, Lines);


}

void drawCircuit(vector<location> locations, RenderWindow& rw, int thickness)//draws a hamiltonian circuit on rw based on the order of locations, with the beginning and end forming a connection
{
    unsigned long long int s = locations.size();
    for(int i=0; i<locations.size(); i++)
    {
        drawLine(locations[i%s], locations[(i+1)%s], rw, thickness);
    }
}