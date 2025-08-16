#include "fpf.hpp"

#include <iostream>

namespace fpf {

void Test() {
  std::cout << "Hello";
  for (int i = 0; i < 10; i++) {
    std::cout << i << " ";
  }
}

int Add(int a, int b, int c) {
  int sum = a+b+c;
  return sum;
}

}  // namespace fpf
