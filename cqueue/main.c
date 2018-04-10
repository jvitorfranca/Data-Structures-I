#include<stdio.h>
#include<stdlib.h>
#include "cqueue.h"

int cqPune(CQueue *cq, int n);

int cqPromove(CQueue *cq, int n);

int main(int argc, char const *argv[]) {
  CQueue *cq;
  int *elm;

  cq = cqCreate(20);
  if (cq != NULL){
    for (int i = 0;i < 10;i++){
      elm = (int*)malloc(sizeof(int));
      scanf("%d", elm);
      cqEnqueue(cq, (void*)elm);
    }
    cqPromove(cq, 9);
    // cqPune(cq, 3);
    // printf("->%d", *((int *) cqDequeue(cq)));
  }
  cqDestroy(cq);

  return 0;
}

int cqPune(CQueue *cq, int n){
  void *elm;
  int next;
  int j;
  if (cq != NULL){
    if (cq->nelms > 0 && n <= cq->nelms){
      elm = cq->elm[cq->beg];
      j = cq->beg;
      for (int i = 0;i < n;i++){
        next = qIncrCircular(j, cq->max);
        cq->elm[j] = cq->elm[next];
        j = next;
      }
      cq->elm[j] = elm;
      printf("deish\n");
      return TRUE;
    }
  }
  return FALSE;
}

int cqPromove(CQueue *cq, int n){
  void *elm;
  int next;
  int j;
  if (cq != NULL){
    if (cq->nelms > 0 && n <= cq->nelms){
      elm = cq->elm[cq->end];
      j = cq->end;
      for (int i = 0;i < n;i++){
        next = qDecrCircular(j, cq->max);
        cq->elm[j] = cq->elm[next];
        j = next;
      }
      cq->elm[j] = elm;
      printf("deish\n");
      return TRUE;
    }
  }
  return FALSE;
}
