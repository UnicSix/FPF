#include "dijkstra.hpp"

#include <cstdlib>

#include "edge_sets.hpp"
#include "fpf_util.hpp"
#include "graph.hpp"
#include "graph_factory.hpp"

int main() {
  auto graph = fpf::GenGraphFromEdgeSet<double>(fpf::EdgeSet6x6_0(), 6);
  fpf::util::PrintGraph(graph);
  for (size_t i=0; i<6; ++i) {
    auto path  = fpf::dijk::FindPath(graph, i);
    fpf::util::println("Shortest path from {} to others", i);
    fpf::util::PrintContainer(std::span(path), " ");
  }
  return EXIT_FAILURE;
}
