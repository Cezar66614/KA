#ifndef KA_H
#define KA_H

#include "ke.h"

#include <stdint.h>

typedef struct ka_vector_struct {
  void *items;
  size_t item_size;
  size_t item_count;
  size_t dimension;
} ka_vector_t;

ka_vector_t ka_init_vector(void *items, size_t item_size, size_t *item_counts, size_t dimension_count);
void ka_free_vector(ka_vector_t *vector);

#ifdef KA_IMPL
#undef KA_IMPL

ka_vector_t ka_init_vector(void *items, size_t item_size, size_t *item_counts, size_t dimension_count) {
  ka_vector_t vector = { 0 };

  if (item_counts > 0) {
  }

  return vector;
}
void ka_free_vector(ka_vector_t *vector) {
}

#endif // KA_IMPL

#endif // KA_H
