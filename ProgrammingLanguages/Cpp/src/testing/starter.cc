// g++ -I/path/to/catch_include starter.cc
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "student.hpp"

TEST_CASE("This is a test name") {

  Student q{"Hello", 10};
  
  REQUIRE(q.sayHello() == 10);
}
// Problem solving
// Prepare the problem:
// 1. Make sure you understand the problem: Reading books, immerse yourself in the problem space
// even consider writing test codo to validate out the ideas
// 2. Decompose: Breack down the individual task in steps (divide and conquer)
// 3. Simplify: Write the code in the most transparent wayt possible.

// From thinking to writing to the tool you are working on. Practice more examples and patterns
// Rehearse (practice) for 30mins daily (consistently track all our learning)
// https://softwareengineering.stackexchange.com/questions/65705/how-to-code-faster-without-sacrificing-quality
