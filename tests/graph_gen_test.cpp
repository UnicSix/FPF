#include <cassert>
#include <iostream>

#include "graph.hpp"
#include "graph_factory.hpp"

int main() {
  auto gen1 = fpf::GenMatrixGraph<5, 5>();

  auto ans1 = fpf::Mat2x2<5, 5>();

  for (auto set : ans1.matrix) {
    std::cout << set << "\n";
  }
  std::cout << "============\n";
  for (auto set : gen1.matrix) {
    std::cout << set << "\n";
  }

  assert(gen1 == ans1);
}
