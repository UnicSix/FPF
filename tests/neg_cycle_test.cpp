#include <cassert>
#include <cstdlib>

#include "bellman-ford.hpp"
#include "edge_sets.hpp"
#include "fpf_util.hpp"
#include "graph.hpp"
#include "graph_factory.hpp"

int main() {
  auto graph = fpf::GenGraphFromEdgeSet<int>(fpf::EdgeSet5x5_0(), 5);
  fpf::util::PrintGraph(graph);
  for (size_t i = 0; i < 6; ++i) {
    auto path = fpf::belf::FindPath(graph, i);
    fpf::util::println("Shortest path from {} to others", i);
    fpf::util::PrintContainer(std::span(path), " ");
  }
  return EXIT_FAILURE;
}
