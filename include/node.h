#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  void *data;
  struct Node *next;
} node_t;

node_t* node_create();

int node_destroy(node_t* node);

int node_set_data(node_t* node, void* data);

int node_set_next(node_t* node, node_t* next);

int node_clear_data(node_t* node);

int node_clear_next(node_t* node);



