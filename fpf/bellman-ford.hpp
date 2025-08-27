#pragma once

#include <vector>

#include "graph.hpp"

namespace fpf {
namespace belf {
template <typename T>
std::vector<T> FindPath([[maybe_unused]] const BitMatGraph2D<T>& graph,
                        [[maybe_unused]] size_t                  src) {
  assert(src < graph.Size());
  const auto INF = std::numeric_limits<T>::max();
  std::vector<T> dists(graph.Size(), INF);
  return dists;
}

}  // namespace belf

}  // namespace fpf
