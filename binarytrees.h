#pragma once
#include <string>     // std::string, std::to_string
#include <map>
#include <iostream>
#include "ds.h"
#include "aux.h"
using namespace std;


class TreeRecAlgo {
public:
	void InOrder(binaryTreeNode* root) {
		if (root == NULL)
			return;
		InOrder(root->left);

		cout << "ParentNode-Name (" << root->parent->data << ") NodeData (" << root->data << ")\n";

		InOrder(root->right);
	}

	void PreOrder(binaryTreeNode* root) {
		if (root == NULL)
			return;
		cout << root->data << " ";
		InOrder(root->left);
		InOrder(root->right);
	}

	void PostOrder(binaryTreeNode* root) {
		if (root == NULL)
			return;
		InOrder(root->left);
		InOrder(root->right);
		cout << root->data << " ";
	}

	bool isSymmetric(binaryTreeNode* root) {
		if (root->left == NULL && root->right != NULL)
		{
			return false;
		}
		if (root->left != NULL && root->right == NULL)
		{
			return false;
		}

		int leftVal = isSymmetric(root->left);
		int rightVal = isSymmetric(root->right);
		if (leftVal != rightVal) {
			return false;
		}
		return true;
	}

	int maxValue(binaryTreeNode* root) {
		if (root == NULL)
			return 0;
		if (root->left == NULL && root->right == NULL)
			return root->data;
		int leftVal = maxValue(root->left);
		int rightVal = maxValue(root->right);
		int currValue = root->data;
		if (leftVal > currValue)
			currValue = leftVal;
		if (rightVal > currValue)
			currValue = rightVal;
		return currValue;
	}

	int minValue(binaryTreeNode* root) {
		if (root == NULL)
			return 0;
		if (root->left == NULL && root->right == NULL)
			return root->data;
		int leftVal = minValue(root->left);
		int rightVal = minValue(root->right);
		int currValue = root->data;
		if (leftVal < currValue)
			currValue = leftVal;
		if (rightVal < currValue)
			currValue = rightVal;
		return currValue;
	}

	int countLeaves(binaryTreeNode* root) {
		if (root == NULL)
			return 0;
		if (root->left == NULL && root->right == NULL)
			return 1;

		int leftCount = countLeaves(root->left);
		int rightCount = countLeaves(root->right);

		return leftCount + rightCount;
	}

	bool isHeap(binaryTreeNode* root) {
		if (root->left == NULL && root->right == NULL)
			return true;

		if (root->right != NULL && root->left == NULL) {
			return root->data > root->right->data;
		}

		if (root->left != NULL && root->right != NULL) {
			if (root->data > root->left->data && root->data > root->right->data)
			{
				return isHeap(root->left) && isHeap(root->right);
			}
		}
		return false;
	}

	/*
		Binary Search
	*/
	bool binarySearch(binaryTreeNode* root, int target) {
		if (root == NULL)
			return false;

		if (target == root->data) {
			return true;
		}

		if (target > root->data)
			return binarySearch(root->right, target);
		return binarySearch(root->left, target);
	}

	binaryTreeNode* BSTInsertion(binaryTreeNode* root, int data)
	{
		BSTInsertion2(root, root, data);
		return root;
	}

	void BSTInsertion2(binaryTreeNode* root, binaryTreeNode* parent, int data) {
		if (root == NULL) {
			binaryTreeNode* newNode = new binaryTreeNode(data);
			newNode->parent = parent;
			return;
		}

		if (data > root->data)
			return BSTInsertion2(root->right, root, data);
		return BSTInsertion2(root->left, root, data);
	}

	bool IsBST(binaryTreeNode* root) {
		if (root == NULL)
			return false;

		bool leftSide = IsBST(root->left);
		bool rightSide = IsBST(root->right);

		if (root != NULL)
		{
			if (root->left != NULL && root->right != NULL)
			{
				if (root->left->data < root->data && root->right->data > root->data)
					return true;
				return false;
			}

			if (root->left != NULL && root->right == NULL) {
				if (root->left->data < root->data)
					return true;
			}

			if (root->right != NULL && root->left == NULL) {
				if (root->right->data > root->data)
					return true;
			}
		}
		return leftSide && rightSide;
	}
};
