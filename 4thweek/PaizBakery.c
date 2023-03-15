#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

typedef struct bstnode_t {
    int key;
      struct bstnode_t *left, *right;
}     BSTNode;

typedef struct bst_result
{
      double value1;
      double value2;
}     hasil;

typedef struct bst_t {
      BSTNode *_root;
      unsigned int _size;
} BST;

BSTNode* __bst__createNode(int value) {
  BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
  newNode->key = value;
  newNode->left = newNode->right = NULL;
  return newNode;
}

BSTNode* __bst__insert(BSTNode *root, int value) {
  if (root == NULL)
    return __bst__createNode(value);

  if (value < root->key)
    root->left = __bst__insert(root->left, value);
  
  else if (value > root->key)
      root->right = __bst__insert(root->right, value);
  
  return root;
}

BSTNode* __bst__search(BSTNode *root, int value) {
  while (root != NULL) {
    if (value < root->key)
      root = root->left;
    else if (value > root->key)
      root = root->right;
    else
      return root;
  }
  return root;
}

BSTNode* __bst__findMinNode(BSTNode *node) {
    BSTNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;
    
    return currNode;
}

BSTNode* __bst__remove(BSTNode *root, int value) {
    if (root == NULL) return NULL;

    if (value > root->key)
        root->right = __bst__remove(root->right, value);
    else if (value < root->key)
        root->left = __bst__remove(root->left, value);
    else {
        
        if (root->left == NULL) {
            BSTNode *rightChild = root->right;
            free(root);
            return rightChild;
        }
        else if (root->right == NULL) {
            BSTNode *leftChild = root->left;
            free(root);
            return leftChild;
        }

        BSTNode *temp = __bst__findMinNode(root->right);
        root->key     = temp->key;
        root->right   = __bst__remove(root->right, temp->key);
    }
    return root;
}

void bst_init(BST *bst) {
      bst->_root = NULL;
      bst->_size = 0u;
}

bool bst_isEmpty(BST *bst) {
      return bst->_root == NULL;
}

bool bst_find(BST *bst, int value) {
      BSTNode *temp = __bst__search(bst->_root, value);
      if (temp == NULL)
        return false;
  
      if (temp->key == value)
        return true;
      else
        return false;
}

void bst_insert(BST *bst, int value) {
      if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, value);
        bst->_size++;
  }
}

int height(BSTNode* node)
{
    if (node==NULL)
        return 0;
    else
    {
        int LeftHeight = height(node->left);
        int RightHeight = height(node->right);

        if (LeftHeight > RightHeight)
            return(LeftHeight+1);
        
        else
            return(RightHeight+1);
    }
}

void MinMax(BSTNode* root, int level, hasil *res)
{
    if (root == NULL)
        return;
    if (level == 1)
  {
    res->value1 += root->key;
    res->value2+=1;
  }
    else if (level > 1)
    {
        MinMax(root->left, level-1, res);
        MinMax(root->right, level-1, res);
    }
}

void BstAVG(BSTNode* root)
{
    hasil avg;
    int i;
    int hi = height(root);
    double amount;

    for (i = 1; i <= hi; i++){
    avg.value2 = 0;
    avg.value1 = 0;
    MinMax(root, i, &avg);
    amount = avg.value1/avg.value2;
    printf("Level %d = %.2lf\n", i-1, amount);
  }
}

void Delete (BSTNode *root){
    if(root == NULL)
        return;
    Delete(root->right);
    Delete(root->left);
    free(root);
}

void bst_bfs(BST *bst)
{
  BstAVG(bst->_root);
}

void deleteT (BST*bst)
{
    Delete(bst->_root);
}

int main()
{
      BST Bakery;
      int chef, cake;
      bst_init(&Bakery);

    scanf("%d", &chef);
    for (int i = 0; i < chef; i++) {
    while (scanf("%d", &cake) != -1 )
    {
      if(cake == -1){
        break;
      }
      else{
      bst_insert(&Bakery, cake);
      }
    }
        bst_bfs(&Bakery);
        deleteT(&Bakery);
        Bakery._root = NULL;
    }
  return 0;
}
