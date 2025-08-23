#pragma once
#include <array>
#include <cstdio>
#include <exception>
#include <format>
#include <iostream>
#include <ostream>
#include <string>

#include "graph.hpp"

namespace fpf {
namespace util {

inline void print(const char* fmt, auto&&... args) {
  try {
    std::string temp = std::vformat(fmt, std::make_format_args(args...));
    fwrite(temp.c_str(), sizeof(char), temp.size(), stdout);
  } catch (std::exception& ex) {
    std::cerr << ex.what();
  }
}

template <typename T>
inline void PrintGraph(BitMatGraph2D<T> mat) {
  size_t N = mat.Size();
  // Output matrix
  std::cout << "Bit matrix:\n";
  for (bm::bvector_size_type i = 0; i < N; i++) {
    for (bm::bvector_size_type j = 0; j < N; j++) {
      std::cout << mat.connection_.get_row(i)->get_bit(j) << " ";
    }
    std::cout << std::endl;
  }
  // Output edges
  std::cout << "Edges:\n";
  for (size_t i = 0; i < N * N; i++) {
    std::cout << mat.edge_vec_[i] << (i % N == (N - 1) ? "\n" : " ");
  }
  std::cout << std::endl;
}

template <typename T, size_t size>
void PrintArray(std::array<T, size> arr) {
  for (auto val : arr) {
    std::cout << val << " ";
  }
  std::cout << std::endl;
}
}  // namespace util

}  // namespace fpf
