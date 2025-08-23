#include <cstdlib>
#include <random>

#include "graph.hpp"
#include "graph_factory.hpp"

int main() {
  fpf::RandGen                    rand;
  std::uniform_int_distribution<> dist(5, 9);

  auto test  = fpf::BitMatGraph2D<int>{5};
  auto test2 = fpf::GenBitMatGraph<double>(19);
  auto test3 = fpf::BitMatGraph2D<float>(dist(rand.rd));
  // fpf::util::PrintGraph(test);
  // fpf::util::PrintGraph(test2);
  // fpf::util::PrintGraph(test3);
  auto test4 = fpf::TestGraph0();
  return EXIT_FAILURE;
}
