#pragma once

// Generic Linked list node to hold data
struct Node {
  void *data_;
  struct Node *next_;
};

// Add
struct Node *linkedlist_add_head(struct Node *head, void *data);
struct Node *linkedlist_add_node(struct Node *node, void *data);

// Remove
struct Node *linkedlist_remove_node_after(struct Node *node);
struct Node *linkedlist_remove_node_at_head(struct Node *head);

void linkedlist_remove_entire_linkedlist(struct Node *head);
