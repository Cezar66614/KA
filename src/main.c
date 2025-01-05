#define KE_IMPL
#include "ke.h" // error handling

#define KA_IMPL
#include "ka.h"

#include <stdio.h>

int main(void) {
  ke_init();
  ke_push_scope(true);

/* test_vec
  ka_vector test_vec = { 0 };

  KA_VECTOR_ALLOC(test_vec, 100, (unsigned long long int)0)

  #define TEST_VEC_PRINT() { \
      unsigned long long int i = 0; \
      for (i = 0; i < test_vec.count; i++) printf("%llu: %llu\n", i, ((unsigned long long int *)test_vec.data)[i]); \
      printf("\n"); \
    }
  #define TEST_VEC_FILL(val) { \
      unsigned long long int i = 0; \
      for (i = 0; i < test_vec.count; i++) ((unsigned long long int *)test_vec.data)[i] = (val); \
    }

  TEST_VEC_PRINT()

  TEST_VEC_FILL(2024)

  TEST_VEC_PRINT()

  KA_VECTOR_REALLOC(test_vec, 1000, (unsigned long long int)0)

  TEST_VEC_PRINT()

  TEST_VEC_FILL(2025)

  TEST_VEC_PRINT()

  KA_VECTOR_REALLOC(test_vec, 10, (unsigned long long int)0)

  TEST_VEC_PRINT()

  TEST_VEC_FILL(2026)

  TEST_VEC_PRINT()

  KA_VECTOR_FREE(test_vec) // -- optional letsss goooo

  TEST_VEC_PRINT()
*/

/* test_str
  ka_string test_str = { 0 };

  KA_STRING_ALLOC(test_str, 8)

  printf("%lld: %lld: %s\n", test_str.space, test_str.length, test_str.data);

  KA_STRING_CPY(test_str, "Test Test 1");

  printf("%lld: %lld: %s\n", test_str.space, test_str.length, test_str.data);

  KA_STRING_CPY(test_str, "");

  printf("%lld: %lld: %s\n", test_str.space, test_str.length, test_str.data);

  {
    KA_STRING_CAT(test_str, "Test Test ");
    KA_STRING_CAT(test_str, "1");
    printf("%lld: %lld: %s\n", test_str.space, test_str.length, test_str.data);
  }

  KA_STRING_SLICE(test_str, "Test Test 1 Test Test 12 Test Test 123 Test Test 1234 Test Test 12345 Test Test 123456", 12, 12);

  printf("%lld: %lld: %s\n", test_str.space, test_str.length, test_str.data);


  ka_string test_str2 = { 0 };

  KA_STRING_ALLOC(test_str2, 8)

  KA_STRING_CPY(test_str2, "Test Test 1234");

  KA_STRING_CAT(test_str2, test_str.data)
  KA_STRING_CAT(test_str, test_str2.data)

  printf("%lld: %lld: %s\n", test_str.space, test_str.length, test_str.data);
  printf("%lld: %lld: %s\n", test_str2.space, test_str2.length, test_str2.data);

  KA_STRING_FREE(test_str2)


  KA_STRING_FREE(test_str)
*/

  ke_pop_scope();
  ke_free();
  return 0;
}
