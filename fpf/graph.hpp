#pragma once

#include <cstddef>
#include <limits>
#include <vector>

#include "bm.h"
#include "bmbmatrix.h"

namespace fpf {

template <typename T>
struct Edge {
  int v1, v2;
  T   dist;
};
template <typename T>
struct Weight {
  auto operator<=>(const Weight& other) const {
    return this->dist <=> other.dist;
  }
  bool operator==(const Weight& other) const {
    return this->dist == other.dist && this->vtx == other.vtx;
  }
  size_t vtx;
  T      dist;
};

using bm_mat = bm::basic_bmatrix<bm::bvector<>>;

template <typename T>
class BitMatGraph2D {
 public:
  BitMatGraph2D(size_t size);
  // BitMatGraph2D()
  ~BitMatGraph2D() = default;

  inline size_t  Size() const { return size; }
  inline const T DistAt(size_t src, auto dest_ptr) const {
    assert(src * size + dest_ptr.value() < size * size);
    return edge_vec_[src * size + dest_ptr.value()];
  }
  inline const T DistAt(size_t src, size_t dest) const {
    assert(src * size + dest < size * size);
    return edge_vec_[src * size + dest];
  }

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
    : connection_(N, true),
      edge_vec_(N * N, std::numeric_limits<T>::max()),
      size(N) {
  for (size_t i = 0; i < N; i++) {
    connection_.construct_row(i);
    edge_vec_[i * N + i] = T(0);
  }
}

}  // namespace fpf
