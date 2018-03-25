#include <vector>
#include <iostream>

void simple_vector() {
  std::vector<int> q_vtc;
  q_vtc.push_back(3);
  q_vtc.push_back(4);
  q_vtc.push_back(22);
  // pointer iterations
  for (auto i = q_vtc.begin(); i != q_vtc.end(); ++i) {
    std::cout << *i << " ";
  }
  std::cout << std::endl;

  // reverse iterations
  for (auto i = q_vtc.rbegin(); i != q_vtc.rend(); ++i) {
    std:: cout << *i << " ";
  }
  std::cout << std::endl;

  // index access
  std::cout << q_vtc[2] << std::endl;
}

int main(int argc, char** argv) {
  simple_vector();
  return 0;
}
