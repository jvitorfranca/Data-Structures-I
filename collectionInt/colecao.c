#ifndef _colecao_c_
#define _colecao_c_

#include<stdio.h>
#include<stdlib.h>
#include "colecao.h"

Colecao *colCreate(int n){
  Colecao *c;
  if (n > 0){
    c = (Colecao*)malloc(sizeof(Colecao));
    if (c != NULL){
      c->elm = (int*)malloc(sizeof(int)*n);
      if (c->elm != NULL){
        c->max = n;
        c->nelm = 0;
        printf("coleção alocada\n");
        return c;
      }
    }
  }
  return NULL;
}

int colDestroy(Colecao *c){
  if (c != NULL){
    if (c->nelm == 0){
      if (c->elm != NULL){
        free(c->elm);
      }
      free(c);
      return TRUE;
    }
  }
  return FALSE;
}

int colInsert(Colecao *c, int elm){
  if (c != NULL){
    if (c->nelm < c->max - 1){
      c->elm[c->nelm] = elm;
      c->nelm++;
      printf("elemento inserido \n");
      return TRUE;
    }
  }
  return FALSE;
}

int colQuery(Colecao *c, int key){
  int i;
  if (c != NULL){
    if (c->nelm > 0){
      i = 0;
      while (i < c->nelm && c->elm[i] != key){
        i++;
      }
      if (c->elm[i] == key){
        printf("elemento encontrado! \n");
        return c->elm[i];
      }
    }
  }
  printf("nao achou \n");
  return -1;
}

int colRemove(Colecao *c, int key){
  int i;
  int elm;
  if (c != NULL){
    if (c->nelm > 0){
      i = 0;
      while (i < c->nelm && c->elm[i] != key){
        i++;
      }
      if (c->elm[i] == key){
        elm = c->elm[i];
        for (;i < c->nelm - 1;i++){
          c->elm[i] = c->elm[i+1];
        }
        c->nelm--;
        printf("removendo... \n");
        return elm;
      }
    }
  }
  return -1;
}

#endif
