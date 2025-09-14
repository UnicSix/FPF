#pragma once

#include <cstddef>
#include <limits>
#include <vector>

#include "bm.h"
#include "bmbmatrix.h"
#include <absl/container/flat_hash_map.h>

namespace fpf {

template <typename T>
struct Edge {
  size_t v1, v2;
  T      dist;
};
template <typename T>

struct pair {
  size_t x;
  size_t y;
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
class FpfGraph {
 public:
  FpfGraph() = default;
  ~FpfGraph() = default;
  auto GetRow(const size_t index) { return connection_.get_row(index); }
  auto ConstructRow(const size_t index) { return connection_.construct_row(index); }

  void BatchPrepend();
  void Pull();
  void Initialize();
  void Delete();
  void Split();
  void Insert();
private:
  absl::flat_hash_map<size_t, T> map;
  bm_mat         connection_;
  size_t         size;
};

template <typename T>
class BitMatGraph2D {
 public:
  explicit BitMatGraph2D(size_t N);
  // BitMatGraph2D()
  ~BitMatGraph2D() = default;

  [[nodiscard]] inline auto GetRow(const size_t index) { return connection_.get_row(index); }
  auto ConstructRow(const size_t index) { return connection_.construct_row(index); }
  inline void SetWeight(const Edge<T>& edge) {
    edge_vec_[edge.v1 * size + edge.v2] = edge.dist;
  }
  [[nodiscard]] inline T& EdgeAt(size_t index) { return edge_vec_.at(index); }
  T& operator[](size_t index) { return edge_vec_[index]; }

  [[nodiscard]] inline size_t  Size() const { return size; }
  inline T DistAt(const size_t src, auto dest_ptr) const {
    assert(src * size + dest_ptr.value() < size * size);
    return edge_vec_[src * size + dest_ptr.value()];
  }
  [[nodiscard]] inline T DistAt(const size_t src, const size_t dest) const {
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

 private:
  std::vector<T> edge_vec_;
  bm_mat         connection_;
  size_t         size;
};

// Constructs a N by N non-dynamic bit matrix filled with 0
template <typename T>
BitMatGraph2D<T>::BitMatGraph2D(const size_t N)
    : edge_vec_(N * N, std::numeric_limits<T>::max()),
      connection_(N, true),
      size(N) {
  for (size_t i = 0; i < N; i++) {
    connection_.construct_row(i);
    edge_vec_[i * N + i] = T(0);
  }
}

}  // namespace fpf
