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
#define FALSE 2

typedef struct _treenode_{

  struct _treenode_ *left;
  struct _treenode_ *right;
  void *data;

}Node;

Node* binaryTreeCreate(){

  Node *root;

  root = (Node*)malloc(sizeof(Node));

  if (root != NULL){

    root->left = NULL;
    root->right = NULL;

    return root;

  }

  return NULL;
}

int binaryTreeDestroy(Node *root){

  if (root->left == NULL && root->right == NULL){

    free(root);

    printf("%s\n", "Tree destroyed successfully");

    return TRUE;

  } else {

    printf("%s\n", "Please, remove all the elements");

    return FALSE;

  }

}

Node *binaryTreeInsert(Node *root, void *data, void* key, int(*cmp)(void*, void*)){

  Node *newnode;

  if (root != NULL){

    if (cmp(key, root->data) <= 0){

      root->left = binaryTreeInsert(root->left, data, key, cmp);

    } else {

      root->right = binaryTreeInsert(root->right, data, key, cmp);

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

void *binaryTreeQuery(Node* root, void* key, int(*cmp)(void*, void*)){

  if (root != NULL){

    if (cmp(key, root->data) == 0){

      return root->data;

    } else if (cmp(key, root->data) < 0){

      return binaryTreeQuery(root->left, key, cmp);

    } else {

      return binaryTreeQuery(root->right, key, cmp);

    }

  }

  return NULL;

}

void *binaryTreeRemove(Node *root, void *key, int(*cmp)(void*, void*), void **data){

  Node *aux;

  void *data;

  if (root != NULL){

    if (cmp(key, root->data) == -1){

      root->left = binaryTreeRemove(root->left, key, cmp);

      return root;

    } else if (cmp(key, root->data) == 1){

      root->right = binaryTreeRemove(root->right, key, cmp);

    } else {

      *data = root->data;

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

        root->data = binaryTreeMaior(root->left);

        binaryTreeRemove(root->left, root->data, cmp, &data);

        return t;

      }

    }

  }

  return NULL;
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
