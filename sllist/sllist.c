#ifndef _sllist_c_
#define _sllist_c_

#include<stdlib.h>

SLList *sllCreate(){
  SLList *l;
  l = (SLList*)malloc(sizeof(SLList));
  if (l != NULL){
    l->first = NULL;
    return l;
  }
  return NULL;
}

int sllDestroy(SLList *l){
  if (l->first == NULL){
    free(l);
    return TRUE;
  }
  return FALSE;
}

int sllInsertFirst(SLList *l, void *data){
  SLNode *newnode;
  if (l != NULL){
    newnode = (SLNode*)malloc(sizeof(SLNode));
    if (newnode != NULL){
      newnode->data = data;
      newnode->next = l->first;
      l->first = newnode;
      return TRUE;
    }
  }
  return FALSE;
}

void *sllRemoveFirst(SLList *l){
  SLNode *aux;
  void *data;
  if (l != NULL){
    if (l->first != NULL){
      aux = l->first;
      data = aux->data;
      l->first = aux->next;
      free(aux);
      return data;
    }
  }
  return NULL;
}

#endif
