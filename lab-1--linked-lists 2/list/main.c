#include <stdio.h>

#include "list.h"

int main() {
  printf("Tests for linked list implementation\n");
  list_t* link_l = list_alloc();
  int x;
  
  
  for(x=0;x<9;x++)
  {
    list_add_to_back(link_l,x);
     printf("Tests for linked lists:\n\n");
  }
  list_print(link_l);
  int len = list_length(link_l);
  printf("length is %d\n",len);
  
  list_add_to_front(link_l,-1);
  list_print(link_l);
  
  len = list_length(link_l);
  printf("length is %d\n",len);
  
  list_free(link_l);
  
  node_free(link_l->head);
  
  list_add_at_index(link_l, 2, 1);
   list_print(link_l);
  
  list_remove_from_back(link_l);
  printf("removed :%d from front\n",list_remove_from_front(link_l));
  list_print(link_l);
  
  
  printf("removed :%d index",list_remove_at_index(link_l,1));
  list_print(link_l);
  
  printf("element is in %d\n",list_is_in(link_l, 2));
  printf("element is at index: %d\n\n",list_get_elem_at(link_l, 2));
  printf("index with given element is at index: %d\n",list_get_index_of(link_l, 75));
  
  return 0;
}
