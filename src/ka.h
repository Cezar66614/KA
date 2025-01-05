#ifndef KA_H
#define KA_H

#include <stdlib.h>
#include <string.h>
#include "ke.h"

typedef struct ka_vector_struct {
  void *data;
  unsigned long long int count;
} ka_vector;

#define KA_VECTOR_ALLOC(vec, num, type) { \
    (vec).data = NULL, (vec).count = 0; \
    if ((num) > 0) { \
      (vec).data = calloc((num), sizeof((type))); \
      if ((vec).data == NULL) KE_ERROR("ERROR: KA failed allocating memory."); \
      (vec).count = (num); \
      ke_push_elem(&(vec), ka_vector_free); \
    } \
  }

#define KA_VECTOR_REALLOC(vec, num, type) { \
    if ((num) > 0) { \
      void *temp = realloc((vec).data, (num) * sizeof((type))); \
      if (temp == NULL) KE_ERROR("ERROR: KA failed re-allocating memory."); \
      (vec).data = temp; \
      if ((num) > (vec).count) memset((vec).data + (vec).count * sizeof((type)), 0, ((num) - (vec).count) * sizeof((type))); \
      (vec).count = (num); \
    } \
  }

#define KA_VECTOR_FREE(vec) { \
    if ((vec).count > 0) free((vec).data); \
    (vec).data = NULL; \
    (vec).count = 0; \
  }

void ka_vector_free(void *);

#ifdef KA_IMPL

void ka_vector_free(void *vec) { KA_VECTOR_FREE(*((ka_vector *)vec)) }

#endif // KA_IMPL


typedef struct ka_string_struct {
  char *data;
  unsigned long long int space, length;
} ka_string;

#define KA_STRING_ALLOC(str, len) { \
    (str).data = NULL, (str).space = (str).length = 0; \
    if ((len) > 0) { \
      (str).data = calloc((len), sizeof(char)); \
      if ((str).data == NULL) KE_ERROR("ERROR: KA failed allocating memory."); \
      (str).space = (len); \
      ke_push_elem(&(str), ka_string_free); \
    } \
  }
#define KA_STRING_REALLOC(str, len) { \
    if ((len) > 0) { \
      void *temp = realloc((str).data, (len) * sizeof(char)); \
      if (temp == NULL) KE_ERROR("ERROR: KA failed re-allocating memory."); \
      (str).data = temp; \
      if ((len) > (str).space) memset((str).data + (str).space * sizeof(char), '\0', ((len) - (str).space) * sizeof(char)); \
      else { \
        if ((len) <= (str).length) { \
          (str).length = (len) - 1; \
          (str).data[(str).length] = '\0'; \
        } \
      } \
      (str).space = (len); \
    } \
  }
#define KA_STRING_FREE(str) { \
    if ((str).space > 0) free((str).data); \
    (str).data = NULL; \
    (str).space = (str).length = 0; \
  }

void ka_string_free(void *);

#ifdef KA_IMPL

void ka_string_free(void *str) { KA_STRING_FREE(*((ka_string *)str)) }

#endif // KA_IMPL

#define KA_BEST_SIZE(size) { \
    unsigned long long int power = 0; \
    if ((size) < 64) while ((size) > power) power += 8; \
    else if ((size <= 128)) while ((size) > power) power += 16; \
    else while ((size) > power) power += 64; \
    (size) = power; \
  }

#define KA_STRING_CPY(dst, src) { \
    unsigned long long int src_size = strlen((src)); \
    if ((dst).space <= src_size + 1) { \
      unsigned long long int new_size = src_size + 1; KA_BEST_SIZE(new_size) \
      KA_STRING_REALLOC(dst, new_size) \
      } \
    \
    unsigned long long int i; \
    for (i = 0; i < src_size; i++) (dst).data[i] = (src)[i]; \
    memset((dst).data + i * sizeof(char), '\0', ((dst).space - i) * sizeof(char)); \
    (dst).length = src_size; \
  }

#define KA_STRING_CAT(dst, src) { \
    unsigned long long int src_size = strlen((src)); \
    if ((dst).space <= (dst).length + src_size + 1) { \
      unsigned long long int new_size = (dst).length + src_size + 1; KA_BEST_SIZE(new_size) \
      KA_STRING_REALLOC(dst, new_size) \
      } \
    \
    unsigned long long int i; \
    for (i = (dst).length; i < (dst).length + src_size; i++) (dst).data[i] = (src)[i - (dst).length]; \
    memset((dst).data + i * sizeof(char), '\0', ((dst).space - i) * sizeof(char)); \
    (dst).length += src_size; \
  }

#define KA_STRING_SLICE(dst, src, start, size) { \
    if ((dst).space <= (size) + 1) { \
      unsigned long long int new_size = (size) + 1; KA_BEST_SIZE(new_size) \
      KA_STRING_REALLOC(dst, new_size) \
      } \
    \
    unsigned long long int i; \
    for (i = 0; i < (size); i++) (dst).data[i] = (src)[i + (start)]; \
    memset((dst).data + i * sizeof(char), '\0', ((dst).space - i) * sizeof(char)); \
    (dst).length = (size); \
  }

#ifdef KA_IMPL
#undef KA_IMPL
#endif // KA_IMPL

#endif // KA_H
