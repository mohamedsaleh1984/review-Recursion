#pragma once
class ArrayRecusiveAlgo {
public:
	/*
	* tail recursive function
	*
	*/
	int arraySum(int numbers[], int size) {
		if (size == 0)
			return 0;

		return numbers[size - 1] + arraySum(numbers, size - 1);
	}
	
	/*
	If the last digit of a binary number is 1, the number is odd; if it's 0, the number is even. Ex:
	*/
	bool EvenOdd(int numbers[], int size) {
		if (size == 0)
			return 0;
		int onesCounter = EvenOdd(numbers, size - 1);
		if (numbers[size - 1] == 1)
			onesCounter++;

		return onesCounter % 2;
	}

	int zeroCountRecursive(int numbers[], int size) {
		if (size == 0)
			return 0;
		int count = zeroCountRecursive(numbers, size - 1);
		if (numbers[size - 1] == 0)
			count++;
		return count;
	}

	int occuranceRecursive(int numbers[], int size, int target) {
		if (size == 0)
			return 0;

		int occur = occuranceRecursive(numbers, size - 1, target);

		if (numbers[size - 1] == target) {
			occur++;
		}
		return occur;
	}

	//find the index of smallest number
	int IndexOfSmallestNumber(int arr[], int n, int& pos) {
		if (n == 0)
			return pos;

		if (n == 1)
			return 0;

		if (arr[n - 1] < arr[pos])
			pos = n - 1;

		IndexOfSmallestNumber(arr, n - 1, pos);
	}


	//Aux function to swap ranges...
	void SwapRange(int arr[], int size, int from, int to) {
		if (from >= to)
			return;
		int temp = arr[from];
		arr[from] = arr[to];
		arr[to] = temp;

		return SwapRange(arr, size, ++from, --to);
	}
	int steps[1000];

	int stepPerms(int n) {
		if (n < 0)
			return 0;
		if (n == 1)
			return 1;
		if (n == 2)
			return 2;
		if (n == 3)
			return 4;

		if (steps[n] != 0)
			return steps[n];
		else {
			steps[n] = stepPerms(n - 1) + stepPerms(n - 2) + stepPerms(n - 3);
			return steps[n];
		}
	}

	int JumbIt(int array[], int size, int& InitStep) {
		if (InitStep >= size)
			return array[size - 1];

		int a = array[InitStep + 1];
		int b = array[InitStep + 2];
		if (a > b)
			InitStep += 2;
		else
			InitStep++;
		int v = JumbIt(array, size, InitStep);
		return array[InitStep] + v;
	}

	int BinarySearch(vector<int> vec, int target) {
		if (vec.size() == 0 || vec.size() == 1 && vec[0] != target)
			return -1;
		if (vec.size() == 1 && vec[0] == target)
			return 0;
		
		return BinarySearchHelper(vec, target, 0, vec.size() - 1);
	}
	
	int BinarySearchHelper(vector<int> vec, int target, int l, int r)
	{
		if (r < l)
			return -1;
		int mid = (l + r) / 2;

		if (vec[mid] == target)
			return mid;
		
		if (target > vec[mid])
			return BinarySearchHelper(vec, target, mid + 1, r);
		return BinarySearchHelper(vec, target, 0, mid - 1);


		return 0;
	}
};