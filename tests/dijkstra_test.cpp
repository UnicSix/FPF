#include "dijkstra.hpp"

#include <cassert>
#include <cstdlib>

#include "bellman-ford.hpp"
#include "edge_sets.hpp"
#include "fpf_util.hpp"
#include "graph.hpp"
#include "graph_factory.hpp"

int main() {
  auto graph = fpf::GenGraphFromEdgeSet<double>(fpf::EdgeSet6x6_0(), 6);
  fpf::util::PrintGraph(graph);
  for (size_t i = 0; i < 6; ++i) {
    auto path = fpf::dijk::FindPath(graph, i);
    fpf::util::println("Shortest path from {} to others", i);
    fpf::util::PrintContainer(std::span(path), " ");
  }
  fpf::util::println("=========");
  for (size_t i = 0; i < 6; ++i) {
    auto path = fpf::belf::FindPath(graph, i);
    fpf::util::println("Shortest path from {} to others", i);
    fpf::util::PrintContainer(std::span(path), " ");
  }
  for (size_t i = 0; i < 6; ++i) {
    auto path1 = fpf::dijk::FindPath(graph, i);
    auto path2 = fpf::belf::FindPath(graph, i);
    assert(path1.size() == path2.size());
    for(size_t j=0; j<path1.size(); j++) {
      assert(path1[j] == path2[j]);
    }
  }
  return EXIT_SUCCESS;
}
