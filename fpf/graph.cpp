#include "graph.hpp"

namespace fpf {
// Constructs a w1 by w2 non-dynamic bit matrix filled with 0
BitMatGraph2D::BitMatGraph2D(size_t N)
    : matrix(N, false), size(N), edge(N * N, 0) {
  for (size_t i = 0; i < N; i++) {
    [[maybe_unused]] auto row = matrix.construct_row(i);
  }
}

}  // namespace fpf
