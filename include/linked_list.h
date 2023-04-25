#include "node.h"

typedef struct LinkedList {
  node_t* head;
  size_t size;
} linked_list_t;

/**
 *  Creates a new Linked List, ready for use.
 */
linked_list_t* linked_list_create();

/**
 * Destroys the linked list, along with all of its data
 */
int linked_list_destroy(linked_list_t** list);

// adds at end
int linked_list_add(linked_list_t* list, node_t* node);

// adds node at position index
int linked_list_add_index(linked_list_t* list, node_t* node, size_t index);

int linked_list_remove_index(linked_list_t* list, size_t index);

int linked_list_remove_node(linked_list_t* list, node_t* node, size_t data_size);

node_t* linked_list_get_index(linked_list_t* list, size_t index);

node_t* linked_list_peek_front(linked_list_t* list);

node_t* linked_list_peek_back(linked_list_t* list);

node_t* linked_list_pop_front(linked_list_t* list);

node_t* linked_list_pop_back(linked_list_t* list);
