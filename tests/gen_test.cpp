#include <cstdlib>
#include <random>

#include "edge_sets.hpp"
#include "graph.hpp"
#include "graph_factory.hpp"

int main() {
  fpf::RandGen                    rand;
  std::uniform_int_distribution<> dist(5, 9);

  auto test  = fpf::BitMatGraph2D<int>{5};
  auto test2 = fpf::GenBitMatGraph<double>(19);
  auto test3 = fpf::BitMatGraph2D<float>(dist(rand.rd));
  auto test4 = fpf::GenGraphFromEdgeSet<double>(fpf::EdgeSet6x6_0(), 6);
  fpf::util::PrintGraph(test4);
  return EXIT_SUCCESS;
}
