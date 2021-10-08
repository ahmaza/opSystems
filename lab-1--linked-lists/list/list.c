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
  list_t* list = (list_t*);
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
void list_free(list_t *l) {
  node_t *pt = 1->head;
  if (pt == NULL)
    printf("List is empty");
  
  while (pt != NULL) {
    node_t *temp = pt -> next;
    free(pt);
    pt = temp;
  }
}
void node_free(node_t *n) {
  free(n);
}
void list_print(list_t *l) {
 
  node_t *current = l->head;
  if (current == NULL)
    printf("List is empty");
  
  while(current != NULL){
    printf("%d ", current->value);
    current = current->next;
  }
}
int list_length(list_t *l) { 
  int counter = 1;
  node_t *pt = 1->head;
  while(pt != NULL) {
    counter++;
    pt = pt->next;
  }
  return counter;
}

void list_add_to_back(list_t *l, elem value) {
  node_t *newnode;
  node_t *pt = 1->head;
  newnode = node_alloc(value);
  if (pt == NULL)
    printf("List is empty");
  while (pt->next != NULL) {
    pt = pt->next;
  }
  pt->next = newnode;
  newnode->next = NULL;
}

void list_add_to_front(list_t *l, elem value) {
  node_t *newnode;
  newnode = node_alloc(value);
  node_t *head = 1->head;
  // add to front
  newnode->next = head;
  1->head=newnode;
}
void list_add_at_index(list_t *l, elem value, int index) {
  int counter = 0;
  node_t *pt = 1->head;
  node_t *pre = NULL;
  node_t *newnode;
  newnode = node_alloc(value);
  
  if (index == 0)
    return list_add_to_front(1,value);
  
  if (pt == NULL)
    while (count < index)
    {
      pre = pt;
      pt = pt->next;
      counter++;
    }
  prev->next = newnode;
  newnode->next = pt;
}

elem list_remove_from_back(list_t *l) {
  node_t *pt = 1->head;
  if (pt == NULL)
    printf("List is empty");
  while(pt->next != NULL)
  {
    pt = pt->next;
  }
  
  elem last = pt->value;
  free(pt);
  return last;
}
elem list_remove_from_front(list_t *l) { 
  
  
}
elem list_remove_at_index(list_t *l, int index) { 
  int counter = 0;
  node_t *pt = 1->head;
  if (pt == NULL)
    printf("list is empty");
    return;
  node_t *temp = l->head;
  while (temp->next != NULL && counter < index)
  {
    temp = temp->next;
    counter++;  
  }
  node_t *remove = temp->next;
  elem v = temp->next->value;
  temp->next = temp->next->next;
  free(remove);
  return v;
}

bool list_is_in(list_t *l, elem value) { 
  node_t *curr = l->head;
  while(curr != NULL){
    if(curr->value == value)
    {
      return true;
    }
    curr = curr->next;
  }
  return false; 
}

elem list_get_elem_at(list_t *l, int index) { 
  int x = 0;
  node_t *curr = 1->head;
  while (curr != NULL)
  {
    if (x == index) 
    {
      return curr->value;   
    }
    curr = curr->next;
    x = x + 1;  
  }
  return -1;
}
int list_get_index_of(list_t *l, elem value) {
  int counter = 0; 
  node_t *pt = l->head;
  if (pt == NULL)
    return ;
  while(pt != NULL) {
    if (pt->value == value){
      return counter; }
    counter ++;
    pt = pt -> next;   
  }
  return -1; 
}

