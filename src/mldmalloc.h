#pragma once

#include <stddef.h>

// Initialize the memory leak detector
int mld_init(void);

// Wrappers for malloc and free
void *mld_malloc(size_t sz);
void mld_free(void *memory);
