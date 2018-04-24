#include<stdio.h>
#include<stdlib.h>
#include "cqueue.h"

typedef struct _stack_{
  int max;
  int top;
  void**elm;
}Stack;

Stack *stkCreate(int max){
  Stack *s;
  if (max > 0){
    s = (Stack*)malloc(sizeof(Stack));
    if (s != NULL){
      s->elm = (void**)malloc(sizeof(void*)*max);
      if (s->elm != NULL){
        s->max = max;
        s->top = -1;
        return s;
      }
      free(s);
    }
  }
  return NULL;
}

int stkDestroy(Stack *s){
  if (s != NULL){
    if (s->top == -1){
      if (s->elm != NULL){
        free(s->elm);
      }
      free(s);
    }
    printf("Stack destoyed succesfully\n");
    return TRUE;
  }
  return FALSE;
}

int stkPush(Stack *s, void* elm){ //inserir (empilhar)
  if (s != NULL){
    if (s->top < s->max - 1){
      s->top++;
      s->elm[s->top] = elm;
      printf("element pushed succesfully\n");
      return TRUE;
    }
  }
  return FALSE;
}

void *stkPop(Stack *s){ //remover (desempilhar)
  void *top;
  if (s != NULL){
    if (s->top >= 0){
      top = s->elm[s->top];
      s->top--;
      return top;
    }
  }
  return NULL;
}

void *stkTop(Stack *s){
  void *top;
  if (s != NULL){
    if (s->top >= 0){
      top = s->elm[s->top];
      return top;
    }
  }
  return NULL;
}

int cqPune(CQueue *cq, int n);

int cqPromove(CQueue *cq, int n);

int cqPuneStack(CQueue *cq, int n);

int cqPromoveStack(CQueue *cq, int n);

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

int cqPuneStack(CQueue *cq, int n){
  Stack *stk;
  void *elm;
  int i, j;

  stk = stkCreate(n);
  if (cq != NULL){
    if (cq->nelms > 0 && n <= cq->nelms){
      elm = cq->elm[cq->beg]
      j = cq->beg;
      for (i = 0;i < n;i++){
        j = qIncrCircular(j, cq->max);
        stkPush(stk, &cq->elm[j]);
      }
      //j = cq->beg;
      for (i = 0;i < n;i++){
        cqEnqueue(cq, stkPop(stk));
        // j = qIncrCircular(j, cq->max);
      }
      cq->elm[j] = elm;
    }
  }
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
