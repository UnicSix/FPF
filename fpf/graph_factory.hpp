#pragma once

#include <array>
#include <cstddef>
#include <iostream>
#include <random>

#include "bm.h"
#include "graph.hpp"
namespace fpf {

class RandGen {
 public:
  inline static std::random_device rand_device{};
  inline static std::mt19937       rd{rand_device()};
};

[[nodiscard]] inline BitMatGraph2D GenBitMatGraph(size_t N) {
  BitMatGraph2D gen{N};
  for (size_t i = 0; i < N; i++) {
    auto row = gen.matrix.construct_row(i);
    for (size_t j = 0; j < N; j += 2) {
      row->set(j);
    }
  }
  return gen;
}

}  // namespace fpf

namespace fpf {
namespace util {

inline void PrintGraph(BitMatGraph2D mat) {
  size_t N = mat.size;
  // Output matrix
  std::cout << "Bit matrix:\n";
  for (bm::bvector_size_type i = 0; i < N; i++) {
    for (bm::bvector_size_type j = 0; j < N; j++) {
      std::cout << mat.matrix.get_row(i)->get_bit(j) << " ";
    }
    std::cout << std::endl;
  }
  // Output edges
  std::cout << "Edges:\n";
  for (size_t i = 0; i < N * N; i++) {
    std::cout << mat.edge[i] << (i % N == (N - 1) ? "\n" : " ");
  }
  std::cout << std::endl;
}

template <typename T, size_t size>
void PrintArray(std::array<T, size> arr) {
  for (auto val : arr) {
    std::cout << val << " ";
  }
  std::cout << std::endl;
}
}  // namespace util

}  // namespace fpf
