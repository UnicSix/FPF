#pragma once

#include <cstddef>
#include <vector>

#include "bm.h"
#include "bmbmatrix.h"
#include "bmfunc.h"

namespace fpf {

using bm_mat = bm::basic_bmatrix<bm::bvector<>>;

template <typename T>
class BitMatGraph2D {
  template <typename First, typename Second>
  using pair = bm::pair<First, Second>;

 public:
  BitMatGraph2D(size_t size);
  ~BitMatGraph2D() = default;

  inline size_t Size() const { return size; }

  /* Given N vertices n0, n1, n2...n(N-1)
   * matrix stores the connection state of each pair of nodes
   * edge stores the correspond weight of node pair
   * E(0->0) -> edge[0*N + 0]
   * E(2->5) -> edge[2*N + 5]
   * E(A->B) might != E(B->A)
   */
  bm_mat         matrix;
  std::vector<T> edge;

 private:
  size_t size;
};

// Constructs a w1 by w2 non-dynamic bit matrix filled with 0
template <typename T>
BitMatGraph2D<T>::BitMatGraph2D(size_t N)
    : matrix(N, false), size(N), edge(N * N, 0) {
  for (size_t i = 0; i < N; i++) {
    [[maybe_unused]] auto row = matrix.construct_row(i);
  }
}

}  // namespace fpf
