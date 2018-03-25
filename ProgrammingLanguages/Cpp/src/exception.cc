#include <iostream>
#include <vector>
#include <memory>

/**
 * std::exception
 * 
 * Derived classes
 * 
 * std::logic_error:
 * - std::domain_error
 * - std::invalid_argument
 * - std::length_error
 * - std::out_of_range
 *
 * std::runtime_error
 * - std::overflow_error
 * - std::range_error
 * - std::underflow_error
 */

int main() {
  std::vector<int> qq = {1, 2, 3};
  try {
    const auto i = qq.at(99);
    std::cout << i << std::endl;
  } catch(std::out_of_range& e) {
    std::cout << "Out of range" << std::endl;
  } catch (std::exception& e) { // use capture by reference for better debug, because catch by value it drops the the parent class.
    std::cout << e.what() << std::endl;
  }

  // between the throw and the catch, locally-scoped objects are cleaned up. e.g: destruct runs

  // We can throw any thing =)))))))))))))))))
  
  // In try/catch, there is not finally, so be becareful when
  try {
    // it pretty save
    auto x_ptr = std::make_shared<int>(10);
    // but, be sure that you clean up memory with `new`
    auto y_ptr = new int(10);
    delete y_ptr;
  } catch (std::exception& e) {
    //
  }
}