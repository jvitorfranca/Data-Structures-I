#ifndef colecaovoid_h_
#define colecaovoid_h_

#define TRUE 0
#define FALSE 1

typedef struct _colecao_{
  int max;
  int nelm;
  void **elm;
}Colecao;

  #ifndef colecaovoid_c_

    Colecao *colCreate(int max);
    int colDestroy(Colecao *c);
    int colInsert(Colecao *c, void* item);
    void *colRemoveLast(Colecao *c);
    void *colQuery(Colecao *c, void *key, int(*cmp)(void*, void*));
    // int cmp(void *data, void *key);

  #else

    extern Colecao *colCreate(int max);
    extern int colDestroy(Colecao *c);
    extern int colInsert(Colecao *c, void* item);
    extern void *colRemoveLast(Colecao *c);
    extern void *colQuery(Colecao *c, void *key, int(*cmp)(void*, void*));

  #endif
#endif
