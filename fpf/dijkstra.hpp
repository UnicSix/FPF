#pragma once

#include <cassert>
#include <functional>
#include <limits>
#include <queue>
#include <vector>

#include "bm.h"
#include "fpf_util.hpp"
#include "graph.hpp"

namespace fpf {

namespace dijk {

template <typename T>
std::vector<T> FindPath(BitMatGraph2D<T>& graph, size_t src) {
  assert(src < graph.Size());

  const auto INF = std::numeric_limits<T>::max();
  std::priority_queue<Weight<T>, std::vector<Weight<T>>,
                      std::greater<Weight<T>>>
                 weights;
  std::vector<T> dists(graph.Size(), INF);
  bm::bvector<>  visited;
  auto           cur_row = graph.GetRow(src);
  dists[src]             = 0;

  weights.push(Weight<T>{src, 0});
  size_t cur = src;
  while (!weights.empty()) {
    cur = weights.top().vtx;
    weights.pop();
    if (visited.get_bit(cur)) continue;
    visited.set(cur);
    cur_row = graph.GetRow(cur);

    // loop through connected vertices
    for (auto vtx = cur_row->first(); vtx < cur_row->end(); ++vtx) {
      // vtx.value(): connected vertex
      if (dists[vtx.value()] > dists[cur] + graph.DistAt(cur, vtx)) {
        dists[vtx.value()] = dists[cur] + graph.DistAt(cur, vtx);
        weights.push(Weight{vtx.value(), dists[vtx.value()]});
      }
    }
  }

  return dists;
}

}  // namespace dijk

}  // namespace fpf
