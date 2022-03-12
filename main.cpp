#include <iostream>
#include <math.h>
#include <string>          
#include <cstddef>          
#include <queue>
#include <stack>
#include "binarytrees.h"
#include "ds.h"
#include "test.h"
#include "arrays.h"

using namespace std;
//          15
//         /  \
//        10   25
//       / \   / \
//      7  13 22  27
//     / \    /
//    5   9  17

int main()
{
	ListNode* head = new ListNode(10);
	head->next = new ListNode(20);
	head->next->next = new ListNode(30);
	head->next->next->next = new ListNode(40);
	head->next->next->next->next = new ListNode(50);
//	head->next->next->next->next->next = new ListNode(60);

	int size = 0;
	ListNode* tmpHead = head;
	while (tmpHead) {
		tmpHead = tmpHead->next;
		size++;
	}

	int splitSize = 2;
	int vectorlen = size / splitSize;
	if (size % splitSize == 1)
		vectorlen++;

	vector<ListNode*> splits(vectorlen);
	int index = 0;
	if (splitSize > size)
	{
		while (head) {
			splits[index] = new ListNode(head->val);
			index++;
			head = head->next;
		}
		if (index < splitSize) {
			splits[index] = nullptr;
			index++;
		}
	}
	else {
		int counter = 1;
		while (head) {
			if (splits[index] == nullptr)
			{
				splits[index] = new ListNode(head->val);
			}
			else {
				ListNode* newOne = new ListNode(head->val);
				splits[index]->next = newOne;
			}

			if (counter % splitSize == 0) 
				index++;

			head = head->next;
			counter++;
		}
	}

	for (auto heads : splits)
	{
		if (heads == nullptr)
		{
			cout << "{}" << endl;
		}
		else {
			cout << "{";
			while (heads) {
				cout << heads->val;
				heads = heads->next;
				if (heads != nullptr)
					cout << ",";
			}
			cout << "}\n";
		}
	}












	//test_LinkedList_RotateRight();
	//test_DP_Memo_Fac();
	//test_Array_BinarySearch();
	//test_PathSum2();
	//test_LowestCommonAncestor();
	//test_FindPathToNode();
	//test_IsBalanced();
	//test_Height();
	//TODO:Fix test_PathWithTargetSum();
	//test_SumOfLeftNodes();		//55+5+-145+152+170 = 237
	//test_SumOfLeftLeaves();		//55+170 = 225
	//test_binaryTree_BinaryTreePaths();
	//test_binaryTree_AreLeavesEqualAnotherWay();
	//test_binaryTree_AreLeavesEqual();
	//test_binaryTree_AreRootsEqual();
	//test_BinaryTree_SumOfRootToLeaf();
	//test_BinaryTree_LevelOrder();
	//test_BinaryTree_PrintPathsFromRootToLeafs();
	//test_BinaryTree_SumofTwoTrees();
	return 0;
}



