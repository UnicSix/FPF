#pragma once

#include <array>

#include "graph.hpp"

namespace fpf {
[[nodiscard]] inline consteval std::array<fpf::Edge<double>, 16>
EdgeSet6x6_0() {
  return std::array<Edge<double>, 16>{
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

// Test Case 1: Graph with negative edges but no negative cycles
[[nodiscard]] inline consteval std::array<fpf::Edge<double>, 14>
EdgeSet6x6_NegativeEdges() {
  return std::array<Edge<double>, 14>{
      Edge<double>{0, 1, 4.0},
      {0, 2, 2.0},
      {1, 2, -3.0},  // Negative edge
      {1, 3, 2.0},
      {1, 4, 3.0},
      {2, 4, 4.0},
      {2, 5, 5.0},
      {3, 2, 5.0},
      {3, 1, 1.0},
      {4, 3, -2.5},  // Negative edge
      {4, 5, -1.0},  // Negative edge
      {5, 0, 1.0},
      {5, 1, -4.2},  // Negative edge
      {5, 4, 2.8},
  };
}

// Test Case 2: Graph with a negative cycle (for negative cycle detection)
[[nodiscard]] inline consteval std::array<fpf::Edge<double>, 12>
EdgeSet5x5_NegativeCycle() {
  return std::array<Edge<double>, 12>{
      Edge<double>{0, 1, 1.0},
      {0, 2, 4.0},
      {1, 2, -3.0},  // Part of negative cycle
      {1, 3, 2.0},
      {1, 4, 2.0},
      {2, 4, 3.0},
      {3, 2, 5.0},
      {3, 1, 1.0},   // Part of negative cycle
      {4, 3, -5.0},  // Part of negative cycle (cycle: 1->2->4->3->1 = -3+3-5+1 = -4)
      {2, 0, 1.0},
      {4, 0, -1.0},  // Additional negative edge
      {0, 4, 6.0},
  };
}

// Test Case 3: Larger graph with mixed positive and negative edges
[[nodiscard]] inline consteval std::array<fpf::Edge<double>, 18>
EdgeSet7x7_MixedEdges() {
  return std::array<Edge<double>, 18>{
      Edge<double>{0, 1, 6.0},
      {0, 2, 7.0},
      {1, 2, 8.0},
      {1, 3, 5.0},
      {1, 4, -4.0},  // Negative edge
      {2, 3, -3.0},  // Negative edge
      {2, 4, 9.0},
      {3, 1, -2.0},  // Negative edge
      {3, 4, 7.0},
      {3, 5, 6.0},
      {4, 0, 2.0},
      {4, 5, -1.0},  // Negative edge
      {4, 6, 3.0},
      {5, 2, 4.0},
      {5, 6, -2.5},  // Negative edge
      {6, 0, 1.0},
      {6, 1, -3.5},  // Negative edge
      {6, 5, 8.0},
  };
}

// Test Case 4: Simple triangle with negative edge (no negative cycle)
[[nodiscard]] inline consteval std::array<fpf::Edge<double>, 6>
EdgeSet3x3_SimpleNegative() {
  return std::array<Edge<double>, 6>{
      Edge<double>{0, 1, 1.0},
      {0, 2, 4.0},
      {1, 2, -2.0},  // Negative edge
      {2, 0, 2.0},
      {1, 0, 3.0},
      {2, 1, 1.5},
  };
}

}  // namespace fpf
