//
// Created by JaredHam777 on 11/3/2018.
//

#include "math functions.h"
double magnitude(location a)
{
    return (sqrt(pow(a.x,2)+pow(a.y, 2)));
}

double angle(location a, location b)
{
    return (acos(dot(a,b)/(magnitude(a)*magnitude(b))));
}
double dot(location a, location b)  //dot product formed by two locations from origin
{
    return (a.x*b.x + a.y*b.y);
}

double distanceBetween(location a, location b)
{
    return magnitude(subtract(a,b));
}

location subtract(location a, location b)   //subtract a from b. ex: (b-a)
{
    location c;
    c.x = b.x-a.x;
    c.y = b.y - a.y;
    return  c;
}

location add(location a, location b)
{
    location c;
    c.x = a.x + b.x;
    c.y = a.y + b.y;
    return  c;
}
