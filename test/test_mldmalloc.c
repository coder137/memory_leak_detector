#include <stdio.h>
#include <stdlib.h>

#include "mldmalloc.h"

int main() {
  mld_init();

  void *a1 = mld_malloc(10);
  void *a2 = mld_malloc(20);

  printf("a1 %p\r\n", a1);
  printf("a2: %p\r\n", a2);

  // NOTE, For testing comment of the free values
  mld_free(a2);
  mld_free(a1);

  return 0;
}
