#pragma once
#include <iostream>
using namespace std;

struct binaryTreeNode {
	int data;
	binaryTreeNode* left = NULL;
	binaryTreeNode* right = NULL;
	binaryTreeNode* parent = NULL;
	binaryTreeNode() {
		left = NULL;
		right = NULL;
		parent = NULL;
	}
	binaryTreeNode(int item) {
		data = item;
		left = NULL;
		right = NULL;
		parent = NULL;
	}
};

struct hexEntry {
	std::string binRep;
	char decRep;
	hexEntry() {

	}
	hexEntry(string binRep, char decRep)
	{
		this->binRep = binRep;
		this->decRep = decRep;
	}
};

struct listNode {
	int data;
	listNode* next;
	listNode() {}
	listNode(int d) {
		data = d;
		next = NULL;
	}
};
typedef listNode* listPtr;



struct HexTable {
	hexEntry Table[16];
	HexTable() {
		Table[0] =	{ "0000",'0' };
		Table[1] =	{ "0001",'1' };
		Table[2] =	{ "0010",'2' };
		Table[3] =	{ "0011",'3' };
		Table[4] =	{ "0100", '4' };
		Table[5] =	{ "0101",'5' };
		Table[6] =	{ "0110",'6' };
		Table[7] =	{ "0111",'7' };
		Table[8] =	{ "1000",'8' };
		Table[9] =	{ "1001",'9' };
		Table[10] = { "1010",'A' };
		Table[11] = { "1011",'B' };
		Table[12] = { "1100",'C' };
		Table[13] = { "1101",'D' };
		Table[14] = { "1110",'E' };
		Table[15] = { "1111",'F' };
	}
	hexEntry* getTable() {
		return Table;
	}
};