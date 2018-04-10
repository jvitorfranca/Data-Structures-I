#ifndef cqueue_h_
#define cqueue_h_

#define TRUE 1
#define FALSE 0

typedef struct _cqueue_{
  int max;
  int beg;
  int end;
  void**elm;
  int nelms;
}CQueue;

  #ifndef cqueue_c_

    CQueue *cqCreate(int n);
    int qIncrCircular(int i, int max);
    int qDecrCircular(int i, int max);
    int cqDestroy(CQueue *cq);
    int cqEnqueue(CQueue *cq, void *elm);
    void *cqDequeue(CQueue *cq);

  #else

    extern CQueue *cqCreate(int n);
    extern int qIncrCircular(int i, int max);
    extern int qDecrCircular(int i, int max);
    extern int cqDestroy(CQueue *cq);
    extern int cqEnqueue(CQueue *cq, void *elm);
    extern void *cqDequeue(CQueue *cq);

  #endif
#endif
