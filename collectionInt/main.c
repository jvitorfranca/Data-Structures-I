#include<stdio.h>
#include<stdlib.h>
#include "colecao.c"
#include "colecao.h"

int main(int argc, char const *argv[]) {
  Colecao *c;
  int i;
  int elm;
  int stat = 0;

  c = colCreate(30);
  if (c != NULL){
    printf("informe 5 digitos: \n");
    for (i = 0;i < 5;i++){
      scanf("%d",&elm);
      colInsert(c, elm);
    }
    while (stat != -1){
      printf("Informe o numero a ser removido, por obséquio: \n");
      scanf("%d",&elm);
      stat = colQuery(c, elm);
      if (stat != -1){
        stat = colRemove(c, elm);
      }
    }
    printf("destruindo coleção \n");
    colDestroy(c);
  }

  return 0;
}
