#ifndef ALCOVE_H
#define ALCOVE_H

#include "feature.h"

class Alcove : public Feature{
 private:
 float _depth;
 
 public:
 Alcove();
 Alcove(float w, float d, float h);
 Alcove( const Alcove &copy);  // copy constructor
 ~Alcove();                     // destructor

 inline void set_depth(float d){_depth = d;}
 inline float get_depth() const {return _depth;}
 inline float getFloorArea() const {
  float theArea = _width * _depth;
  return theArea;
 }
 inline float getWallArea() {
  float wallArea = 2*(_depth*_height);
  return wallArea;
 }
};
 
#endif
