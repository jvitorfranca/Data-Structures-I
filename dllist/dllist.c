#ifndef _dllist_c_
#define _dllist_c_

#include<stdlib.h>
#include<stdio.h>

#define TRUE 1
#define FALSE 0

typedef struct _dlnode_{

  struct _dlnode_ *next;
  struct _dlnode_ *previous;
  void *data;

}DLNode;

typedef struct _dllist_{

  DLNode *first;

}DLList;

DLList *dllCreate(){

  DLList *list;

  list = (DLList*)malloc(sizeof(DLList));

  if (list != NULL){

    list->first = NULL;

    return list;

  }

  return NULL;

}

int dllDestroy(DLList *list){

  if (list != NULL){

    if (list->first == NULL){

      free(list);

      return TRUE;

    }

  }

  return FALSE;
}

int sllInsertAfterSpecified(DLList *list, void *data, int(*cmp)(void*, void*), void*key){

  DLNode *specified;
  DLNode *newnode;
  // DLNode *next;

  if (list != NULL){

    if (list->first != NULL){

      specified = list->first;

      while (cmp(specified->data, key) != TRUE && specified->next != NULL){

        specified = specified->next;

      }

      if (cmp(specified->data, key) == TRUE){

        newnode = (DLNode*)malloc(sizeof(DLNode));

        if (newnode != NULL){

          // next = specified->next;
          newnode->next = specified->next;
          newnode->data = data;
          newnode->previous = specified;

          if (specified->next != NULL){

            specified->next->previous = newnode;

          }

          specified->next = newnode;

          return TRUE;
        }

      }

    }

  }

  return FALSE;
}

int dllInsertBeforeSpecified(DLList *list, void *data, int(*cmp)(void*, void*), void* key){

  DLNode *specified;
  DLNode *newnode;
  DLNode *previous;

  if (list != NULL){

    if (list->first != NULL){

      specified = list->first;

      while (cmp(specified->data, key) != TRUE && specified->next != NULL){

        specified = specified->next;

      }

      if (cmp(specified->data, key) == TRUE){

        newnode = (DLNode*)malloc(sizeof(DLNode));

        if (newnode != NULL){

          newnode->data = data;
          previous = specified->previous;
          newnode->next = specified;
          newnode->previous = previous;
          specified->previous = newnode;

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

void *dllRemoveSpecified(DLList *list, void *key, int(*cmp)(void*, void*)){

  DLNode *next;
  DLNode *previous;
  DLNode *specified;

  void *data;

  if (list != NULL){

    if (list->first != NULL){

      specified = list->first;

      while (cmp(specified->data, key) != TRUE && specified->next != NULL){

        specified = specified->next;

      }

      if (cmp(specified->data, key) == TRUE){

        previous = specified->previous;
        next = specified->next;
        data = specified->data;

        if (next != NULL){

          next->previous = previous;

        }

        if (previous != NULL){

          previous->next = next;

        } else {

          list->first = next;

        }

        free(spec);

        return data;
      }

    }

  }

  return NULL;
}

void *dllGetFirst(DLList *list){

  if (list != NULL){

    if (list->first != NULL){

      list->current = list->first;

      return list->current->data;

    }

  }

  return NULL;
}

void *dllGetNext(DLList *list){

  if (list != NULL){

    if (list->current != NULL){

      list->current = list->current->next;

      return list->current->data;

    }

  }

  return NULL;
}

DLNode* dllGetSpecNode(SLList *list, void *key, int(*cmp)(void*, void*)){

  DLNode *current;

  if (list != NULL){

    if (list->first != NULL){

      current = list->first;

      while (cmp(current->data, key) != TRUE && current->next != NULL){

        current = current->next;

      }

      if (cmp(current->data, key) == TRUE){

        return current;

      }

    }

  }

  return NULL;
}

int dllRemoveSpecifiedAndNext(DLList *list, void *key, int(*cmp)(void*, void*)){

  DLNode *specified;
  DLNode *next;
  DLNode *after_next = NULL;

  if (list != NULL){

    specified = dllGetSpecNode(list, key, cmp);

    if (specified != NULL){

      previous = specified->previous;

      next = specified->next;

      if (next != NULL){

        after_next = next->next;

        free(next);

      }

      if (previous != NULL){

        previous->next = after_next;

      } else {

        list->first = after_next;

      }

      if (after_next != NULL){

        after_next->previous = previous;

      }

      free(spec);

      return TRUE;
    }

  }

  return FALSE;
}

int dllRemoveSpecifiedAndPrevious(DLList *list, void *key, int(*cmp)(void*, void*)){

  DLNode *specified;
  DLNode *before_previous;
  DLNode *previous = NULL;

  if (list != NULL){

    if (list->first != NULL){

      specified = dllGetSpecNode(list, key, cmp);

      if (specified != NULL){

        previous = specified->previous;

        if (previous != NULL){

          before_previous = previous->previous;

          free(previous);

        }

        next = specified->next;

        if (next != NULL){

          next->previous = before_previous;

        }

        if (before_previous != NULL){

          before_previous->next = next;

        } else {

          list->first = next;

        }

        free(specified);

        return TRUE;
      }

    }

  }

  return FALSE;
}

int dllRemoveOdd(DLList *list, int(*myfree)(void*)){

  DLNode *current;
  DLNode *next;
  DLNode *previous = NULL;

  if (list != NULL){

    if (list->first != NULL){

      current = list->first;

      myfree(current->data);

      while (current != NULL){

        if (current == list->first){

          list->first = current->next;

          if (list->first != NULL){

            list->first->previous = NULL;

            next = current;

            current = current->next->next;

            free(next);

          } else {

            free(current);

          }

        } else {

          previous->next = current->next;

          if (current->next != NULL){

            current->next->previous = previous;

          }

          previous = current->next;

          free(current);

          if (previous != NULL){

            current = previous->next;

          } else {

            current = NULL;

          }

        }

      }

      return TRUE;
    }

  }

  return FALSE;
}

#endif
