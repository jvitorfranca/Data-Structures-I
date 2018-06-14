#include<stdio.h>
#include<stdlib.h>

typedef struct _treenode_{

  struct _treenode_ *left;
  struct _treenode_ *right;
  void *data;

}Node;

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

        tree
        ----
         1    <-- root
       /   \
      4     5
     /  \    \
    6    7    8
