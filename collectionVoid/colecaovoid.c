#ifndef _colecaovoid_c_
#define _colecaovoid_c_

#include<stdio.h>
#include<stdlib.h>
#include "colecaovoid.h"

Colecao *colCreate(int max){
  Colecao *c;

  if (max > 0){
    c = (Colecao*)malloc(sizeof(Colecao));
    if (c != NULL){
      c->elm = (void**)malloc(sizeof(void*)*max);
      if (c->elm != NULL){
        c->max = max;
        c->nelm = 0;
        printf("Colecao criada com sucesso!\n");
        return c;
      }
    }
  }
  return NULL;
}

int colDestroy(Colecao *c){
  if (c != NULL){
    if (c->elm != NULL){
      free(c->elm);
    }
    free(c);
    printf("colecao destruida\n");
    return TRUE;
  }
  return FALSE;
}

int colInsert(Colecao *c, void* item){
  if (c != NULL){
    if (c->elm != NULL){
      if (c->nelm < c->max-1){
        c->elm[c->nelm + 1] = item;
        c->nelm++;
        printf("elemento inserido\n");
        return TRUE;
      }
    }
  }
  return FALSE;
}

void *colRemoveLast(Colecao *c){
  void *itemRemovido;
  if (c != NULL){
    if (c->elm != NULL){
      if (c->nelm > 0){
        itemRemovido = c->elm[c->nelm];
        c->nelm--;
        return itemRemovido;
      }
    }
  }
  return NULL;
}

void *colQuery(Colecao *c, void *key, int(*cmp)(void*, void*)){
  int i = 0;
  if (c != NULL){
    if (c->elm != NULL){
      if (c->nelm > 0){
        while (i < c->nelm && cmp(c->elm[i], key)!=0){
          i++;
        }
        if (cmp(c->elm[i], key) == 0){
          return c->elm[i];
        }
      }
    }
  }
  return NULL;
}

// int cmp(void *data->elm[i], void *key){
//   Colecao *aux = (Colecao*) data;
//
//   if (aux->data == (int)key){
//     return TRUE;
//   }
//   return FALSE;
// }

#endif
