//feature.cxx
#include "feature.h"
 
 Feature::Feature(){}
 Feature::Feature(float w, float h){
  _width = w;
  _height = h;
 }
 Feature::Feature(const Feature &copy) {
  //copy object
  _width = copy._width;
  _height = copy._height;
}

Feature::~Feature(void) {
   /*delete _width;
   delete _height;*/
}
