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
}SLList;

  #ifndef sllist_c_

    SLList *sllCreate();
    int sllDestroy(SLList *l);
    int sllInsertFirst(SLList *l, void *data);
    void *sllRemoveFirst(SLList *l);

  #else

    extern SLList *sllCreate();
    extern int sllDestroy(SLList *l);
    extern int sllInsertFirst(SLList *l, void *data);
    extern void *sllRemoveFirst(SLList *l);

  #endif
#endif
