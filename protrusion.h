#ifndef PROTRUSION_H
#define PROTRUSION_H

#include "feature.h"

class Protrusion : public Feature{
 float _depth;
 bool _isCorner;
 public:
 Protrusion();
 Protrusion(float w, float d, float h, bool c);
 Protrusion( const Protrusion &copy);  // copy constructor
 ~Protrusion();                     // destructor
 
 inline void set_depth(float d){_depth = d;}
 inline void set_isCorner(bool c){_isCorner = c;}
 inline float get_depth() const {return _depth;}
 inline bool get_isCorner() const {return _isCorner;}
 inline float getFloorArea() const {
  float theArea = _width * _depth;
  return theArea;
 }
 inline float getWallArea() {
  float theArea;
  if (!_isCorner){
   theArea = 2*(_depth*_height);
  }
  else theArea = 0;
  return theArea;
 }
};

#endif
