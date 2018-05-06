/*

  singly-linked list algorithm implement to Data Structures I class

  compiled in a linux terminal with gcc main.c sllist.c -o main && ./main

*/

#include<stdlib.h>
#include<stdio.h>
#include "sllist.h"

int main(int argc, char const *argv[]) {
  SLList *list;

  unsigned int entry1 = 10;
  unsigned int entry2 = 7;
  unsigned int lenght = 0;

  void* first_removed = NULL;
  void* nth_removed = NULL;

  list = sllCreate();

  if (list != NULL){

    sllInsertFirst(list, (void*)&entry1);
    sllInsertLast(list, (void*)&entry2);

    lenght = sllNumNodes(list);

    printf("%d\n", lenght);

    first_removed = sllRemoveFirst(list);

    if (first_removed != NULL){
      printf("%s\n", "first removed");
    }

    nth_removed = sllRemoveNth(list, 0);

    if (nth_removed != NULL){
      printf("%s\n", "nth removed");
    }

  }

  sllDestroy(list);

  return 0;
}
