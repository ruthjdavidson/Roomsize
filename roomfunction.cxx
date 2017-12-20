//roomfunction.cxx
#include "roomfunction.h"


float calculateFloorArea(float l, float w, std::vector<Alcove> alcoves, std::vector<Protrusion> protrusions){
 float theArea = l * w;
 unsigned int i = 0;
 for (i=0; i < alcoves.size(); i++){
   float alc_area = alcoves[i].getFloorArea();
   theArea = theArea + alc_area;
  }
  for (i=0; i < protrusions.size(); i++){
   float prot_area = protrusions[i].getFloorArea();
   theArea = theArea - prot_area;
  }
  return theArea;
 }

float calculateWallArea(float l, float w, float h, std::vector<Feature> doors, std::vector<Feature> windows, std::vector<Alcove> alcoves, std::vector<Protrusion> protrusions){
 float theArea = 2*(l*h) + 2*(w*h); 
 unsigned int i =0;
 for (i=0; i < doors.size(); i++){
   float door_area = doors[i].getArea();
   theArea = theArea - door_area;
  }
  for (i=0; i < windows.size(); i++){
   float window_area = windows[i].getArea();
   theArea = theArea - window_area;
  }
  for (i=0; i < alcoves.size(); i++){
    float alc_area = alcoves[i].getWallArea();
    theArea = theArea + alc_area;
  }
  for (i=0; i < protrusions.size(); i++){
   float prot_area = protrusions[i].getWallArea();
   theArea = theArea + prot_area;
  }
 return theArea;
}

float calculateVolume(float floorArea, float h){
 float volume = floorArea * h;
 return volume;
}

Feature createDoor(std::string u){
  float h, w;
  std::cout << "What is the height of your door in " << u << "?" << std::endl;
  std::cin >> h ;
  std::cout << "What is the width of your door in " << u << "?" << std::endl;
  std::cin >> w ;
  Feature myDoor(h, w);
  return myDoor;
 }
 Feature createWindow(std::string u){
  float h, w;

 std::cout << "What is the height of your window in " << u << "?" << std::endl;
 std::cin >> h ;
 std::cout << "What is the width of your window in " << u << "?" << std::endl;
 std::cin >> w ;
 Feature myWindow(h, w);
 return myWindow;
 }
 
 Alcove createAlcove(std::string u, float h){
  float w, d;

 std::cout << "What is the width of your alcove in " << u << "?" << std::endl;
 std::cin >> w ;
 std::cout << "What is the depth of your alcove in " << u << "?" << std::endl;
 std::cin >> d ;
 Alcove myAlcove(w,d,h);
 return myAlcove;
}

Protrusion createProtrusion(std::string u, float h){
  float w, d;
  std::string myAnswer;
  bool isCorner = false;

 std::cout << "What is the width of your protrusion in " << u << "?" << std::endl;
 std::cin >> w ;
 std::cout << "What is the depth of your protrusion in " << u << "?" << std::endl;
 std::cin >> d ;
 std::cout << "Is the protrusion in the corner of the room? y/n " << std::endl;
 std::cin >> myAnswer ;
 if (myAnswer == "y"){isCorner = true;}
 else if (myAnswer == "n") {isCorner = false;}
 else {
  std::cout << "Unexpected input, try again. y/n" << std::endl;
  std::cin >> myAnswer ;
  if (myAnswer == "y"){isCorner = true;}
   else if (myAnswer == "n") {isCorner = false;}
   else {std::exit(1);}
  }
 
 Protrusion myProtrusion(w, d, h, isCorner);
 return myProtrusion;
}

