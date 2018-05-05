#ifndef _sllist_c_
#define _sllist_c_

#include<stdlib.h>

SLList *sllCreate(){
  SLList *list;
  list = (SLList*)malloc(sizeof(SLList));
  if (list != NULL){
    list->first = NULL;
    list->current = NULL;
    return list;
  }
  return NULL;
}

void* sllFirst(SLList*list){
  if (list != NULL){
    if (list->first != NULL){
      l->current = l->first;
      return l->current->data;
    }
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
      aux = list->first;
      data = aux->data;
      list->first = aux->next;
      free(aux);
      return data;
    }
  }
  return NULL;
}

void *sllRemoveSpecified(SLList *list, void *key, int(*cmp)(void*, void*)){
  SLNode *current;
  SLNode *previous;

  void *data;

  if (list != NULL){
    if (list->first != NULL){
      current = list->first;
      previous = NULL;
      while (cmp(key, current->data) != TRUE && current->next != NULL){
        previous = current;
        current = current->next;
      }
      if (cmp(key, current->data == TRUE)){
        if (previous != NULL){
          previous->next = current->next;
        } else {
          list->first = current->next;
        }
        data = current->data;
        free(current);
        return data;
      }
    }
  }
  return NULL;
}

int sllInsertBeforeSpecified(SLList *list, void *key, int(*cmp)(void*, void*), void *data){
  SLNode *current;
  SLNode *previous;
  SLNode *newnode;

  if (list != NULL){
    if (list->first != NULL){
      current = list->first;
      previous = NULL;
      while (cmp(key, current->data) != TRUE && current->next != NULL){
        previous = current;
        current = current->next;
      }
      if (cmp(key, current->data) == TRUE){
        newnode = (SLNode*)malloc(sizeof(SLNode));
        if (newnode != NULL){
          newnode->data = data;
          newnode->next = current->next;
          if (previous != NULL){
            previous->next = newnode;
          } else {
            list->first = newnode;
          }
          return TRUE;
        }
      }
    }
  }
  return FALSE;
}

int sllInsertAfterSpecified(SLList *list, void *key, int(*cmp)(void*, void*), void *data){
  SLNode *newnode;
  SLNode *current;

  if (list != NULL){
    if (list->first != NULL){
      current = list->first;
      while (cmp(key, current->data) != TRUE && current->next != NULL){
        current = current->next;
      }
      if (cmp(key, current->data) == TRUE){
        newnode = (SLNode*)malloc(sizeof(SLNode));
        if (newnode != NULL){
          newnode->data = data;
          newnode->next = current->next;
          current->next = newnode;
          return TRUE;
        }
      }
    }
  }
  return FALSE;
}

void *sllQuery(SLList *list, void *key, int(*cmp)(void*, void*)){
  SLNode *current;

  if (list != NULL){
    current = list->first;
    while (cmp(key, current->data) && current->next != NULL){
      current = current->next;
    }
    if (cmp(key, current->data) == TRUE){
      return current->data;
    }
  }
  return NULL;
}

int sllNumOcc(SLList *list, void *key, int(*cmp)(void*, void*)){
  SLNode *current;
  unsigned int n;
  if (list != NULL){
    if (list->first != NULL){
      current = list->first;
      while (current != NULL){
        if (cmp(current->data, key) == TRUE){
          n++;
        }
        current = current->next;
      }
      return n;
    }
  }
  return -1;
}

void *sllRemoveNth(SLList *list, int n){
  SLNode *current;
  SLNode *previous;
  void *data;
  if (list != NULL){
    if (list->first != NULL){
      current = list->first;
      previous = NULL;
      while (n > 0 && current != NULL){
        previous = current;
        current = current->next;
        n--;
      }
      if (current != NULL){
        data = current->data;
        if (previous != NULL){
          previous->next = current->next;
        } else {
          list->first = current->next;
        }
        free(current);
        return data;
      }
    }
  }
  return NULL;
}

int sllRemoveSpecifiedNext(SLList *list, void *key, int(*cmp)(void*, void*)){
  SLNode *current;
  SLNode *previous;
  SLNode *next;

  if (list != NULL){
    if (list->first != NULL){
      previous = NULL;
      current = list->first;
      while (cmp(current->data, key) != TRUE && current->next != NULL){
        previous = current;
        current = current->next;
      }
      if (cmp(current->data, key) == TRUE){
        if (previous != NULL){
          if (current->next != NULL){
            previous->next = current->next->next;
            free(current->next);
          } else {
            previous->next != NULL;
          }
          free(current);
        } else {
          if (current->next != NULL){
            list->first = current->next->next;
            free(current->next);
          } else {
            list->first = NULL;
          }
          free(current);
        }
        return TRUE;
      }
    }
  }
  return FALSE;
}

int sllRemoveSpecifiedPrevious(SLList *list, void *key, int(*cmp)(void*, void*)){
  SLNode *current;
  SLNode *previous;
  SLNode *next;
  SLNode *p_previous;

  if (list != NULL){
    if (list->first != NULL){
      p_previous = NULL;
      previous = NULL;
      current = list->first;

      while (cmp(current->data, key) != TRUE && current->next != NULL){
        p_previous = previous;
        previous = current;
        current = current->next;
      }
      if (cmp(current->data, key) == TRUE){
        if (p_previous != NULL){
          p_previous->next = current->next;
        } else {
          list->first = current->next;
        }
        if (previous != NULL){
          free(p_previous);
          free(current);
          return TRUE;
        }
        return TRUE;
      }
    }
  }
  return FALSE;
}

#endif
