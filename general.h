#pragma once
#ifndef GENERAL_H
#define GENERAL_H
#include <string>     // std::string, std::to_string
#include <map>
#include "arrays.h"
#include "linkedlist.h"
#include "binarytrees.h"
#include "random.h"

using namespace std;

class RecAlgo {
public:
	int steps[1000];
	void intToBinaryRepRecursive(int number) {
		if (number > 0)
		{
			number /= 2;
			cout << number % 2;
			intToBinaryRepRecursive(number);
		}
	}

	string intToBinaryRecursive(int number) {
		if (number == 0)
			return "";
		number /= 2;
		string res = to_string(number % 2);
		return res + intToBinaryRecursive(number);
	}

	string binToHexRepRecursive(string bin)
	{
		if (bin.size() == 0)
			return "";

		string strChunk = bin.substr(0, 4);
		string hexRep = to_string((char)getHex(strChunk));
		return hexRep + binToHexRepRecursive(bin.substr(4, bin.length() - 1));
	}

	string intToHexRepresentation(int number) {
		string szBinary = intToBinaryRecursive(number);
		return binToHexRepRecursive(szBinary);
	}

	/*
		Print digits starting by n back to 1
		Example:
		n = 5
		output: 5 4 3 2 1
	*/
	void Backword(int n) {
		if (n > 0) {
			cout << n << " ";
			Backword(n - 1);
		}
		return;
	}

	/*
	Print digits from 1, 2,...., n
	*/
	void Forward(int n) {
		if (n > 0) {
			Forward(n - 1);
			cout << n << " ";
		}
		return;
	}

	/*
		Print number backward
		Example:
			n = 1984
			output: 4891
	*/
	void PrintNumberBackword(int year)
	{
		if (year > 0) {
			cout << year % 10;
			PrintNumberBackword(year / 10);
		}
	}

	/*
		Print Astrikes
		Example:
			input:n = 2
			output: **
	*/
	void PrintAstriks(int nTimes) {
		if (nTimes > 0)
		{
			cout << "*";
			PrintAstriks(nTimes - 1);
		}
		else if (nTimes == 0) {
			cout << "*\n";
		}
	}

	int Power(int x, int n) {
		if (n == 1)
			return x;
		return x * Power(x, n - 1);
	}

	int Factorial(int n)
	{
		if (n == 1 || n == 2) {
			return 2;
		}
		return n * Factorial(n - 1);
	}

	int Factorial_Mem(int n)
	{
		static std::map<int, int> values;
		if (n == 0 || n == 1)
			return n;

		std::map<int, int>::iterator iter = values.find(n);
		if (iter == values.end())
			return values[n] = Factorial_Mem(n - 1) + Factorial_Mem(n - 2);
		else
			return iter->second;
	}


	/*
	There are n people in a room, where n is an integer greater than or equal to 2.
	Each person shakes hands once every other person. What is the total number of handshakes
	in the room? Write a recursive function to solve this problem.
	*/
	int handShake(int n)
	{
		if (n == 1)
			return 0;
		if (n == 2)
			return 1;
		return (n - 1) + handShake(n - 1);
	}

	void starts(int n) {
		cout << "\n";
		for (size_t i = 0; i <= n; i++)
		{
			cout << "*";
		}
		cout << "\n";
	}

	int MinElement(int arr[], int n)
	{
		if (n == 1)
			return arr[0];
		return min(arr[n - 1], MinElement(arr, n - 1));
	}

	int MaxElement(int arr[], int n)
	{
		if (n == 1)
			return arr[0];
		return max(arr[n - 1], MaxElement(arr, n - 1));
	}

	bool IsPalindrome(string str) {
		if (str.length() == 0 || str.length() == 1) {
			return true;
		}
		if (str[0] != str[str.length() - 1])
			return false;
		return IsPalindrome(str.substr(1, str.length() - 2));
	}

	int Combination(int n, int r) {
		int nMr = Factorial(n - r);
		int fr = Factorial(r);
		int ls = Factorial(n);
		return  ls / (fr * nMr);
	}


	int countWays(int n) {
		if (n < 0)
			return 0;
		else if (n == 0)
			return 1;
		else
			return countWays(n - 1) + countWays(n - 2) + countWays(n - 3);
	}

	int countWays2(int n) {
		if (n <= 0)
			return 0;
		else if (n == 1)
			return 1;
		else if (n == 2)
			return 2;
		else if (n == 3)
			return 4;
		return countWays2(n - 1) + countWays2(n - 2) + countWays2(n - 3);
	}

	int RobbotStepsCounter(int r) {
		if (r == 0)
			return 0;
		else if (r < 3)
			return r;
		else if (r == 3)
			return 4;
		return 1 + RobbotStepsCounter(r - 1);

	}

	//
	int numOfOnes(int n) {
		int sum = 0;
		while (n > 0) {
			sum += n % 2;
			n = n >> 1; // shift right which is Divide the number over 10
		}
		return sum;
	}

	int numOfZeros(int n)
	{
		int sum = 0;
		while (n > 0) {
			if (n % 2 == 0)
				sum++;
			n = n >> 1; // shift right;
		}
		return sum;
	}
};

#endif // !GENERAL_H
