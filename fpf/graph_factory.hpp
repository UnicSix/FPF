#pragma once

#include <array>
#include <cstddef>
#include <iostream>
#include <random>
#include "bm.h"

#include "bm.h"
#include "graph.hpp"
namespace fpf {

class RandGen {
 public:
  inline static std::random_device rand_device{};
  inline static std::mt19937       rd{rand_device()};
};

template <size_t w1, size_t w2>
[[nodiscard]] Mat2x2<w1, w2> GenMatrixGraph() {
  RandGen                            rand;
  std::uniform_int_distribution<int> dist(0, 4);
  for (int i = 0; i < 5; i++) {
    std::cout << dist(rand.rd) << " ";
  }
  std::cout << std::endl;
  Mat2x2<w1, w2> matrix{true};
  return matrix;
}

template <size_t w1, size_t w2>
[[nodiscard]] BitMat2x2<w1, w2> GenBitMatGraph() {
  BitMat2x2<w1, w2> gen;
  for (size_t i = 0; i < w1; i++) {
    auto row = gen.matrix.construct_row(i);
    for (size_t j = 0; j < w2; j += 2) {
      row->set(j);
    }
  }
  return gen;
}

}  // namespace fpf

namespace fpf {
namespace util {

template <size_t w1, size_t w2>
void PrintGraph(BitMat2x2<w1, w2> mat) {
  for (bm::bvector_size_type i = 0; i < w1; i++) {
    for (bm::bvector_size_type j = 0; j < w2; j++) {
      std::cout << mat.matrix.get_row(i)->get_bit(j) << " ";
    }
    std::cout << std::endl;
  }
}

template <size_t size>
void PrintArray(std::array<int, size> arr) {
  for (auto val : arr) {
    std::cout << val << " ";
  }
  std::cout << std::endl;
}
}  // namespace util

}  // namespace fpf
