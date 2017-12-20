//protrusion.cxx
#include "feature.h"
#include "protrusion.h"

Protrusion::Protrusion(){}
Protrusion::Protrusion(float w, float d, float h, bool c){
 _width = w;
 _depth = d;
 _height = h;
 _isCorner = c;
}
Protrusion::Protrusion(const Protrusion &copy) {
  //copy object
  _width = copy._width;
  _depth = copy._depth;
  _height = copy._height;
  _isCorner = copy._isCorner;
}

Protrusion::~Protrusion(void) {
   /*delete _width;
   delete _depth;
   delete _height;
   delete _isCorner;*/
}
