#pragma once

namespace fpf {
void Test();
[[nodiscard]] int Add(int a, int b, int c);

template<typename T>
auto Mult(T x1, T x2, T x3) {
  return x1 * x2 * x3;
}
}  // namespace fpf
