#pragma once

#include <array>

#include "graph.hpp"

namespace fpf {
[[nodiscard]] inline consteval std::array<fpf::Edge<double>, 18>
EdgeSet6x6_0() {
  return std::array<Edge<double>, 18>{
      Edge<double>{0, 1, 1.2},
      {0, 2, 2.3},
      {0, 4, 3.1},
      {1, 0, 2.8},
      {1, 2, 1.9},
      {1, 5, 4.5},
      {2, 0, 1.7},
      {2, 1, 3.3},
      {2, 3, 2.1},
      {3, 1, 1.8},
      {3, 4, 2.9},
      {3, 5, 3.7},
      {4, 0, 2.4},
      {4, 5, 1.6},
      {5, 2, 3.8},
      {5, 3, 1.3},
  };
}

}  // namespace fpf
