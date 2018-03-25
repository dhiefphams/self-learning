#include <string>

#ifndef PERSON_H
#define PERSON_H

namespace qq {

class Person {
public:
  std::string name;
  int age;

  Person(std::string name, int age);

  ~Person();
};

} // namespace qq

#endif
