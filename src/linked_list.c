#include "linked_list.h"
#include <stdarg.h>
#include <string.h>

linked_list_t* linked_list_create() {
  linked_list_t* list = malloc(sizeof(linked_list_t));
  if(!list) {
    fprintf(stderr, "Could not allocate resources for linked list. Returning NULL...\n");
    return NULL;
  }

  list->head = NULL;
  list->size = 0;

  return list;
}

int linked_list_destroy(linked_list_t* list) {
  if(!list) {
    fprintf(stderr, "Error: List pointer is NULL.\n");
    return -1;
  }

  while(list->size > 0) {
    linked_list_remove_index(list, 0);
  }

  free(list);

  return 0;
}

// adds at end
int linked_list_add(linked_list_t* list, node_t* node) {
  if(!list) {
    fprintf(stderr, "Error: LinkedList list is NULL. Returning NULL...\n");
    return -1;
  }
  
  if(!node) {
    fprintf(stderr, "Error: Attemping to add NULL node_t to list. Returning -1...\n");
    return -1;
  }
  
  if(list->size == 0) {
    list->head = node;
    return 0;
  }
  
  node_t* end = linked_list_peek_back(list);
  end->next = node;
  
  return 0;
}

// adds node at position index
int linked_list_add_index(linked_list_t* list, node_t* node, size_t index) {
  if(!list) {
    fprintf(stderr, "Error: LinkedList list is NULL. Returning NULL...\n");
    return -1;
  }
  
  if(!node) {
    fprintf(stderr, "Error: Attemping to add NULL node_t to list. Returning -1...\n");
    return -1;
  }
  
  if(index > list->size) {
    if(index > list->size) {
      fprintf(stderr, "Error: index [%zu] is out of range for linked list size [%zu]. Returning -1...\n", index, list->size);
      return -1;
    }
  }
  
  if(index == 0) {
    node->next = list->head;
    list->head = node;
    return 0;
  } else {
    node_t* prev = linked_list_get_index(list, index-1);
    node->next = prev->next;
    prev->next = node;
    return 0;
  }
}

int linked_list_remove_index(linked_list_t* list, size_t index) {
  if(!list) {
    fprintf(stderr, "Error: LinkedList list is NULL. Returning NULL...\n");
    return -1;
  }

  if(index > list->size) {
    if(index > list->size) {
      fprintf(stderr, "Error: index [%zu] is out of range for linked list size [%zu]. Returning -1...\n", index, list->size);
      return -1;
    }
  }
  
  node_t* temp;
  
  if(index == 0) {
    temp = list->head;
    list->head = temp->next;
    free(temp);
    return 0;
  } else {
    node_t* prev = linked_list_get_index(list, index-1);
    temp = prev->next;
    prev->next = temp->next;
    free(temp);
    return 0;
  }
}

int linked_list_remove_node(linked_list_t* list, node_t* node, size_t data_size) {
    node_t* prev = list->head;
    node_t* cur = prev->next;
    
    // Remove if the first element matches
    if(memcmp(node->data, prev->data, data_size) == 0) {
      node_t* temp = prev;
      list->head = temp->next;
      free(temp);
      return 0;
    }
    
    while(memcmp(cur->data, node->data, data_size) != 0) {
      if(!cur) {
        fprintf(stderr, "Could not find node in list. Returning -1...\n");
        return -1;
      }
      prev = prev->next;
      cur = cur->next;
    }
    
    prev->next = cur->next;
    free(cur);
    return 0;
}

node_t* linked_list_get_index(linked_list_t* list, size_t index) {
  if(!list) {
    fprintf(stderr, "Error: LinkedList list is NULL. Returning NULL...\n");
    return NULL;
  }
  
  if(index > list->size) {
    fprintf(stderr, "Error: index [%zu] is out of range for linked list size [%zu]. Returning NULL...\n", index, list->size);
    return NULL;
  }
  
    node_t* cur = list->head;
    size_t count = 0;
    while(count < index) {
      cur = cur->next;
    }
    
    return cur;
}

node_t* linked_list_peek_front(linked_list_t* list) {
  if(!list) {
    fprintf(stderr, "Error: LinkedList list is NULL. Returning NULL...\n");
    return NULL;
  }
  
  return list->head;
}

node_t* linked_list_peek_back(linked_list_t* list) {
  if(!list) {
    fprintf(stderr, "Error: LinkedList list is NULL. Returning NULL...\n");
    return NULL;
  }
  
  if(list->size == 0) {
    fprintf(stderr, "Error: No nodes exist in list. Returning NULL...\n");
    return NULL;
  }
  
  return linked_list_get_index(list, list->size - 1);
}

node_t* linked_list_pop_front(linked_list_t* list) {
  if(!list) {
    fprintf(stderr, "Error: LinkedList list is NULL. Returning NULL...\n");
    return NULL;
  }
  
  node_t* temp = list->head;
  list->head = list->head->next;
  free(temp);
  return 0;
}

node_t* linked_list_pop_back(linked_list_t* list) {
  if(!list) {
    fprintf(stderr, "Error: LinkedList list is NULL. Returning NULL...\n");
    return NULL;
  }
  
  if(list->size == 1) {
    node_t* temp = list->head;
    list->head = NULL;
    return temp;
  }
  
  // Get second to last node
  node_t* new_last = linked_list_get_index(list, list->size - 2);
  node_t* temp = new_last->next;
  new_last->next = NULL;
  return temp;
}