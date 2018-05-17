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

#endif
