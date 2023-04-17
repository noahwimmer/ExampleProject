#include "linked_list.h"

void linked_list_print(linked_list_t* list) {
  // data type is int
  printf("[");
  node_t* cur = list->head;
  while(cur != NULL) {
    printf("%d ", *((int*) cur->data));
    cur = cur->next;
  }
  printf("]\n");
}

int main() {
  int a = 2;
  
  linked_list_t* list = linked_list_create();
  node_t* node = node_create();
  node_set_data(node, &a);
  linked_list_add(list, node);
  
  linked_list_print(list);
  
  return 0;
}