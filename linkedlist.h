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
		if (head->data < 0)
			listCount++;
		return listCount;
	}
	int occuranceRecursive(listNode* head, int target) {
		if (head == NULL)
			return 0;
		int occur = occuranceRecursive(head->next, target);
		if (head->data == target) {
			occur++;
		}
		return occur;
	}
};

