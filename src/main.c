#define KE_IMPL
#include "ke.h" // error handling

#define KA_IMPL
#include "ka.h"

int main(void) {
  ke_init();
  ke_push_scope(true);

  ke_pop_scope();
  ke_free();
  return 0;
}
