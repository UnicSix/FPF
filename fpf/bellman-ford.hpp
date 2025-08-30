#pragma once

#include <vector>

#include "bm.h"
#include "fpf_util.hpp"
#include "graph.hpp"

namespace fpf {
namespace belf {
template <typename T>
std::vector<T> FindPath(BitMatGraph2D<T>& graph, size_t src) {
  assert(src < graph.Size());
  const auto    INF = std::numeric_limits<T>::max();
  bm::bvector<> visited;

  std::vector<T> dists(graph.Size(), INF);
  dists[src] = 0;
  for (size_t i = 0; i < graph.Size(); ++i) {
    size_t cur     = (src + i) % graph.Size();
    auto   cur_row = graph.GetRow(cur);
    for (auto vtx = cur_row->first(); vtx != cur_row->end(); ++vtx) {
      // Avoid numeric overload
      if (graph.DistAt(cur, vtx) == INF || dists[cur] == INF)
        continue;
      else if (dists[vtx.value()] > dists[cur] + graph.DistAt(cur, vtx)) {
        dists[vtx.value()] = dists[cur] + graph.DistAt(cur, vtx);
      }
    }
  }
  // Check negative cycle

  return dists;
}

}  // namespace belf

}  // namespace fpf
