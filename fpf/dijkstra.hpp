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
std::vector<T> FindPath(const BitMatGraph2D<T>& graph, size_t src) {
  assert(src < graph.Size());

  const auto INF = std::numeric_limits<T>::max();
  const auto sz  = graph.Size();
  std::priority_queue<Weight<T>, std::vector<Weight<T>>,
                      std::greater<Weight<T>>>
                 vertices;
  std::vector<T> dists(graph.Size(), INF);
  bm::bvector<>  visited;
  auto           src_row = graph.connection_.get_row(src);
  dists[src]             = 0;

  auto DistAt = [&graph, &sz](size_t src, auto dest_ptr) {
    assert(src * sz + dest_ptr.value() < sz * sz);
    return graph.edge_vec_[src * sz + dest_ptr.value()];
  };

  vertices.push({src, 0});
  size_t cur = src;
  while (!vertices.empty()) {
    cur = vertices.top().vtx;
    vertices.pop();
    if (visited.get_bit(cur)) continue;
    visited.set(cur);
    src_row = graph.connection_.get_row(cur);

    // loop through connected vertices
    for (auto vtx = src_row->first(); vtx < src_row->end(); ++vtx) {
      // vtx.value(): connected vertex
      if (dists[vtx.value()] > dists[cur] + DistAt(cur, vtx)) {
        dists[vtx.value()] = dists[cur] + DistAt(cur, vtx);
        vertices.push({vtx.value(), dists[vtx.value()]});
      }
    }
  }

  return dists;
}

}  // namespace dijk

}  // namespace fpf
