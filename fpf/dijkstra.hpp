#pragma once

#include <vector>

#include "graph.hpp"

namespace fpf {

namespace dijk {

template <typename T>
std::vector<Edge<T>> FindPath(BitMatGraph2D<T>& graph, [[maybe_unused]] int start) {
  std::vector<Edge<T>> path(graph.Size(), {});
  return path;
}

}  // namespace dijk

}  // namespace fpf
