#include "dijkstra.hpp"

#include <cstdlib>

#include "edge_sets.hpp"
#include "fpf_util.hpp"
#include "graph.hpp"
#include "graph_factory.hpp"

int main() {
  int  start = 0;
  auto graph = fpf::GenGraphFromEdgeSet<double>(fpf::EdgeSet6x6_0(), 6);
  auto path  = fpf::dijk::FindPath(graph, start);
  fpf::util::PrintGraph(graph);
  fpf::util::println("Shortest path from {} to others", start);
  fpf::util::PrintContainer(std::span(path), "\n");
  return EXIT_FAILURE;
}
