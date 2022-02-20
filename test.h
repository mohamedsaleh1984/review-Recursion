#ifndef TEST_H
#include <iostream>
#include <math.h>
#include <string>         // std::string
#include <cstddef>         // std::size_t
#include <queue>
#include <stack>
#include "binarytrees.h"
#include "ds.h"
using namespace std;
TreeRecAlgo* ptrTree;
void test_BinaryTree_LevelOrder() {
    binaryTreeNode* root = new binaryTreeNode(10);
    root->left = new binaryTreeNode(8);
    root->right = new binaryTreeNode(2);
    root->left->left = new binaryTreeNode(3);
    root->left->right = new binaryTreeNode(5);
    root->right->left = new  binaryTreeNode(2);
    root->right->left->left = new binaryTreeNode(12);
    /* Constructed binary tree is
         10
        /   \
       8     2
      / \    /
     3   5  2
           /
          12
    */
    ptrTree->LevelOrder(root);
    //exoected:: 10,8,2,3,5,2,12
}

void  test_BinaryTree_PrintPathsFromRootToLeafs()
{
    /* Constructed binary tree is
         10
        /   \
       8     2
      / \    /
     3   5  2
           /
          2
    */
    binaryTreeNode* root = new binaryTreeNode(10);
    root->left = new binaryTreeNode(8);
    root->right = new binaryTreeNode(2);
    root->left->left = new binaryTreeNode(3);
    root->left->right = new binaryTreeNode(5);
    root->right->left = new  binaryTreeNode(2);
    root->right->left->left = new binaryTreeNode(2);
    ptrTree->PrintPaths(root);

}

void test_BinaryTree_SumofTwoTrees() {
    binaryTreeNode* root = new binaryTreeNode(10);
    root->left = new binaryTreeNode(8);
    root->right = new binaryTreeNode(2);
    root->left->left = new binaryTreeNode(3);
    root->left->right = new binaryTreeNode(5);
    root->right->left = new  binaryTreeNode(2);
    root->right->left->left = new binaryTreeNode(2);

    binaryTreeNode* root2 = new binaryTreeNode(2);
    root2->left = new binaryTreeNode(5);
    root2->right = new binaryTreeNode(3);
    root2->left->left = new binaryTreeNode(1);
    root2->right->left = new  binaryTreeNode(9);
    root2->right->left->left = new binaryTreeNode(15);

    binaryTreeNode* root3 = ptrTree->SumofTwoTrees(root, root2);
    ptrTree->InOrder(root3);
}
#endif // !TEST_H
