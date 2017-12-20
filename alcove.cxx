//alcove.cxx
#include "feature.h"
#include "alcove.h"
 
 Alcove::Alcove(){}
 Alcove::Alcove(float w, float d, float h){
  _width = w;
  _depth = d;
  _height = h;
 }
 
 Alcove::Alcove(const Alcove &copy) {
  //copy object
  _width = copy._width;
  _depth = copy._depth;
  _height = copy._height;
}

Alcove::~Alcove(void) {
   /*delete _width;
   delete _depth;
   delete _height;*/
}
