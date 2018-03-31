#ifndef colecao_h_
#define colecao_h_

#define TRUE 0
#define FALSE 1

typedef struct _colecao_{
  int *elm;
  int max;
  int nelm;
}Colecao;

  #ifndef colecao_c_

    Colecao *colCreate(int n);
    int colDestroy(Colecao *c);
    int colInsert(Colecao *c, int elm);
    int colQuery(Colecao *c, int key);
    int colRemove(Colecao *c, int key);

  #else

    extern Colecao *colCreate(int n);
    extern int colDestroy(Colecao *c);
    extern int colInsert(Colecao *c, int elm);
    extern int colQuery(Colecao *c, int key);
    extern int colRemove(Colecao *c, int key);

  #endif
#endif
