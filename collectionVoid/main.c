#include<stdio.h>
#include<stdlib.h>
#include "colecaovoid.h"
#include "colecaovoid.c"

int main(int argc, char const *argv[]) {
  Colecao *c;
  int elm;
  int stat = 0;
  int *pelm;

  c = colCreate(30);
  if (c != NULL){
    for (int i = 0;i < 5;i++){
      pelm = (int*)malloc(sizeof(int));
      printf("informe os elementos\n");
      scanf("%d",&pelm);
      colInsert(c, (void*)pelm);
    }
    while (pelm != NULL){
      pelm = (int *)colRemoveLast(c);
      printf("%d\n",pelm);
    }
    colDestroy(c);
  }

  return 0;
}
