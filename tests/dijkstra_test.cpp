#include "dijkstra.hpp"

#include "edge_sets.hpp"
#include "fpf_util.hpp"
#include "graph.hpp"
#include "graph_factory.hpp"

int main() {
  auto graph = fpf::GenGraphFromEdgeSet(fpf::EdgeSet6x6_0());
  auto path  = fpf::dijk::FindPath(graph, 0);
  fpf::util::PrintGraph(graph);
  // fpf::util::PrintContainer(path);
}
