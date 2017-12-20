#ifndef FEATURE_H
#define FEATURE_H

class Feature{
 protected:
 float _width, _height;
 public:
 Feature();
 Feature(float w, float h);
 Feature( const Feature &copy);  // copy constructor
 ~Feature();                     // destructor
 inline void set_width(float w){_width = w;}
 inline void set_height(float h){_height = h;}
 inline float get_width() const {return _width;}
 inline float get_height() const {return _height;}
 inline float getArea() const {
  float theArea = (_width * _height);
  return theArea;
 }
};

#endif
