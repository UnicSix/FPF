#pragma once

#include <cassert>
#include <cstddef>
#include <limits>
#include <vector>

#include "bm.h"
#include "fpf_util.hpp"
#include "graph.hpp"

namespace fpf {

namespace {}

template <typename T>
std::vector<T> FindPath(BitMatGraph2D<T>& graph, size_t src) {
  assert(src < graph.Size());

  const auto          INF         = std::numeric_limits<T>::max();
  const auto          NOT_VISITED = std::numeric_limits<size_t>::max();
  std::vector<size_t> pred(graph.Size(), NOT_VISITED);
  std::vector<T>      dists(graph.Size(), INF);
  pred[0]    = src;
  dists[src] = 0;

  // clang-format off
  /* For every vtx u with dist(u) < b, u is complete
   * Set S contains all current vertices u with b <= d_hat[u] < B for some bound B
   * Each incomplete vertex v with b <= d_hat[v] < B must pass some complete vertex in S.
   * BMSSP: Bounded multi-source shortest path
  */
  // clang-format on

  return {};
}

}  // namespace fpf
