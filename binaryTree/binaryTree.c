/*
  Implementing a binary Tree, with the function:
    1. Create
    2. Destroy
    3. Insert
    4. Remove
    5. Query

  Wrote by: jvitorfranca

     tree
     ----
      1    <-- root
     / \
    4   5
   / \   \
  6   7   8

*/

#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct _treenode_{

  struct _treenode_ *left;
  struct _treenode_ *right;
  void *data;

}Node;

Node* BSTreeCreate(){

  Node *root;

  root = (Node*)malloc(sizeof(Node));

  if (root != NULL){

    root->left = NULL;
    root->right = NULL;

    return root;

  }

  return NULL;
}

int BSTreeDestroy(Node *root){

  if (root->left == NULL && root->right == NULL){

    free(root);

    return TRUE;

  } else {

    return FALSE;

  }

}

Node *BSTreeInsert(Node *root, void *data, void* key, int(*cmp)(void*, void*)){

  Node *newnode;

  if (root != NULL){

    if (cmp(key, root->data) <= 0){

      root->left = BSTreeInsert(root->left, data, key, cmp);

    } else {

      root->right = BSTreeInsert(root->right, data, key, cmp);

    }

    return root;

  } else {

    newnode = (Node*)malloc(sizeof(Node));

    if (newnode != NULL){

      newnode->left = NULL;
      newnode->right = NULL;
      newnode->data = data;

      return newnode;

    }

    return NULL;
  }

}

void *BSTreeQuery(Node* root, void* key, int(*cmp)(void*, void*)){

  if (root != NULL){

    if (cmp(key, root->data) == 0){

      return root->data;

    } else if (cmp(key, root->data) < 0){

      return BSTreeQuery(root->left, key, cmp);

    } else {

      return BSTreeQuery(root->right, key, cmp);

    }

  }

  return NULL;

}

void *BSTreeBigger(Node *root){

  void *data;

  if (root != NULL){

    while (root->right != NULL){

      data = root->data;

      root = root->right;

    }

    return data;
  }

  return NULL;
}

Node *BSTreeRemove(Node *root, void *key, int(*cmp)(void*, void*)){

  Node *aux;

  void *data;

  if (root != NULL){

    if (cmp(key, root->data) == -1){

      root->left = BSTreeRemove(root->left, key, cmp);

      return root;

    } else if (cmp(key, root->data) == 1){

      root->right = BSTreeRemove(root->right, key, cmp);

      return root;

    } else {

      data = root->data;

      if (root->left == NULL && root->right == NULL){

        free(root);

        return NULL;

      } else if (root->left != NULL && root->right == NULL){

        aux = root->left;

        free(root);

        return aux;

      } else if (root->left == NULL && root->right != NULL){

        aux = root->right;

        free(root);

        return aux;

      } else {

        root->data = BSTreeBigger(root->left);

        BSTreeRemove(root->left, root->data, cmp);

        return root;

      }

    }

  }

  return NULL;
}

int cmp(void *key, void* data){

  int *a;
  int *b;

  a = (int*)key;
  b = (int*)data;

  if (b < a){

    return -1;

  } else if(b > a){

    return 1;

  } else {

    return 0;

  }

}

void treePreOrdem(Node *root, int(*visit)(void*)){

  if (root != NULL){

    visit(root->data);
    treePreOrdem(root->left, visit);
    treePreOrdem(root->right, visit);

  }

}

void treePosOrdem(Node *root, int(*visit)(void*)){

  if (root != NULL){

    treePosOrdem(root->left, visit);
    treePosOrdem(root->right, visit);
    visit(root->data);

  }

}

void treeSimetria(Node *root, int(*visit)(void*)){

  if (root != NULL){

    treePosOrdem(root->left, visit);
    visit(root->data);
    treePosOrdem(root->right, visit);

  }

}

void visit(void* data){

  int aux;

  if (data != NULL){

    aux = (int)data;

    printf("%d\n", aux);

  }

}

int main(int argc, char const *argv[]) {

  int menuOption;
  int data;

  void* query = NULL;
  void* aux = NULL;

  Node *root;

  do{

    printf("%s\n", "=========================");
    printf("%s\n", " 1. Create a Binary Tree ");
    printf("%s\n", " 2. Insert a element     ");
    printf("%s\n", " 3. Query a element      ");
    printf("%s\n", " 4. Remove a element     ");
    printf("%s\n", " 5. Destroy              ");
    printf("%s\n", " 6. Exit                 ");
    printf("%s\n", "=========================");

    printf("%s\n", "Please, select a option: ");
    scanf("%d", &menuOption);

    switch (menuOption) {

      case 1:

        root = BSTreeCreate();

        if (root != NULL){

          printf("%s\n", "Created successfully");

        } else {

          printf("%s\n", "Something went wrong");

        }

        break;
      case 2:

        printf("%s\n", "Insert the integer you want to add");

        scanf("%d", &data);

        root = BSTreeInsert(root, (void*)data, (void*)data, cmp);

        if (root != NULL){

          printf("%s\n", "Element inserted");

        } else {

          printf("%s\n", "Something went wrong");

        }

        break;
      case 3:

        printf("%s\n", "Insert the integer you want to query: ");

        scanf("%d", &data);

        query = BSTreeQuery(root, (void*)data, cmp);

        if (cmp(query, (void*)data) == 0){

          printf("%s\n", "Found");

        } else {

          printf("%s\n", "Not found");

        }

        break;
      case 4:

        printf("%s\n", "Insert the integer you want to delete: ");

        scanf("%d", &data);

        root = BSTreeRemove(root, (void*)data, cmp);

        break;
      case 5:

        if (BSTreeDestroy(root) == TRUE){

          printf("%s\n", "The tree was destroyed");

        } else {

          printf("%s\n", "Something went wrong");

        }

        break;
      default:

        break;
    }

  }while(menuOption != 6);

  return 0;
}
