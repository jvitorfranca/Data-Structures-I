#ifndef dllist_h_
#define dllist_h_

#define TRUE 1
#define FALSE 0

typedef struct _dlnode_{

  struct _dlnode_ *next;
  struct _dlnode_ *previous;
  void *data;

}DLNode;

typedef struct _dllist_{

  DLNode *first;

}DLList;

  #ifndef dllist_c_

    DLList *dllCreate();

    int dllDestroy(DLList *list);

    int dllInsertLast(DLList *list, void *data);

    int dllInsertAfterSpecified(DLList *list, void *data, int(*cmp)(void*, void*), void*key);

    int dllInsertBeforeSpecified(DLList *list, void *data, int(*cmp)(void*, void*), void* key);

    int dllRemoveSpecifiedAndNext(DLList *list, void *key, int(*cmp)(void*, void*));

    int dllRemoveSpecifiedAndPrevious(DLList *list, void *key, int(*cmp)(void*, void*));

    int dllRemoveOdd(DLList *list, int(*myfree)(void*));

    void *dllRemoveSpecified(DLList *list, void *key, int(*cmp)(void*, void*));

    void *dllGetFirst(DLList *list);

    void *dllGetNext(DLList *list);

    DLNode* dllGetSpecNode(DLList *list, void *key, int(*cmp)(void*, void*));


  #else

    extern DLList *dllCreate();

    extern int dllDestroy(DLList *list);

    extern int dllInsertLast(DLList *list, void *data);

    extern int sllInsertAfterSpecified(DLList *list, void *data, int(*cmp)(void*, void*), void*key);

    extern int dllInsertBeforeSpecified(DLList *list, void *data, int(*cmp)(void*, void*), void* key);

    extern int dllRemoveSpecifiedAndNext(DLList *list, void *key, int(*cmp)(void*, void*));

    extern int dllRemoveSpecifiedAndPrevious(DLList *list, void *key, int(*cmp)(void*, void*));

    extern int dllRemoveOdd(DLList *list, int(*myfree)(void*));

    extern void *dllRemoveSpecified(DLList *list, void *key, int(*cmp)(void*, void*));

    extern void *dllGetFirst(DLList *list);

    extern void *dllGetNext(DLList *list);

    extern DLNode* dllGetSpecNode(DLList *list, void *key, int(*cmp)(void*, void*));

  #endif

#endif
