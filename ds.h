#pragma once
#ifndef DS_H

#include <iostream>
using namespace std;

struct binaryTreeNode {
	int val= 0;
	binaryTreeNode* left = NULL;
	binaryTreeNode* right = NULL;
	binaryTreeNode() {
		left = NULL;
		right = NULL;
	}
	binaryTreeNode(int item) {
		val = item;
		left = NULL;
		right = NULL;
	}
};

struct HexEntry {
	std::string binRep;
	char decRep = '\0';
	HexEntry() {

	}
	HexEntry(string binRep, char decRep)
	{
		this->binRep = binRep;
		this->decRep = decRep;
	}
};

struct ListNode {
	int val = 0 ;
	ListNode* next = NULL;
	ListNode() {}
	ListNode(int d) {
		val = d;
		next = NULL;
	}
};
typedef ListNode* listPtr;

struct HexTable {
	HexEntry Table[16];
	HexTable() {
		Table[0] = { "0000",'0' };
		Table[1] = { "0001",'1' };
		Table[2] = { "0010",'2' };
		Table[3] = { "0011",'3' };
		Table[4] = { "0100", '4' };
		Table[5] = { "0101",'5' };
		Table[6] = { "0110",'6' };
		Table[7] = { "0111",'7' };
		Table[8] = { "1000",'8' };
		Table[9] = { "1001",'9' };
		Table[10] = { "1010",'A' };
		Table[11] = { "1011",'B' };
		Table[12] = { "1100",'C' };
		Table[13] = { "1101",'D' };
		Table[14] = { "1110",'E' };
		Table[15] = { "1111",'F' };
	}
	HexEntry* getTable() {
		return Table;
	}
};
#endif // !DS_H
