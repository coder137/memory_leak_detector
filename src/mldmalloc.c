#include "mldmalloc.h"

#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

// Constants
#define EXIT_ERROR 1

// Static function declarations
static void check_leak(void);
static void find_and_remove_node_containing(void *memory);

// Static variables
static struct Node *head = NULL;

// Initialize the memory leak detector
int mld_init(void) { return atexit(check_leak); }

// Wrappers for malloc and free
void *mld_malloc(size_t sz) {
  if (sz <= 0) {
    return NULL;
  }

  void *allocated = malloc(sz);
  if (allocated == NULL) {
    return NULL;
  }

  // * Make a memory management chain
  head = linkedlist_add_node(head, allocated);
  return allocated;
}

void mld_free(void *memory) {
  find_and_remove_node_containing(memory);
  free(memory);
}

// Static function definitions

static void find_and_remove_node_containing(void *memory) {
  if (head == NULL) {
    return;
  }

  // * First data contains allocated memory
  if (head->data_ == memory) {
    head = linkedlist_remove_node_at_head(head);
    return;
  }

  // * Otherwise iterate over head and find allocated memory
  struct Node *ptr = head->next_;
  struct Node *prev = head;
  while (ptr != NULL) {
    if (ptr->data_ == memory) {
      prev = linkedlist_remove_node_after(prev);
      break;
    }
    prev = ptr;
    ptr = ptr->next_;
  }
}

static void check_leak(void) {
  if (head == NULL) {
    printf("No memory leaks\r\n");
    return;
  }

  printf("---------------------------------\r\n");
  printf("Memory Leak detected\r\n");
  struct Node *ptr = head;
  while (ptr != NULL) {
    printf("Leak at %p\r\n", ptr->data_);
    ptr = ptr->next_;
  }
  linkedlist_remove_entire_linkedlist(head);
  printf("---------------------------------\r\n");

  // Exit with error
  exit(EXIT_ERROR);
}
