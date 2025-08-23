#pragma once

#include <cstddef>
#include <vector>

#include "bm.h"
#include "bmbmatrix.h"
#include "bmfunc.h"

namespace fpf {

template <typename T>
struct Edge {
  int v1, v2;
  T   dist;
};

using bm_mat = bm::basic_bmatrix<bm::bvector<>>;

template <typename T>
class BitMatGraph2D {
  template <typename First, typename Second>
  using pair = bm::pair<First, Second>;

 public:
  BitMatGraph2D(size_t size);
  // BitMatGraph2D()
  ~BitMatGraph2D() = default;

  inline size_t Size() const { return size; }

  /* Given N vertices n0, n1, n2...n(N-1)
   * matrix stores the connection state of each pair of nodes
   * edge stores the correspond weight of node pair
   * E(0->0) -> edge[0*N + 0]
   * E(2->5) -> edge[2*N + 5]
   * E(A->B) might != E(B->A)
   */
  bm_mat         connection_;
  std::vector<T> edge_vec_;

 private:
  size_t size;
};

// Constructs a N by N non-dynamic bit matrix filled with 0
template <typename T>
BitMatGraph2D<T>::BitMatGraph2D(size_t N)
    : connection_(N, false), edge_vec_(N * N, 0), size(N) {
  for (size_t i = 0; i < N; i++) {
    connection_.construct_row(i);
  }
}

}  // namespace fpf
