#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "colecao.h"

typedef struct _aluno_{
  long int cpf;
  char nome[50];
  int idade;
}Aluno;

int cmpCpfAluno(void *a, void *b);

int cmpNomeAluno(void *a, void *b);

int main(int argc, char const *argv[]) {
  Aluno *a;
  Colecao *c;
  long int cpf;
  int i = 0;
  int opcao;

  c = colCreate(30);
  if (c != NULL){
    do{
      printf("\nPRESSIONE 1 PARA INSERIR UM ALUNO \nPRESSIONE 2 PARA BUSCAR ALUNO PELO CPF \nPRESSIONE 3 PARA REMOVER O ULTIMO ALUNO \nPRESSIONE 4 PARA SAIR \n");
      scanf("%d", &opcao);
      switch (opcao){
        case 1:
          printf("Informe o nome, o cpf e a idade do aluno: \n");
          a = (Aluno*)malloc(sizeof(Aluno));
          if (a != NULL){
            scanf("%s%ld%d", a->nome, &(a->cpf), &(a->idade));
            colInsert(c, (void*)a);
          }

          break;
        case 2:
          printf("Informe o cpf de quem deseja buscar: \n");
          scanf("%ld", &cpf);
          a = colQuery(c, (void*)cpf, cmpCpfAluno);
          if (a != NULL){
            printf("%s\n%ld\n%d\n", a->nome, a->cpf, a->idade);
          } else {
            printf("cpf não encontrado");
          }

          break;
        case 3:
          colRemoveLast(c);

          break;
      }
    }while (opcao != 4);
  }
  colDestroy(c);

  return 0;
}

int cmpCpfAluno(void *a, void *b){
  int *auxA;
  Aluno *auxB;

  auxA = (int*)a;
  auxB = (Aluno*)b;

  if (auxB->cpf == auxA){
    return TRUE;
  } else {
    return FALSE;
  }
}

int cmpNomeAluno(void *a, void *b){
  char *auxA;
  Aluno *auxB;

  auxA = (char*)a;
  auxB = (Aluno*)b;

  if (strcmp(auxA, auxB->nome) == TRUE){
    return TRUE;
  } else {
    return FALSE;
  }
}
