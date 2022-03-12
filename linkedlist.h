#pragma once
#include <string>     // std::string, std::to_string
#include <map>
#include "ds.h"
using namespace std;

class LinkedListRecAlgo {
public:
	int countNegative(listPtr head) {
		if (head == NULL)
			return 0;
		int listCount = countNegative(head->next);
		if (head->val < 0)
			listCount++;
		return listCount;
	}

	int occuranceRecursive(ListNode* head, int target) {
		if (head == NULL)
			return 0;
		int occur = occuranceRecursive(head->next, target);
		if (head->val == target) {
			occur++;
		}
		return occur;
	}
	//https://leetcode.com/problems/rotate-list/
	ListNode* rotateRight(ListNode* head, int k) {
		ListNode* tmpHead = head;
		ListNode* headToReturn = head;
		vector<ListNode*> nodes;
		vector<int> values;

		int index = 0;
		while (head) {
			nodes.push_back(head);
			values.push_back(head->val);
			head = head->next;
			index++;
		}

		int size = nodes.size();

		for (int i = 0; i < size; i++) {
			int newPosition = 0;
			if (i + k >= size)
				newPosition = (i + k) % size;
			else
				newPosition = (i + k);
			nodes[newPosition]->val = values[i];
		}

		//Update the Original List
		index = 0;
		while (tmpHead) {
			tmpHead->val = nodes[index]->val;
			tmpHead = tmpHead->next;
			index++;
		}
		return headToReturn;

	}

	//https://leetcode.com/problems/split-linked-list-in-parts/
	vector<ListNode*> splitListToParts(ListNode* head, int k) {
		int size = 0;
		ListNode* tmpHead = head;
		while (tmpHead) {
			tmpHead = tmpHead->next;
			size++;
		}

		int splitSize = k;

		int index = 0;
		if (splitSize > size)
		{
			vector<ListNode*> splits(splitSize);
			while (head) {
				splits[index] = new ListNode(head->val);
				index++;
				head = head->next;
			}
			if (index < splitSize) {
				splits[index] = nullptr;
				index++;
			}
			return splits;
		}

		int vectorlen = size / splitSize;
		vector<int> vectorSizes(k);
		for (int i = 0; i < k; i++) {
			vectorSizes[i] = k;
		}
		int remaining = size % k;
		for (int i = 0; i < remaining; i++) {
			vectorSizes[i]++;
		}

		
		vector<ListNode*> splits(vectorlen);

		int counter = 1;
		while (head) {
			if (splits[index] == nullptr)
			{
				splits[index] = new ListNode(head->val);
			}
			else {
				ListNode* ptr = splits[index];
				ListNode* newOne = new ListNode(head->val);
				while (ptr->next) {
					ptr = ptr->next;
				}
				ptr->next = newOne;
			}

			if (counter == vectorSizes[index]) {
				index++;
				counter = 0;
			}

			head = head->next;
			counter++;
		}

		return splits;
	}
private:
};

