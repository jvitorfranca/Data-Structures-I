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

  c = colCreate(30);
  if (c != NULL){
    printf("informe o nome, cpf e idade de alunos\n");
    for (i = 0;i < 3;i++){
      a = (Aluno*)malloc(sizeof(Aluno));
      if (a != NULL){
        scanf("%s%ld%d", a->nome, &(a->cpf), &(a->idade));
        colInsert(c, (void*)a);
      }
    }
    i = 0;
    printf("informe o cpf de dois deles para ser buscado\n");
    do{
      scanf("%ld", &cpf);
      a = colQuery(c, (void*)cpf, cmpCpfAluno);
      if (a != NULL){
        printf("%s\n%ld\n%d\n", a->nome, a->cpf, a->idade);
      } else {
        printf("não achei\n");
      }
      i++;
    }while(i < 2);
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


