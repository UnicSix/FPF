#pragma once

#include "graph.hpp"
namespace fpf {

template <size_t w1, size_t w2>
[[nodiscard]] Mat2x2<w1, w2> GenMatrixGraph() {
  Mat2x2<w1, w2> matrix{true};
  return matrix;
}

}  // namespace fpf
