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
	//https://leetcode.com/problems/fibonacci-number/
	unsigned long long fac_Memo(int num) {
		vector<unsigned long long>  table(num+1);
		table[0] = 0;
		table[1] = 1;
		for (int i = 2; i <= num; i++) {
			table[i] = table[i - 1] + table[i - 2];
		}
		return table[num];
	}

	//https://leetcode.com/problems/n-th-tribonacci-number
	int tribonacci(int n) {
		if (n == 0)
			return 0;
		if (n == 1)
			return 1;
		if (n == 2)
			return 1;
		vector<int>  table(n + 1);
		table[0] = 0;
		table[1] = 1;
		table[2] = 1;
		for (int i = 3; i <= n; i++) {
			table[i] = table[i - 1] + table[i - 2] + table[i - 3];
		}
		return table[n];
	}
private:

};
#endif // !__DP_H__
