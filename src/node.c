#include "node.h"

node_t* node_create() {
  node_t *node = malloc(sizeof(node_t));
  if (!node) {
    fprintf(stderr,
            "Could not allocate resources for new node. Returning NULL...\n");
    return NULL;
  }

  node->data = NULL;
  node->next = NULL;

  return node;
}

int node_destroy(node_t* node) {
  if(!node) {
    fprintf(stderr, "Error: Node pointer is NULL.\n");
    return -1;
  }

  free(node);

  return 0;
}

int node_set_data(node_t* node, void* data) {
  if(!node) {
    fprintf(stderr, "Error: Node pointer is NULL.\n");
    return -1;
  }

  node->data = data;

  return 0;
}

int node_set_next(node_t* node, node_t* next) {
  if(!node) {
    fprintf(stderr, "Error: Node pointer is NULL.\n");
    return -1;
  }

  node->next = next;

  return 0;
}

int node_clear_data(node_t* node) {
  if(!node) {
    fprintf(stderr, "Error: Node pointer is NULL.\n");
    return -1;
  }

  node->data = NULL;

  return 0;
}

int node_clear_next(node_t* node) {
  if(!node) {
    fprintf(stderr, "Error: Node pointer is NULL.\n");
    return -1;
  }

  node->data = NULL;

  return 0;
}