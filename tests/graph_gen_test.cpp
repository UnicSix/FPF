#include <cassert>
#include <cstdlib>
#include <exception>
#include <iostream>

#include "bm.h"
#include "bmbmatrix.h"
#include "bmsparsevec.h"
#include "bmsparsevec_serial.h"
#include "bmundef.h" /* clear the pre-proc defines from BM */
#include "graph.hpp"
#include "graph_factory.hpp"

typedef bm::basic_bmatrix<bm::bvector<>>         bmatr_32;
typedef bm::sparse_vector_serializer<bmatr_32>   bmb_serializer_type;
typedef bm::sparse_vector_deserializer<bmatr_32> bmb_deserializer_type;

int main() {
  try {
    bm::basic_bmatrix<bm::bvector<>> bmatr0(0);
    for (unsigned i = 0; i < 100; i += 1) {
      bmatr_32::bvector_type* bv = bmatr0.construct_row(i);
      for (unsigned j = 0; j < 150; j += 1) bv->set(j);
    }  // for i
    bmatr0.optimize();  // optimize all bit-vectors
    bm::bvector<>::enumerator en     = bmatr0.row(0)->first();
    bm::bvector<>::enumerator en_end = bmatr0.row(0)->end();
    for (; en < en_end; ++en) {
      std::cout << en.value() << " ";
    }
    std::cout << "\n";

    bmatr_32::bvector_type bv_mask;  // AND vector [10..100]...[200..210]
    bv_mask.set_range(29, 47);

    for (unsigned i = 0; i < bmatr0.rows(); ++i) {
      if (bmatr_32::bvector_type* bv = bmatr0.get_row(i)) bv->bit_and(bv_mask);
    }
    en     = bmatr0.row(0)->first();
    en_end = bmatr0.row(0)->end();
    for (; en < en_end; ++en) {
      std::cout << en.value() << " ";
    }
    std::cout << "\n";
    // assert(gen1 == ans1);
  } catch (std::exception& e) {
    std::cout << "Exception: " << e.what() << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
