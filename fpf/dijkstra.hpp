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
  std::priority_queue<T, std::vector<T>, std::greater<T>> nodes;
  std::vector<T> dists(graph.Size(), INF);
  bm::bvector<>  visited;
  auto           src_row = graph.connection_.get_row(src);
  dists[src]             = 0;

  bool done = false;
  // int  next = 0;
  nodes.emplace(0);
  while (!done) {
    for (auto itr = src_row->first(); itr < src_row->end(); ++itr) {
    }
    done = true;
  }

  return dists;
}

}  // namespace dijk

}  // namespace fpf
