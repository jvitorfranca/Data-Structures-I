#ifndef _sllist_c_
#define _sllist_c_

#include<stdlib.h>

SLList *sllCreate(){
  SLList *list;
  list = (SLList*)malloc(sizeof(SLList));
  if (list != NULL){
    list->first = NULL;
    return list;
  }
  return NULL;
}

int sllDestroy(SLList *list){
  if (list->first == NULL){
    free(list);
    return TRUE;
  }
  return FALSE;
}

int sllInsertFirst(SLList *list, void *data){
  SLNode *newnode;
  if (l != NULL){
    newnode = (SLNode*)malloc(sizeof(SLNode));
    if (newnode != NULL){
      newnode->data = data;
      newnode->next = list->first;
      list->first = newnode;
      return TRUE;
    }
  }
  return FALSE;
}

int sllInsertLast(SLList *list, void *data){
  SLNode *newnode;
  SLNode *last;
  if (list != NULL){
    newnode = (SLNode*)malloc(sizeof(SLNode));
    if (newnode != NULL){
      newnode->next = NULL;
      newnode->data = data;
      if (l->first != NULL){
        last = list->first;
        while (last->next != NULL){
          last =  last->next;
        }
        last->next = newnode;
      } else {
        list->first = newnode;
      }
      return TRUE;
    }
  }
  return FALSE;
}

int sllNumNodes(SLList *list){
  SLNode *aux;
  unsigned int lenght;
  lenght = 0;
  if (list != NULL){
    if (list->first != NULL){
      aux = list->first;
      while (aux->next != NULL){
        lenght++;
        aux = aux->next;
      }
      return lenght;
    }
  }
  return NULL;
}

void *sllRemoveFirst(SLList *list){
  SLNode *aux;
  void *data;
  if (list != NULL){
    if (list->first != NULL){
      aux = lit->first;
      data = aux->data;
      list->first = aux->next;
      free(aux);
      return data;
    }
  }
  return NULL;
}

#endif
