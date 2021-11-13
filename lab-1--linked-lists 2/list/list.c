// list/list.c
// 
// Implementation for linked list.
//
// <Author>

#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

#include "list.h"

list_t *list_alloc() {
  list_t* list = (list_t*)
malloc(sizeof(list_t));
  list->head = NULL;
  return list;
  
}

node_t *node_alloc(elem v) {
  node_t* newnode = (node_t*) 
malloc(sizeof(node_t));
  newnode->value = v;
  newnode->next = NULL;
  return newnode;
  
}

void node_free(node_t *n) {
  free(n);
}

void list_free(list_t *l) {
    node_t *current = l->head;
    node_t *temp = NULL;
    while (current != NULL) 
    {
      temp = current->next;
      node_free(current);
      current = temp;
      
    }
}

void list_print(list_t *l) {
 
  node_t *current = l->head;
  while(current != NULL){
    printf("%d\n",current->value);
    current = current->next;
  } 
}

int list_length(list_t *l) { 
  int counter = 0;
  node_t *current = l->head;
  while(current != NULL) 
  {
    counter++;
    current = current->next;
  }
  return counter;
}

void list_add_to_back(list_t *l, elem value) {
  node_t *newnode;
  node_t *current = l->head;
  newnode = node_alloc(value);
  newnode->next = NULL;
  if (current == NULL) {
    
    l->head = newnode;
    printf("List is empty");
  }
  else{
    while (current->next != NULL) {
      current = current->next;
    }
   current->next = newnode;
  } 
}

void list_add_to_front(list_t *l, elem value) {
  node_t *newnode = node_alloc(value);
  node_t *head = l->head;
  // add to front
  newnode->next = head;
  l->head = newnode;

}
void list_add_at_index(list_t *l, elem value, int index) {
  //int counter = 0;
  node_t *pt = l->head;
  node_t *pre = NULL;
  node_t *newnode;
  newnode = node_alloc(value);
  
  if (index == 0) 
  {
    return list_add_to_front(l,value);
  }
  
  if (index >= list_length(l))
  {
    return list_add_to_back(l,value);
  }
  
  int count = 0;
  node_t *temp = NULL;
  node_t *current = l->head;
  
  while(count < index-1) 
  {
    current = current->next;
    count++;  
  }
  temp = current->next;
  current->next = node_alloc(value);
  current = current->next;
  current->next = temp;
  
}

elem list_remove_from_back(list_t *l) {
  node_t *pt = l->head;
  while (pt->next->next != NULL)
  {
    pt = pt->next;
  }
  node_t *temp = pt->next;
  pt->next = NULL;
  return temp->value;
   
}

elem list_remove_from_front(list_t *l) { 
  node_t *current = l->head;
  node_t *temp = current->next;
  
  l->head = temp;
  return current->value;
}
  
elem list_remove_at_index(list_t *l, int index) { 
  if (index ==0)
  {
    return list_remove_from_front(l);
  }
  if (index >= list_length(l))
  {
    return list_remove_from_back(l);
  }
  
  int count = 0;
  node_t *temp = NULL;
  node_t *current = l->head;
  while (count < index-1)
  {
     current = current->next;
     count = count+1;
   }
  //current is node before remove
  
  temp = current->next->next;
  node_t *delete = current->next;
  delete->next = NULL;
  current->next = temp;
  return delete->value;

bool list_is_in(list_t *l, elem value) { 
  node_t *current = l->head;
  while(current != NULL){
    if(current->value == value)
    {
      return true;
    }
    current = current->next;
  }
  return false; 
}

elem list_get_elem_at(list_t *l, int index) { 
  if (index < 0){
    return -1;
  }
  
  int x = 0;
  node_t *current = l->head;
  
  while (current != NULL)
  {
    if (x == index) 
    {
      return current->value;   
    }
    current = current->next;
    x = x + 1;  
  }
  return -1;
}
int list_get_index_of(list_t *l, elem value) {
  int counter = 0; 
  node_t *pt = l->head;
  while(pt != NULL) {
    if (pt->value == value)
    {
      return counter; 
    }
    counter ++;
    pt = pt->next;   
  }
  return -1; 
  }
}

 
