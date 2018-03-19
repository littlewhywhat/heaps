#include <iostream>

#include "greeter.h"

//! Greet world
/*!
    Use greeter to say hello to world in standard output
*/
int main(void) {
  Greeter greeter;
  greeter.greet(std::cout, "World");
  return 0;
}
