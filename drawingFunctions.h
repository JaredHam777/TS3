//
// Created by JaredHam777 on 11/3/2018.
//
#include <vector>
#include "location.h"
#include <string>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#ifndef SFML_TEMPLATE_DRAWINGFUNCTIONS_H
#define SFML_TEMPLATE_DRAWINGFUNCTIONS_H
void drawLocations(vector<location>, RenderWindow&, int size);
void initializeWindow(Vector2u, string, RenderWindow&);
void connectOuterPoints(vector<location>, RenderWindow&);
void drawLine(location a, location b, RenderWindow&, int thickness);
void drawCircuit(vector<location> locations, RenderWindow&, int thickness);
#endif //SFML_TEMPLATE_DRAWINGFUNCTIONS_H
