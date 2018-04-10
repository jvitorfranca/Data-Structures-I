#ifndef _cqueue_c_
#define _cqueue_c_

#include<stdio.h>
#include<stdlib.h>
#include "cqueue.h"

int qIncrCircular(int i, int max){
  if (i < max - 1){
    i++;
  } else {
    i = 0;
  }
  return i;
}

int qDecrCircular(int i, int max){
  if (i > 0){
    i--;
  } else {
    i = max - 1;
  }
  return i;
}

CQueue *cqCreate(int n){
  CQueue *cq;
  if (n > 0){
    cq = (CQueue*)malloc(sizeof(CQueue));
    if (cq != NULL){
      cq->elm = (void**)malloc(sizeof(void*)*n);
      if (cq->elm != NULL){
        cq->max = n;
        cq->beg = 0;
        cq->end = -1;
        cq->nelms = 0;
        printf("Cq criada\n");
        return cq;
      }
      free(cq);
    }
  }
  return NULL;
}

int cqDestroy(CQueue *cq){
  if (cq != NULL){
    if (cq->elm != NULL){
      free(cq->elm);
      free(cq);
      printf("destruindo cq\n");
      return TRUE;
    }
  }
  return FALSE;
}

int cqEnqueue(CQueue *cq, void *elm){
  if (cq != NULL){
    if (cq->nelms < cq->max){
      cq->end = qIncrCircular(cq->end, cq->max);
      cq->elm[cq->end] = elm;
      cq->nelms++;
      printf("elemento inserido\n");
      return TRUE;
    }
  }
  return FALSE;
}

void *cqDequeue(CQueue *cq){
  void *elm;
  if (cq != NULL){
    if (cq->nelms > 0){
      elm = cq->elm[cq->beg];
      cq->beg = qIncrCircular(cq->beg, cq->max);
      cq->nelms--;
      return elm;
    }
  }
  return NULL;
}

#endif
