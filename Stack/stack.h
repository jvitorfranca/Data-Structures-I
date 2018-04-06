#ifndef stack_h_
#define stack_h_

#define TRUE 1
#define FALSE 0

typedef struct _stack_{
  int max;
  int top;
  void**elm;
}Stack;

  #ifndef stack_c_

    Stack *stkCreate(int max);
    int stkDestroy(Stack *s);
    int stkPush(Stack *s, void*elm);
    void *stkPop(Stack *s);
    void *stkPop(Stack *s);

  #else

    extern Stack *stkCreate(int max);
    extern int stkDestroy(Stack *s);
    extern int stkPush(Stack *s, void*elm);
    extern void *stkPop(Stack *s);
    extern void *stkPop(Stack *s);

  #endif
#endif
