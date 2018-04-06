#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

int Palindromo(char *s, int n){
  Stack *stk;
  char *c;
  int i;

  stk = stkCreate(n);
  if (stk != NULL){
    for (i = 0;i < n;i++){
      stkPush(stk, (void*)&s[i]);
    }
    i = 0;
    c = (char*)stkPop(stk);
    while (c != NULL){
      if(*c != s[i]){
        while(stkPop(stk)!=NULL){
        }
        stkDestroy(stk);
        return FALSE;
      }
      i++;
      c = (char*)stkPop(stk);
    }
    stkDestroy(stk);
    return TRUE;
  }
  return FALSE;
}

int main(int argc, char const *argv[]) {
  char *s;
  int n;
  int i;

  printf("informe o tamanho da palavra: \n");
  scanf("%d",&n);

  s = (char*)malloc(sizeof(char)*n);
  if (s != NULL){
      scanf("%s",s);
      printf("%s\n", s);
  }

  if (Palindromo(s, n) == 1){
    printf("é um palindromo\n");
  } else {
    printf("não é um palindromo\n");
  }

  return 0;
}
