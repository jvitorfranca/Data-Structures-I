/*

  singly-linked list algorithm implement to Data Structures I class, implemented with a structure "students"

  compiled in a linux terminal with gcc main.c sllist.c -o main && ./main

*/

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "sllist.h"

typedef struct _students_{

  char name[2000];
  long int registration;
  float coeficient;

}Student;

int cmpStudentName(void* key, void* data){
  char *name;
  Student *new_student;

  name = (char*)key;
  new_student = (Student*)data;

  if (strcmp(name, new_student->name) == 0){

    return TRUE;

  } else {

    return FALSE;

  }
}

int cmpStudentRegistration(void *key, void* data){
  int *registration;
  Student *new_student;

  registration = (int*)key;
  new_student = (Student*)data;

  if (*registration == new_student->registration){

    return TRUE;

  } else {

    return FALSE;

  }
}

int cmpStudentCoeficient(void* key, void* data){
  float *coeficient;
  Student *new_student;

  coeficient = (float*)key;
  new_student = (Student*)data;

  if (*coeficient == new_student->coeficient){

    return TRUE;

  } else {

    return FALSE;

  }
}

Student* setStudent(){

  Student* new_student;
  new_student = (Student*)malloc(sizeof(Student));

  if (new_student != NULL){

    printf("Inform the student's name: \n");
    scanf("%s", new_student->name);
    printf("Inform the student's registration: \n");
    scanf("%ld", &new_student->registration);
    printf("Inform the student's coeficient: \n");
    scanf("%f", &new_student->coeficient);

    return new_student;
  } else {

    printf("new student was not accepted");

  }
  return NULL;
}

void getStudent(Student *new_student){

  if (new_student != NULL){

    printf("Name: %s | Registration: %ld | Coeficient: %f |\n", new_student->name, new_student->registration, new_student->coeficient);

  }
}

int main(int argc, char const *argv[]) {
  SLList *list = NULL;

  Student *new_student;

  int option = 0;
  int status;

  while (option != 17){

    printf("==================================================\n");
    printf("=     1. Create a list.                          =\n");
    printf("=     2. Destroy the list.                       =\n");
    printf("=     3. Insert in the first position.           =\n");
    printf("=     4. Insert in the last position.            =\n");
    printf("=     5. Insert before specified.                =\n");
    printf("=     6. Insert after specified.                 =\n");
    printf("=     7. Get the first.                          =\n");
    printf("=     8. Get the next.                           =\n");
    printf("=     9. Get the number of nodes.                =\n");
    printf("=     10. Remove the first.                      =\n");
    printf("=     11. Remove a specific node.                =\n");
    printf("=     12. Remove the nth node.                   =\n");
    printf("=     13. Remove specified next.                 =\n");
    printf("=     14. Remove specified previous.             =\n");
    printf("=     15. Search on the list.                    =\n");
    printf("=     16. Get the number of occurencies.         =\n");
    printf("=     17. Exit.                                  =\n");
    printf("==================================================\n");

    scanf("%d", &option);

    switch (option){
      case 1:

        if (list == NULL){
          list = sllCreate();

          if (list != NULL){

            printf("list created succesfully\n");

          } else {

            printf("list was not created\n");

          }
        } else {

          printf("the list was already created\n");

        }

        break;
      case 2:

        if (list != NULL){

          status = sllDestroy(list);

          if (status == TRUE) {

            printf("list destroyed succesfully\n");

          } else {

            printf("list was not destroyed \n");

          }

        } else {

          printf("the list is NULL\n");

        }

        break;
      case 3:

        if (list != NULL){

          new_student = setStudent();

          if (new_student != NULL){

            status = sllInsertFirst(list, (void*)new_student);

            if (status){

              printf("element inserted \n");

            } else {

              printf("element not inserted \n");

            }

          }

        } else {

          printf("There is no list \n");

        }
        break;

      case 4:

        if (list != NULL){

          new_student = setStudent();

          if (new_student != NULL){

            status = sllInsertLast(list, (void*)new_student);

            if (status){

              printf("element inserted\n");

            } else {

              printf("element not inserted\n");

            }

          }

        } else {

          printf("There is no list \n");

        }

        break;

      // case 5:
      //
      // case 6:
      //
      // case 7:
      //
      // case 8:
      //
      // case 9:
      //
      // case 10:
      //
      // case 11:
      //
      // case 12:
      //
      // case 13:
      //
      // case 14:
      //
      // case 15:
      //
      // case 16:
      //
      // default:

    }

    // system("clear");

  }

  // unsigned int entry1 = 10;
  // unsigned int entry2 = 7;
  // unsigned int lenght = 0;
  //
  // void* first_removed = NULL;
  // void* nth_removed = NULL;
  //
  // list = sllCreate();
  //
  // if (list != NULL){
  //
  //   sllInsertFirst(list, (void*)&entry1);
  //   sllInsertLast(list, (void*)&entry2);
  //
  //   lenght = sllNumNodes(list);
  //
  //   printf("%d\n", lenght);
  //
  //   first_removed = sllRemoveFirst(list);
  //
  //   if (first_removed != NULL){
  //     printf("%s\n", "first removed");
  //   }
  //
  //   nth_removed = sllRemoveNth(list, 0);
  //
  //   if (nth_removed != NULL){
  //     printf("%s\n", "nth removed");
  //   }
  //
  // }
  //
  // sllDestroy(list);
  //
  // return 0;
}
