#ifndef sllist_h_
#define sllist_h_

#define TRUE 1
#define FALSE 0

typedef struct _slnode_{

  struct _slnode_ *next;
  void *data;

}SLNode;

typedef struct _sll_{

  SLNode *first;
  SLNode *current;

}SLList;

  #ifndef sllist_c_

    SLList *sllCreate();

    SLList *sllIntercala(SLList *list1, SLList *list2);

    int sllDestroy(SLList *l);

    int sllInsertFirst(SLList *l, void *data);

    int sllInsertLast(SLList *list, void *data);

    int sllNumNodes(SLList *list);

    int sllInsertBeforeSpecified(SLList *list, void *key, int(*cmp)(void*, void*), void *data);

    int sllInsertAfterSpecified(SLList *list, void *key, int(*cmp)(void*, void*), void *data);

    int sllNumOcc(SLList *list, void *key, int(*cmp)(void*, void*));

    int sllRemoveSpecifiedNext(SLList *list, void *key, int(*cmp)(void*, void*));

    int sllRemoveSpecifiedPrevious(SLList *list, void *key, int(*cmp)(void*, void*));

    void *sllNext(SLList *list);

    void *sllRemoveFirst(SLList *l);

    void* sllGetFirst(SLList*list);

    void *sllRemoveSpecified(SLList *list, void *key, int(*cmp)(void*, void*));

    void *sllQuery(SLList *list, void *key, int(*cmp)(void*, void*));

    void *sllRemoveNth(SLList *list, int n);

  #else

    extern SLList *sllCreate();

    extern SLList *sllIntercala(SLList *list1, SLList *list2);

    extern int sllDestroy(SLList *l);

    extern int sllInsertFirst(SLList *l, void *data);

    extern int sllInsertLast(SLList *list, void *data);

    extern int sllNumNodes(SLList *list);

    extern int sllInsertBeforeSpecified(SLList *list, void *key, int(*cmp)(void*, void*), void *data);

    extern int sllInsertAfterSpecified(SLList *list, void *key, int(*cmp)(void*, void*), void *data);

    extern int sllNumOcc(SLList *list, void *key, int(*cmp)(void*, void*));

    extern int sllRemoveSpecifiedNext(SLList *list, void *key, int(*cmp)(void*, void*));

    extern int sllRemoveSpecifiedPrevious(SLList *list, void *key, int(*cmp)(void*, void*));

    extern void *sllNext(SLList *list);

    extern void *sllRemoveFirst(SLList *l);

    extern void* sllGetFirst(SLList*list);

    extern void *sllRemoveSpecified(SLList *list, void *key, int(*cmp)(void*, void*));

    extern void *sllQuery(SLList *list, void *key, int(*cmp)(void*, void*));

    extern void *sllRemoveNth(SLList *list, int n);

  #endif
#endif
