#define KE_IMPL
#include "ke.h" // error handling

#define KA_IMPL
#include "ka.h"

#include <stdio.h>

int main(void) {
  ke_init();

  ke_push_scope(1);

  printf("Hello, World!\n");

  ke_pop_scope();

  ke_free();
  return 0;
}
