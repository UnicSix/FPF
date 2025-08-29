#include "dijkstra.hpp"

#include <cassert>
#include <cstdlib>

#include "bellman-ford.hpp"
#include "edge_sets.hpp"
#include "fpf_util.hpp"
#include "graph.hpp"
#include "graph_factory.hpp"

int main() {
  auto graph = fpf::GenGraphFromEdgeSet<double>(fpf::EdgeSet6x6_NegativeEdges(), 6);
  for (size_t i = 0; i < 6; ++i) {
    auto path = fpf::belf::FindPath(graph, i);
    fpf::util::println("Shortest path from {} to others", i);
    fpf::util::PrintContainer(std::span(path), " ");
  }
  return EXIT_FAILURE;
}

