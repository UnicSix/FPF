#pragma once

#include <bitset>
#include <cstddef>
#include <random>
#include <vector>

#include "bm.h"
#include "bmbmatrix.h"

namespace fpf {

typedef bm::basic_bmatrix<bm::bvector<>> bmatr_32;

template <size_t w1, size_t w2>
class Mat2x2 {
 public:
  Mat2x2(bool init = false);
  ~Mat2x2()                            = default;
  bool operator==(const Mat2x2&) const = default;

  inline static std::random_device rand_device{};
  inline static std::mt19937       rand{rand_device()};

  std::vector<std::bitset<w1>> matrix;
};

template <size_t w1, size_t w2>
Mat2x2<w1, w2>::Mat2x2(bool init) {
  matrix = std::vector<std::bitset<w1>>(w2, init);
}

template <size_t w1, size_t w2>
class BitMat2x2 {
 public:
  bmatr_32 matrix;
};

}  // namespace fpf
