#include <string>


class Student {
private:
  std::string name;
  int age;

public:
  Student(std::string name, int age): name{name}, age{age} {}

  int sayHello() {
    return this->age;
  }
};

// I'm useless there. Here, I'm good!
