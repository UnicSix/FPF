#include <cstdlib>
#include "graph.hpp"
#include "graph_factory.hpp"

int main() {
  auto test = fpf::BitMat2x2<5, 12>();
  fpf::util::PrintGraph(test);
  return EXIT_FAILURE;
}
