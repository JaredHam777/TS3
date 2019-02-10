//
// Created by JaredHam777 on 11/3/2018.
//
#include "location.h"

#ifndef SFML_TEMPLATE_MATH_FUNCTIONS_H
#define SFML_TEMPLATE_MATH_FUNCTIONS_H
double magnitude(location a);

double angle(location a, location b);
double dot(location a, location b);
double distanceBetween(location a, location b);
location subtract(location a, location b);
location add(location a, location b);
#endif //SFML_TEMPLATE_MATH_FUNCTIONS_H
