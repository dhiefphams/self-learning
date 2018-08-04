#include <iostream>
#include "Rectangle.h"

namespace shapes {
  // default constructor
  Rectangle::Rectangle() {}

  // Overload constructor
  Rectangle::Rectangle(int x0, int y0, int x1, int y1):
    x0{x0}, y0{y0}, x1{x1}, y1{y1} {
  }

  // Destructor
  Rectangle::~Rectangle() {}


  int Rectangle::getArea() {
    return (this->x1 - this->x0) * (this->y1 - this->y0);
  }

  // get the size of the rect
  // put the size in the pointers args
  void Rectangle::getSize(int* width, int* height) {
    (*width) = x1 - x0;
    (*height) = y1 - y0;
  }

  void Rectangle::move(int dx, int dy) {
    this->x0 += dx;
    this->y0 += dy;
    this->x1 += dx;
    this->y1 += dy;
  }
}
