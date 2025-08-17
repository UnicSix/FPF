#pragma once

#include <bitset>
#include <cstddef>
#include <vector>

#include "bm.h"
#include "bmbmatrix.h"

namespace fpf {

using bm_mat = bm::basic_bmatrix<bm::bvector<>>;

template <size_t w1, size_t w2>
class Mat2x2 {
 public:
  Mat2x2(bool init = false);
  ~Mat2x2()                            = default;
  bool operator==(const Mat2x2&) const = default;

  std::vector<std::bitset<w1>> matrix;
};

template <size_t w1, size_t w2>
Mat2x2<w1, w2>::Mat2x2(bool init) {
  matrix = std::vector<std::bitset<w1>>(w2, init);
}

template <size_t w1, size_t w2>
class BitMat2x2 {
 public:
  BitMat2x2();
  ~BitMat2x2() = default;

  bm_mat matrix;
};

// Constructs a w1 by w2 bit matrix filled with 0
template <size_t w1, size_t w2>
BitMat2x2<w1, w2>::BitMat2x2() :matrix(0){
  for (size_t i = 0; i < w1; i++) {
    [[maybe_unused]] auto row = matrix.construct_row(i);
  }
}

}  // namespace fpf
