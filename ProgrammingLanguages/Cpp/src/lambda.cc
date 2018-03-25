#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

std::vector<int> qq = {1, 2, 3};

/**
 * Compiler generates an anonymous function object
 * - Have context (capture): in `[]`
 * - Can keep in a variable
 */

void show_vector(std::vector<int> v) {
  std::for_each(v.begin(), v.end(), [](const int& val) {
    std::cout << val << " ";
  });
  std::cout << std::endl;
}

void capture() {
  std::cout << "Lamda function capturing" << std::endl;
  // [x, y]: capture x and y by value
  // [&x, &y]: capture by referene
  // [=]: capture what we need inside the lambda function by **value**
  // [&]: capture every by **reference**
  int x = 2;
  int y = 22;
  // normal: capture by value and we can not change x and y
  std::function<void(int)> immu_val = [x, y](int val) {
    if (val > x && val <= y) {
      std::cout << "Hello " << val << std::endl;
    } else {
      std::cout << "Oops! " << std::endl;
    }
  };
  // We can take an reference of the param too
  // with mutable: we can change the x and y, but we are referencing
  // by value, so it doesn't have any effect
  std::function<void(int&)> mul_val = [=](int& val) mutable {
    const int old = val;
    val *= 2; // double each value inside the vector
    x = y;
    y = old;
  };

  // Capture by reference
  std::function<void(int&)> ref_capture = [&](int& val) mutable {
    x *= 2;
    y *= 2;
  };

  std::for_each(qq.begin(), qq.end(), mul_val);
  show_vector(qq);
  std::cout << "(x, y) = (" << x << ", " << y << ")" << std::endl;
  std::cout << "Lamda function capturing: Done" << std::endl;
}

int main() {
  std::vector<int> v;
  v.push_back(10);
  // [] -> double {
  //  return
  // }
  std::for_each(v.begin(), v.end(), [](int val) {
    std::cout << val << std::endl;
  });

  // lambda return val
  std::transform(v.begin(), v.end(), std::back_inserter(v), [](int val) -> int {
    return val * val;
  });

  capture();
}
 