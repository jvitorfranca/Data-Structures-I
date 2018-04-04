#include<stdio.h>
#include<stdlib.h>
#include "colecao.h"

int main(int argc, char const *argv[]) {
  Colecao *c;
  int i;
  int elm;
  int stat = 0;
  int opcao = 0;

  c = colCreate(30);
  if (c != NULL){
    do{
      printf("\nPRESSIONE 1 PARA INSERIR UM INT NA COLECAO \nPRESSIONE 2 PARA REMOVER UM INT \nPRESSIONE 3 PARA DESTRUIR A COLECAO\n");
      scanf("%d", &opcao);

      switch (opcao) {
        case 1:
            printf("Informe o inteiro que deseja incluir: \n");
            scanf("%d", &elm);
            colInsert(c, elm);

            break;
        case 2:
            printf("Informe o número a ser removido: \n");
            scanf("%d", &elm);
            stat = colQuery(c, elm);
            if (stat != -1){
              stat = colRemove(c, elm);
            }

            break;
      }
    }while(opcao != 3);

    colDestroy(c);
  }

  return 0;
}
