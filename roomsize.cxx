// roomsize.cxx, written by Ruth Davidson 20/12/17
// This program calculates the floor area, wall area and volume of a rectangular room with any number of doors and windows, and any number of regular floor-to-ceiling alcolves and protrusions.
// This program could be easily modified to include different features, of differing sizes and shapes.

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

#include "feature.h"
#include "alcove.h"
#include "protrusion.h"
#include "roomfunction.h"

//declare functions



int main()
{
 float theLength, theWidth, theHeight;
 float floorArea, wallArea, roomVolume;
 
 int numberOfDoors, numberOfWindows, numberOfAlcoves, numberOfProtrusions;

 std::vector<Feature> windows, doors;
 std::vector<Alcove> alcoves;
 std::vector<Protrusion> protrusions;
 int i = 0;
 std::string myUnits;
 //ask for units - if units are consistant the shouldn't affect the maths.
 std::cout << "What dimensions are you working in? Inches, centimetres or metres?" << std::endl;
 std::cin >> myUnits ;
 //ask for dimensions
 std::cout << "What is the length of your room in " << myUnits << "?" << std::endl ;
 std::cin >> theLength ;
 std::cout << "What is the width of your room in " << myUnits << "?" << std::endl ;
 std::cin >> theWidth ;
 std::cout << "What is the height of your room in " << myUnits << "?" << std::endl ;
 std::cin >> theHeight ;
 
 std::cout << "How many doors are there in your room? "; 
 do{
  std::cout << "Enter 1-10:" << std::endl ;
  std::cin >> numberOfDoors ;}
 while (numberOfDoors <= 0 || numberOfDoors > 10);

 for (i = 0; i < numberOfDoors; i++){
  std::cout << "For door number " << i+1 << ":" << std::endl ;
  Feature myDoor = createDoor(myUnits);
  doors.push_back(myDoor);
 }
 
 std::cout << "How many windows are there in your room? " ;
 
 do{
  std::cout << "Enter 0-10:" << std::endl ;
  std::cin >> numberOfWindows ;}
 while (numberOfWindows < 0 || numberOfWindows > 10);

 if (numberOfWindows == 0){
  std::cout << "No windows." << std::endl;
 }
 else{
  for (i = 0; i < numberOfWindows; i++){
   std::cout << "For window number " << i+1 << ":" << std::endl ;
   Feature myWindow = createWindow(myUnits);
   windows.push_back(myWindow);
  }
 }

 std::cout << "How many alcoves, nooks or other extra spaces are there in your room? " ;
 
 do{
  std::cout << "Enter 0-10:" << std::endl ;
  std::cin >> numberOfAlcoves ;}
 while (numberOfAlcoves < 0 || numberOfAlcoves > 10);

 if (numberOfAlcoves == 0){
  std::cout << "No alcoves" << std::endl;
 }
 else{
  for (i = 0; i < numberOfAlcoves; i++){
   std::cout << "For alcove number " << i+1 << ":" << std::endl ;
   Alcove myAlcove = createAlcove(myUnits,theHeight);
   alcoves.push_back(myAlcove);
  }
 }

 std::cout << "How many protrusions that jut into your room, such as chimney breasts or boxed in cables, are there?" ;
 do{
  std::cout << "Enter 0-10:" << std::endl ;
  std::cin >> numberOfProtrusions ;}
 while (numberOfProtrusions < 0 || numberOfProtrusions > 10);

 if (numberOfProtrusions == 0){
  std::cout << "No protrusions" << std::endl;
  }
 else{
  for (i = 0; i < numberOfProtrusions; i++){
   Protrusion myProtrusion = createProtrusion(myUnits, theHeight);
   protrusions.push_back(myProtrusion);
  }
 }
floorArea = calculateFloorArea(theLength, theWidth, alcoves, protrusions);
wallArea = calculateWallArea(theLength, theWidth, theHeight, doors, windows, alcoves, protrusions);
roomVolume = calculateVolume(floorArea, theHeight);

std::cout << "Floor area is " << floorArea << " square " << myUnits << std::endl;
std::cout << "Wall area is " << wallArea << " square " << myUnits << std::endl;
std::cout << "Volume is " << roomVolume << " cubic " << myUnits << std::endl;

return 0;
}
