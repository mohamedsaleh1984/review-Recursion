#pragma once
#ifndef HELPER_H
#include <iostream>
#include "ds.h"
using namespace std;

class Helper {
public:
	binaryTreeNode* buildTree(binaryTreeNode* root, vector<int> nodes) {
		binaryTreeNode* root2 = buildTreeHelper(root, nodes, 0);
		return root2;
	}

	binaryTreeNode* buildTreeHelper(binaryTreeNode* root, vector<int> nodes, int i) {
		if (i < nodes.size()) {
			binaryTreeNode* temp = newNode(nodes[i]);
			root = temp;

			root->left = buildTreeHelper(root->left, nodes, 2 * i + 1);
			root->right = buildTreeHelper(root->right, nodes, 2 * i + 2);
		}
		return root;
	}

	binaryTreeNode* newNode(int data) {
		binaryTreeNode* node = (binaryTreeNode*)malloc(sizeof(binaryTreeNode));
		node->data = data;
		node->left = node->right = NULL;
		return node;
	}

	binaryTreeNode* makeTree() {
		/*
				 15
			  /      \
			10        25
		   /  \      /  \
		   7  13   22   27
		 / \       /
		5   9     17
		*/
		binaryTreeNode* root = new binaryTreeNode();
		root->data = 15;
		root->left = new binaryTreeNode(10);
		root->right = new binaryTreeNode(25);
		root->left->left = new binaryTreeNode(7);
		root->left->right = new binaryTreeNode(13);
		root->left->left->left = new binaryTreeNode(5);
		root->left->left->right = new binaryTreeNode(9);
		root->right->right = new binaryTreeNode(27);
		root->right->left = new binaryTreeNode(22);
		root->right->left->left = new binaryTreeNode(17);
		return root;
	}
	binaryTreeNode* makeSymmetricTree() {
		binaryTreeNode* root = new binaryTreeNode();
		root->data = 1;
		root->left = new binaryTreeNode(2);
		root->left->left = new binaryTreeNode(3);
		root->left->right = new binaryTreeNode(4);


		root->right = new binaryTreeNode(2);
		root->right->left = new binaryTreeNode(4);
		root->right->right = new binaryTreeNode(3);

		return root;
	}
	binaryTreeNode* makeHeap() {
		binaryTreeNode* root = new binaryTreeNode();
		root->data = 9;
		root->left = new binaryTreeNode(8);
		root->right = new binaryTreeNode(7);
		root->left->left = new binaryTreeNode(3);
		root->left->right = new binaryTreeNode(7);
		root->right->right = new binaryTreeNode(5);
		root->right->left = new binaryTreeNode(4);
		return root;
	}
	binaryTreeNode* makeBSTTree() {
		binaryTreeNode* root = new binaryTreeNode();
		root->data = 50;
		root->left = new binaryTreeNode(30);
		root->right = new binaryTreeNode(60);
		root->left->left = new binaryTreeNode(25);
		root->left->right = new binaryTreeNode(40);
		root->right->left = new binaryTreeNode(55);
		root->right->right = new binaryTreeNode(70);
		return root;
	}
	binaryTreeNode* makeSmallTree() {
		binaryTreeNode* root = new binaryTreeNode();
		root->data = 10;
		root->left = new binaryTreeNode(66);
		root->right = new binaryTreeNode(140);
		return root;
	}

	void showLList(listPtr head) {
		while (head != NULL) {
			cout << head->data << endl;
			head = head->next;
		}
	}

	void showArray(int array[], int size) {
		for (int i = 0; i < size; i++) {
			cout << array[i] << " ";
		}
	}

	template <class T>
	void showVector(vector<T> vec) {
		for (int i = 0; i < vec.size(); i++) {
			cout << vec[i] << " ";
		}
	}

	listNode* arrayToList(int arr[], int n)
	{
		listNode* root = NULL;
		for (int i = 0; i < n; i++)
			insert(&root, arr[i]);
		return root;
	}

	void insert(listNode** root, int item)
	{
		listNode* temp = new listNode;
		listNode* ptr;
		temp->data = item;
		temp->next = NULL;

		if (*root == NULL)
			*root = temp;
		else {
			ptr = *root;
			while (ptr->next != NULL)
				ptr = ptr->next;
			ptr->next = temp;
		}
	}
};


/* UTILITY FUNCTIONS */
/* Utility that prints out an array on a line. */
void printArray(int ints[], int len)
{
	int i;
	for (i = 0; i < len; i++)
		cout << ints[i] << " ";
	cout << endl;
}
#endif // AUX_H

