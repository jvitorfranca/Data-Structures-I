#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "dllist.h"

typedef struct _students_{

  char name[2000];
  long int registration;
  float coeficient;

}Student;

int cmpStudentName(void* data, void* key){
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

int cmpStudentRegistration(void* data, void *key){
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

int cmpStudentCoeficient(void* data, void* key){
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
  DLList *list = NULL;

  Student *new_student;

  void* data_removed = NULL;
  void* data_query = NULL;

  char name[20];

  int option = 0;
  int status = 0;

  while (option != 10){

    printf("==================================================\n");
    printf("=     1. Create a list.                          =\n");
    printf("=     2. Destroy the list.                       =\n");
    printf("=     3. Insert after specified.                 =\n");
    printf("=     4. Insert before specified.                =\n");
    printf("=     5. Remove specified and next.              =\n");
    printf("=     6. Remove specified and previous.          =\n");
    printf("=     7. Remove specified.                       =\n");
    printf("=     8. Get first.                              =\n");
    printf("=     9. Insert specified.                       =\n");
    printf("=     10. Exit.                                  =\n");
    printf("==================================================\n");

    scanf("%d", &option);

    switch (option){
      case 1:

        if (list == NULL){
          list = dllCreate();

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

          status = dllDestroy(list);

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

          printf("Inform the name: \n");

          scanf("%s", name);

          if (new_student != NULL){

            status = dllInsertAfterSpecified(list, (void*)new_student, (*cmpStudentName),(void*)name);

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

          printf("Inform the name: \n");

          scanf("%s", name);

          if (new_student != NULL){

            status = dllInsertBeforeSpecified(list, (void*)new_student, (*cmpStudentName), (void*)name);

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

      case 5:

        printf("inform the name of the student you're trying to remove \n");
        scanf("%s", name);

        status = dllRemoveSpecifiedAndNext(list, (void*)name, cmpStudentName);

        if (status == 1){

          printf("element removed \n");

        } else {

          printf("something's wrong \n");

        }

        break;

      case 6:

        printf("inform the name of the student you're trying to remove \n");
        scanf("%s", name);

        status = dllRemoveSpecifiedAndPrevious(list, (void*)name, cmpStudentName);

        if (status == 1){

          printf("element removed \n");

        } else {

          printf("something's wrong \n");

        }

        break;

      case 7:

        data_removed = NULL;

        printf("inform the name of the student you're trying to remove \n");
        scanf("%s", name);

        data_removed = dllRemoveSpecified(list, (void*)name, cmpStudentName);

        if (data_removed != NULL){

          printf("element removed \n");

        } else {

          printf("something's wrong \n");

        }

        break;

      case 8:

        new_student = (Student *) dllGetFirst(list);

        if (new_student != NULL){

          getStudent(new_student);

        }

        break;

      case 9:

        if (list != NULL){

          new_student = setStudent();

          if (new_student != NULL){

            status = dllInsertLast(list, (void*)new_student);

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

    }

    // system("clear");

  }

}
