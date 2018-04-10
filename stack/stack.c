#ifndef _stack_c_
#define _stack_c_

#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

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

#endif
