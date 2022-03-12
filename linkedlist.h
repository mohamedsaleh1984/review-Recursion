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
private:
	void rotateRightHelper(ListNode* head, vector<int>, int k) {

	}
};

