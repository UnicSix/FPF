#pragma once
#include <cstdio>
#include <exception>
#include <format>
#include <iostream>
#include <limits>
#include <span>
#include <string>

#include "graph.hpp"

template <typename T>
struct std::formatter<fpf::Edge<T>> {
  constexpr auto parse(std::format_parse_context& ctx) { return ctx.begin(); }
  auto format(const fpf::Edge<T>& edge, std::format_context& ctx) const {
    return std::format_to(ctx.out(), "start: {}, end: {}, dist: {}", edge.v1,
                          edge.v2, edge.dist);
  }
};

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

inline void println(const char* fmt, auto&&... args) {
  try {
    std::string temp = std::vformat(fmt, std::make_format_args(args...)) + "\n";
    fwrite(temp.c_str(), sizeof(char), temp.size(), stdout);
  } catch (std::exception& ex) {
    std::cerr << ex.what();
  }
}

template <typename T>
inline void PrintGraph(BitMatGraph2D<T> mat) {
  size_t     N   = mat.Size();
  const auto INF = std::numeric_limits<T>::max();
  // Output matrix
  print("Bit matrix:\n");
  for (bm::bvector_size_type i = 0; i < N; i++) {
    for (bm::bvector_size_type j = 0; j < N; j++) {
      print("{:b} ", mat.GetRow(i)->get_bit(j));
    }
    print("\n");
  }
  // Output edges
  print("Edges:\n");
  for (size_t i = 0; i < N * N; i++) {
    if (mat[i] == INF) {
      print("{:<5},{}", "INF", (i % N == (N - 1) ? "\n" : " "));
    }
    else {
      print("{:<5},{}", mat[i], (i % N == (N - 1) ? "\n" : " "));
    }
  }
  print("\n");
}

template <typename T>
inline void PrintContainer(const std::span<T>& container,
                           std::string&&       delimiter = " ") {
  const auto INF = std::numeric_limits<T>::max();
  for (auto&& val : container) {
    if (val == INF)
      print("{:<5}{}", "INF", delimiter);
    else
      print("{:<5}{}", val, delimiter);
  }
  print("\n");
}
}  // namespace util

}  // namespace fpf
