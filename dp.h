#pragma once
#ifndef __DP_H__
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

class DynamicProgramming {
public:
	unsigned long long fac_Memo(int num) {
		vector<unsigned long long>  table(num+1);
		table[0] = 0;
		table[1] = 1;
		for (int i = 2; i <= num; i++) {
			table[i] = table[i - 1] + table[i - 2];
		}
		return table[num];
	}
private:

};
#endif // !__DP_H__
