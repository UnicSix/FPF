#pragma once
#include <cstdio>
#include <exception>
#include <format>
#include <iostream>
#include <span>
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
  print("Bit matrix:\n");
  for (bm::bvector_size_type i = 0; i < N; i++) {
    for (bm::bvector_size_type j = 0; j < N; j++) {
      print("{:b} ", mat.connection_.get_row(i)->get_bit(j));
    }
    print("\n");
  }
  // Output edges
  print("Edges:\n");
  for (size_t i = 0; i < N * N; i++) {
    print("{:<3},{}", mat.edge_vec_[i], (i % N == (N - 1) ? "\n" : " "));
  }
  print("\n");
}

template <typename T>
void PrintContainer(std::span<T> cont) {
  for (auto val : cont) {
    print("{} ", val);
  }
  print("\n");
}
}  // namespace util

}  // namespace fpf
