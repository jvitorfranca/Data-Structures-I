#ifndef _sllist_c_
#define _sllist_c_

#include<stdlib.h>
#include<stdio.h>
#include "sllist.h"

SLList *sllCreate(){

  SLList *list;
  list = (SLList*)malloc(sizeof(SLList));

  if (list != NULL){

    list->first = NULL;
    list->current = NULL;
    printf("%s","list created succesfully\n");
    return list;

  }

  return NULL;

}

void* sllGetFirst(SLList*list){

  if (list != NULL){

    if (list->first != NULL){

      list->current = list->first;

      return list->current->data;

    }
  }

  return NULL;

}

int sllDestroy(SLList *list){

  if (list->first == NULL){

    printf("%s", "list destroyed succesfully\n");
    free(list);
    return TRUE;

  }

  return FALSE;
}

int sllInsertFirst(SLList *list, void *data){

  SLNode *newnode;

  if (list != NULL){

    newnode = (SLNode*)malloc(sizeof(SLNode));

    if (newnode != NULL){

      newnode->data = data;
      newnode->next = list->first;
      list->first = newnode;

      printf("%s", "element pushed succesfully\n");

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

      if (list->first != NULL){

        last = list->first;

        while (last->next != NULL){
          last =  last->next;
        }

        last->next = newnode;

      } else {

        list->first = newnode;

      }

      printf("%s", "element pushed succesfully\n");

      return TRUE;

    }
  }

  return FALSE;

}

int sllNumNodes(SLList *list){

  SLNode *aux;

  unsigned int lenght;

  if (list != NULL){

    if (list->first != NULL){

      aux = list->first;

      lenght = 1;

      while (aux->next != NULL){

        lenght++;
        aux = aux->next;

      }

      return lenght;

    }
  }

  return FALSE;

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

void *sllNext(SLList *list){

  SLNode *current;

  if (list != NULL){

    if (list->current != NULL){

      current = list->current;

      list->current = current->next;

      return list->current->data;
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

      if (cmp(key, current->data) == TRUE){

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
          newnode->next = current->next; //ou current?

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

    while (cmp(key, current->data) != TRUE && current->next != NULL){

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

SLList *sllIntercala(SLList *list1, SLList *list2){

  SLList *list3;
  SLNode *current1;
  SLNode *next1;
  SLNode *current2;
  SLNode *next2;

  if (list1 != NULL && list2 != NULL){

    list3 = sllCreate();

    if (list3 != NULL){

      if (list1->first != NULL){

        current1 = list1->first;
        next1 = current1->next;

        if (list2->first != NULL){

          current2 = list2->first;
          next2 = current2->next;

          while (current1 != NULL && current2 != NULL){

            current1->next = current2;
            current2->next = next1;
            current1 = next1;
            current2 = next2;

            if (next1 != NULL){

              next1 = next1->next;

            }

            if (next2 != NULL){

              next2 = next2->next;
            }

            return list3;
          }
        }
      }
    }
  }

  return NULL;
}

#endif
