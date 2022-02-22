#pragma once
#include <string>     // std::string, std::to_string
#include <map>
#include <iostream>
#include "ds.h"
#include "aux.h"
#include <queue>
#include <stack>
#include <set> 
#include <utility> 
#include <functional>
using namespace std;

class TreeRecAlgo {
public:
	void InOrder(binaryTreeNode* root) {
		if (root == NULL)
			return;
		InOrder(root->left);
		cout << root->data << " ";
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

	bool IsSymmetric(binaryTreeNode* root) {
		if (root->left == NULL && root->right != NULL)
		{
			return false;
		}
		if (root->left != NULL && root->right == NULL)
		{
			return false;
		}

		int leftVal = IsSymmetric(root->left);
		int rightVal = IsSymmetric(root->right);
		if (leftVal != rightVal) {
			return false;
		}
		return true;
	}

	int MaxValue(binaryTreeNode* root) {
		if (root == NULL)
			return 0;
		if (root->left == NULL && root->right == NULL)
			return root->data;

		int leftVal = MaxValue(root->left);
		int rightVal = MaxValue(root->right);
		int currValue = root->data;

		if (leftVal > currValue)
			currValue = leftVal;
		if (rightVal > currValue)
			currValue = rightVal;
		return currValue;
	}

	int MinValue(binaryTreeNode* root) {
		if (root == NULL)
			return 0;
		if (root->left == NULL && root->right == NULL)
			return root->data;

		int leftVal = MinValue(root->left);
		int rightVal = MinValue(root->right);
		int currValue = root->data;

		if (leftVal < currValue)
			currValue = leftVal;
		if (rightVal < currValue)
			currValue = rightVal;
		return currValue;
	}

	int CountLeaves(binaryTreeNode* root) {
		if (root == NULL)
			return 0;

		if (root->left == NULL && root->right == NULL)
			return 1;

		int leftCount = CountLeaves(root->left);
		int rightCount = CountLeaves(root->right);

		return leftCount + rightCount;
	}

	bool IsHeap(binaryTreeNode* root) {
		if (root->left == NULL && root->right == NULL)
			return true;

		if (root->right != NULL && root->left == NULL) {
			return root->data > root->right->data;
		}

		if (root->left != NULL && root->right != NULL) {
			if (root->data > root->left->data && root->data > root->right->data)
			{
				return IsHeap(root->left) && IsHeap(root->right);
			}
		}
		return false;
	}

	bool BinarySearch(binaryTreeNode* root, int target) {
		if (root == NULL)
			return false;

		if (target == root->data) {
			return true;
		}

		if (target > root->data)
			return BinarySearch(root->right, target);
		return BinarySearch(root->left, target);
	}

	binaryTreeNode* BSTInsertion(binaryTreeNode* root, int data)
	{
		BSTInsertion2(root, root, data);
		return root;
	}

	void BSTInsertion2(binaryTreeNode* root, binaryTreeNode* parent, int data) {
		if (root == NULL) {
			binaryTreeNode* newNode = new binaryTreeNode(data);
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

	void LevelOrder(struct binaryTreeNode* root) {
		if (root == NULL) return;
		queue<binaryTreeNode*> Q;
		Q.push(root);
		while (!Q.empty()) {
			struct binaryTreeNode* curr = Q.front();
			cout << curr->data << " ";
			if (curr->left != NULL) Q.push(curr->left);
			if (curr->right != NULL) Q.push(curr->right);
			Q.pop();
		}
	}

	binaryTreeNode* SumofTwoTrees(binaryTreeNode* root1, binaryTreeNode* root2) {
		if (root1 == NULL && root2 == NULL) return NULL;
		if (root1 == NULL) return root2;
		if (root2 == NULL) return root1;

		struct binaryTreeNode* newNode = (struct binaryTreeNode*)malloc(sizeof(struct binaryTreeNode));
		newNode->data = root1->data + root2->data;

		newNode->left = SumofTwoTrees(root1->left, root2->left);
		newNode->right = SumofTwoTrees(root1->right, root2->right);

		return newNode;
	}

	int SumOfRootToLeaf(binaryTreeNode* root) {
		if (root == NULL)
			return 0;
		return root->data + SumOfRootToLeaf(root->left) + SumOfRootToLeaf(root->right);
	}

	/*Given a binary tree, print out all of its root-to-leaf paths, one per line. Uses a recursive helper to do the work.*/
	void PrintPaths(binaryTreeNode* node)
	{
		int path[1000];
		printPathsRecur(node, path, 0);
	}

	bool AreTreeEqual(binaryTreeNode* r1, binaryTreeNode* r2) {
		if ((r1 == NULL && r2 != NULL) || (r1 != NULL && r2 == NULL))
			return false;
		if (r1 == NULL && r2 == NULL) {
			return true;
		}
		if (r1->data == r2->data) {
			return true;
		}

		bool bLeftSide = AreTreeEqual(r1->left, r2->left);
		bool bRightSide = AreTreeEqual(r1->right, r2->right);
		return bLeftSide && bRightSide;
	}

	bool AreLeavesEqual(binaryTreeNode* r1, binaryTreeNode* r2) {
		if (r1 == NULL && r2 == NULL) {
			return true;
		}

		if (r1->left == NULL && r2->left == NULL && r1->right == NULL && r2->right) {
			if (r1->data == r2->data)
				return true;
			else
				return false;
		}

		bool bLeftSide = AreLeavesEqual(r1->left, r2->left);
		bool bRightSide = AreLeavesEqual(r1->right, r2->right);
		return bLeftSide && bRightSide;
	}

	bool AreLeavesEqual2(binaryTreeNode* r1, binaryTreeNode* r2) {
		vector<int> v1 = getLeaves(r1);
		vector<int> v2 = getLeaves(r2);
		if (v1.size() != v2.size()) {
			return false;
		}

		for (int i = 0; i < v1.size(); i++) {
			if (v1[i] != v2[i])
				return false;
		}

		return true;;
	}

	vector<string> BinaryTreePaths(binaryTreeNode* root) {
		vector<string> result;
		PathFinder(root, result, "");
		return result;
	}

	int SumOfLeftNodes(binaryTreeNode* root) {
		int sum = 0;
		SumOfLeftNodesHelper(root, false, sum);
		return sum;
	}

	int SumOfLeftLeaves(binaryTreeNode* root) {
		int sum = 0;
		SumOfLeftLeavesHelper(root, false, sum);
		return sum;
	}

	bool PathWithTargetSum(binaryTreeNode* root, const int& TargetSum) {
		int alt = 0;
		return IsPathSum(root, TargetSum, alt);
	}
	//TODO:FIX
	string FindPathToNode(binaryTreeNode* root, int TargetNode) {
		queue<std::pair<binaryTreeNode*, int>> S;

		//Parent Value, Current Node
		map<int, binaryTreeNode*> kk;

		std::pair<binaryTreeNode*, int > targetNode;
		string r = "";
		S.push(std::make_pair(root, -1));
		kk.insert(std::make_pair(-1, root));

		while (!S.empty()) {
			pair<binaryTreeNode*, int> node = S.front();
			if (node.first->data == TargetNode) 
			{
				targetNode = make_pair(node.first, node.first->data);
				kk.insert(std::make_pair(node.first->data, node.first));
				break;
			}
			else {
				if (node.first->left) {
					S.push(std::make_pair(node.first->left, node.first->data));
					kk.insert(std::make_pair(node.first->data, node.first->left));
				}

				if (node.first->right) {
					S.push(std::make_pair(node.first->right, node.first->data));
					kk.insert(std::make_pair(node.first->data, node.first->right));
				}

				S.pop();
			}
		}

		while (targetNode.second != -1)
		{
			int upNode;
			r += to_string(targetNode.second);
			binaryTreeNode* dd = kk.at(targetNode.second);

		}


		return "";
	}

	//void findPathToNodeHelper(binaryTreeNode* root, int TargetNode) {
	//	stack<std::pair<binaryTreeNode*,int>> S;
	//	set<int> visited;
	//	bool foundPath = false;
	//	S.push(std::make_pair(root, 0));
	//	
	//	while (!S.empty()) {
	//		//Check if it's Target
	//		pair<binaryTreeNode*, int> node = S.top();

	//		 if (node.first->data == TargetNode) {
	//			break;
	//		}
	//		else {
	//			if (node.first->left) {
	//				S.push(std::make_pair(node.first->left,node.second));
	//			}

	//			if (node.first->right) {
	//				S.push(std::make_pair(node.first->right, node.second));
	//			}
	//			visited.insert(node.first->data);
	//			S.pop();
	//		} 
	//	}
	//}

	int GetHeight(binaryTreeNode* root) {
		if (root == NULL) return 0;
		return 1 + max(GetHeight(root->left), GetHeight(root->right));
	}

	/*
		1- Left subtree is balanced
		2- right subtree is balanced
		3- the difference between left and right less than or equal 1
	*/
	bool IsBalanced(binaryTreeNode* root) {
		if (root == NULL)
			return true;

		int lh = GetHeight(root->left);
		int rh = GetHeight(root->right);

		if (abs(lh - rh) <= 1 && IsBalanced(root->left) && IsBalanced(root->right))
			return true;
		return false;
	}

	/*
		Convert one tree to another; knowing that you can swap only the children if specific Parent
		ref ::https://www.youtube.com/watch?v=o6NfQeGP0zg
	*/
	/*bool IsIsomorphic(binaryTreeNode* root1, binaryTreeNode* root2)
	{
		if (!root1 && !root2) return true;
		if (!root1 || !root1) return false;
		if (root1->data != root2->data) return false;

		bool a = IsIsomorphic(root1->left, root2->left) && IsIsomorphic(root1->right, root2->right);
		bool b = IsIsomorphic(root1->left, root2->right) && IsIsomorphic(root1->right, root2->left);
		return a || b;
	}*/
private:
	vector<int> getLeaves(binaryTreeNode* root) {
		vector<int> vec;
		leaves(root, vec);
		return vec;
	}
	void leaves(binaryTreeNode* root, vector<int>& v) {
		if (root == NULL)
			return;
		if (root->left == NULL and root->right == NULL)
			v.push_back(root->data);
		leaves(root->left, v);
		leaves(root->right, v);
	}
	/* Prototypes for functions needed in printPaths() */
	/* Recursive helper function -- given a node, and an array containing the path from the root node up to but not including this node, print out all the root-leaf paths.*/
	void printPathsRecur(binaryTreeNode* node, int path[], int pathLen)
	{
		if (node == NULL)
			return;

		/* append this node to the path array */
		path[pathLen] = node->data;
		pathLen++;

		/* it's a leaf, so print the path that lead to here */
		if (node->left == NULL && node->right == NULL)
		{
			printArray(path, pathLen);
		}
		else
		{
			/* otherwise try both subtrees */
			printPathsRecur(node->left, path, pathLen);
			printPathsRecur(node->right, path, pathLen);
		}
	}

	//Get all avaliable Paths from Root to Leaves
	void PathFinder(binaryTreeNode* root, vector<string>& res, string currPath) {
		if (root == NULL)
			return;

		//We've reached to a leave
		if (root->left == NULL && root->right == NULL) {
			//Append the current Node to the Path
			currPath += to_string(root->data);
			//Push the Path to the vector
			res.push_back(currPath);
			return;
		}



		currPath += to_string(root->data) + "->";
		if (root->left)
			PathFinder(root->left, res, currPath);

		if (root->right)
			PathFinder(root->right, res, currPath);
	}

	int SumOfLeftNodesHelper(binaryTreeNode* root, bool isLeft, int& sum) {
		if (root == NULL)
			return 0;

		if (isLeft) {
			cout << root->data << " ";
			sum += root->data;
		}

		int leftNode = SumOfLeftNodesHelper(root->left, true, sum);
		int rightNode = SumOfLeftNodesHelper(root->right, false, sum);
	}

	int SumOfLeftLeavesHelper(binaryTreeNode* root, bool isLeft, int& sum) {
		if (root == NULL)
			return 0;

		if (isLeft && root->left == NULL && root->right == NULL) {
			cout << root->data << " ";
			sum += root->data;
		}

		int leftNode = SumOfLeftLeavesHelper(root->left, true, sum);
		int rightNode = SumOfLeftLeavesHelper(root->right, false, sum);
	}

	bool IsPathSum(binaryTreeNode* root, int TargetSum, int& currentSum) {
		if (root == NULL)
			return false;

		if (root->left == NULL && root->right == NULL)
			return (currentSum + root->data) == TargetSum;

		int sumUntil = currentSum + root->data;
		bool leftVal = IsPathSum(root->left, TargetSum, sumUntil);
		bool rightVal = IsPathSum(root->right, TargetSum, sumUntil);

		return leftVal || rightVal;
	}
};
