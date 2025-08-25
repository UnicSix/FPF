#pragma once

#include <array>
#include <cstddef>
#include <random>

#include "fpf_util.hpp"
#include "graph.hpp"
namespace fpf {

class RandGen {
 public:
  inline static std::random_device rand_device{};
  inline static std::mt19937       rd{rand_device()};
};

template <typename T>
[[nodiscard]] inline BitMatGraph2D<T> GenBitMatGraph(size_t N) {
  BitMatGraph2D<T> gen{N};
  for (size_t i = 0; i < N; i++) {
    auto row = gen.connection_.construct_row(i);
    for (size_t j = 0; j < N; j += 2) {
      row->set(j);
    }
  }
  return gen;
}

// 6x6 adjacency matrix (36 bits total)
// Dense connectivity pattern
// matrix bits: 011010 101001 110100 010110 100011 001101
// Corresponding edge weights (36 doubles)
// edge weights: [
//   0.0, 1.2, 2.3, 0.0, 3.1, 0.0,    // from node 0
//   2.8, 0.0, 1.9, 0.0, 0.0, 4.5,    // from node 1
//   1.7, 3.3, 0.0, 2.1, 0.0, 0.0,    // from node 2
//   0.0, 1.8, 0.0, 0.0, 2.9, 3.7,    // from node 3
//   2.4, 0.0, 0.0, 0.0, 0.0, 1.6,    // from node 4
//   0.0, 0.0, 3.8, 1.3, 0.0, 0.0     // from node 5
// ]
//
// Input data format:
// Edge{v1, v2, dist}

template <typename T, size_t sz>
[[nodiscard]] inline BitMatGraph2D<T> GenGraphFromEdgeSet(
    std::array<Edge<T>, sz>&& edge_set, size_t size) {
  BitMatGraph2D<T> gen(size);
  const auto&      N = gen.Size();
  for (auto&& edge : edge_set) {
    gen.connection_.get_row(edge.v1)->set(edge.v2);
    gen.edge_vec_.at(edge.v1 * N + edge.v2) = edge.dist;
  }
  // Every vertice's dist to itself is 0
  for (size_t i = 0; i < size; ++i) {
    gen.edge_vec_[i * N + i] = T(0);
  }
  return gen;
}

}  // namespace fpf
