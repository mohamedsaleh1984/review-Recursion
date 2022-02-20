#pragma once
#include <iostream>
#include "ds.h"
using namespace std;

char getHex(string desBinary) {
	if (desBinary.length() != 4)
		return '\0';

	HexTable tbl;
	hexEntry* entries = tbl.getTable();

	for (int i = 0; i < 16; i++)
	{
		hexEntry entry = *(entries + i);
		if (desBinary.compare(entry.binRep) == 0) {
			return tbl.Table[i].decRep;
		}
	}
	return '\0';
}
