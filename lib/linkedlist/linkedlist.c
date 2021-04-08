#include "linkedlist.h"

#include <stddef.h>
#include <stdlib.h>

struct Node *linkedlist_add_head(struct Node *head, void *data) {
  struct Node *temp = malloc(sizeof(struct Node) * 1);
  if (temp == NULL) {
    return head;
  }

  if (head == NULL) {
    temp->data_ = data;
    temp->next_ = NULL;

    head = temp;
  } else {
    temp->data_ = data;
    temp->next_ = head;
    head = temp;
  }

  return head;
}

struct Node *linkedlist_add_node(struct Node *node, void *data) {
  struct Node *temp = malloc(sizeof(struct Node) * 1);
  if (temp == NULL) {
    return node;
  }

  if (node == NULL) {
    temp->data_ = data;
    temp->next_ = NULL;
    node = temp;
  } else {
    struct Node *next = node->next_;
    temp->data_ = data;
    node->next_ = temp;
    temp->next_ = next;
  }

  return node;
}

struct Node *linkedlist_remove_node_after(struct Node *node) {
  if (node == NULL || node->next_ == NULL) {
    return node;
  }

  struct Node *rnode = node->next_;
  node->next_ = rnode->next_;
  free(rnode);
}

struct Node *linkedlist_remove_node_at_head(struct Node *head) {
  struct Node *next = head->next_;
  free(head);
  return next; // This can be NULL
}

void linkedlist_remove_entire_linkedlist(struct Node *head) {
  while (head != NULL) {
    struct Node *current = head;
    head = head->next_;
    free(current);
  }
}
