#include <iostream>

#include "person.h"

namespace qq {
  Person::Person(std::string name, int age): name{name}, age{age} {
    this->age = age;
    this->name = name;
    std::cout << name << "is constructing ..." << std::endl;
  }

  ~ Person::Person () {
    std::cout << name << "is destroying ..." << std::endl;
  }

}