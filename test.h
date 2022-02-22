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
Aux* ptrAux;

void test_FindPathToNode() {
    binaryTreeNode* root = ptrAux->makeTree();
    cout << ptrTree->FindPathToNode(root, 17) << endl;
}

void test_IsBalanced() {
    binaryTreeNode* root = ptrAux->makeTree();
    printf("%s", ptrTree->IsBalanced(root) ? "true" : "false");
}

void test_Height() {
    binaryTreeNode* root = ptrAux->makeTree();
    cout << ptrTree->GetHeight(root) << endl;
}

void test_PathWithTargetSum() {
    binaryTreeNode* root = ptrAux->makeTree();
    cout << ptrTree->PathWithTargetSum(root,272) << endl;
}

void test_SumOfLeftLeaves() {
    binaryTreeNode* root = ptrAux->makeTree();
    cout << ptrTree->SumOfLeftLeaves(root) << endl;
}

void test_SumOfLeftNodes() {
    binaryTreeNode* root = ptrAux->makeTree();
    cout << ptrTree->SumOfLeftNodes(root) << endl;
}

void test_binaryTree_BinaryTreePaths() {
    binaryTreeNode* root  = ptrAux->makeTree();
    vector<string> v = ptrTree->BinaryTreePaths(root);
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << "\n";
}

void test_binaryTree_AreLeavesEqualAnotherWay() {
    binaryTreeNode* root = ptrAux->makeTree();
    binaryTreeNode* root3 = new binaryTreeNode(15);
    root3->left = new binaryTreeNode(6);
    root3->right = new binaryTreeNode(9);
    root3->left->left = new binaryTreeNode(3);
    root3->left->right = new binaryTreeNode(5);
    root3->right->left = new  binaryTreeNode(2);
    root3->right->left->left = new binaryTreeNode(2);
    cout << ptrTree->AreLeavesEqual2(root, root3) << endl;
}

void test_binaryTree_AreLeavesEqual() {
    binaryTreeNode* root = ptrAux->makeTree();
    binaryTreeNode* root3 = ptrAux->makeTree(); 
    cout << ptrTree->AreLeavesEqual(root, root3) << endl;
}

void test_binaryTree_AreRootsEqual() {
    binaryTreeNode* root = ptrAux->makeTree();
    binaryTreeNode* root2 = new binaryTreeNode(2);
    root2->left = new binaryTreeNode(5);
    root2->right = new binaryTreeNode(3);
    root2->left->left = new binaryTreeNode(1);
    root2->right->left = new  binaryTreeNode(9);
    root2->right->left->left = new binaryTreeNode(15);
    cout << ptrTree->AreTreeEqual(root, root2) << endl;


    binaryTreeNode* root3 = new binaryTreeNode(10);
    root3->left = new binaryTreeNode(8);
    root3->right = new binaryTreeNode(2);
    root3->left->left = new binaryTreeNode(3);
    root3->left->right = new binaryTreeNode(5);
    root3->right->left = new  binaryTreeNode(2);
    root3->right->left->left = new binaryTreeNode(2);
    cout << ptrTree->AreTreeEqual(root, root3) << endl;
}

void test_BinaryTree_SumOfRootToLeaf() {
    binaryTreeNode* root = ptrAux->makeTree();
    cout << "Sum " << ptrTree->SumOfRootToLeaf(root) << endl;
}


void test_BinaryTree_LevelOrder() {
    binaryTreeNode* root = ptrAux->makeTree();
    ptrTree->LevelOrder(root);
}

void  test_BinaryTree_PrintPathsFromRootToLeafs()
{
    binaryTreeNode* root = ptrAux->makeTree();
    ptrTree->PrintPaths(root);
}

void test_BinaryTree_SumofTwoTrees() {
    binaryTreeNode* root = ptrAux->makeTree();

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
