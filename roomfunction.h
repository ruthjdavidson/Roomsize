#ifndef ROOMFUNCTIONS_H
#define ROOMFUNCTIONS_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

#include "feature.h"
#include "alcove.h"
#include "protrusion.h"

float calculateFloorArea(float l, float w, std::vector<Alcove> alcoves, std::vector<Protrusion> protrusions);

float calculateWallArea(float l, float w, float h, std::vector<Feature> doors, std::vector<Feature> windows, std::vector<Alcove> alcoves, std::vector<Protrusion> protrusions);
float calculateVolume(float floorArea, float h);

Feature createDoor(std::string u);
Feature createWindow(std::string u);
Alcove createAlcove(std::string u, float h);
Protrusion createProtrusion(std::string u, float h);

#endif
