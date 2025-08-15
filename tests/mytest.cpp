#include <cassert>
#include <cstdlib>
#include "fpf.hpp"

int main() {
  assert(fpf::Add(5, 7, 19) == 31);
  assert(fpf::Add(1, 2, 3) == 6);
  assert(fpf::Mult(3, 2, 3) == 18);
  return EXIT_SUCCESS;
}
