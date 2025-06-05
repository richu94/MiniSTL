#include "Array.hpp"

template<class T>
int binary_search(Array<T> arr, T key) {
	int left = 0, right = arr.GetLength() - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		T value = arr[mid];
		if (value == key) {
			return mid + 1;
		}
		else if (value > key) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return -1;
}

template<class T>
int binary_search_recursion(Array<T> arr, int left, int right, T key) {
	if (left > right) {
		return -1;
	}
	int mid = (left + right) / 2;
	T value = arr[mid];
	if (value == key) {
		return mid + 1;
	}
	else if (value > key) {
		binary_search_recursion(arr, left, mid - 1, key);
	}
	else {
		binary_search_recursion(arr, mid + 1, right, key);
	}
}

template<class T>
int binary_search(Array<T>* arr,T key) {
	int left = 0, right = arr->GetLength() - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		T value = arr->ArrayGetById(mid);
		if (value == key) {
			return mid + 1;
		}
		else if (value > key) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return -1;
}

template<class T>
int binary_search_recursion(Array<T>* arr,int left,int right , T key) {
	if (left > right) {
		return -1;
	}
	int mid = (left + right) / 2;
	T value = arr->ArrayGetById(mid);
	if (value == key) {
		return mid + 1;
	}
	else if (value > key) {
		binary_search_recursion(arr,left,mid - 1,key);
	}
	else {
		binary_search_recursion(arr, mid + 1, right, key);
	}
}

int main() {
	//Array<int>* arr = new Array<int>(10,0);
	//for (int i = 0; i <= 9; i++) {
	//	arr->ChangeValue(i, i);
	//}
	//int res = binary_search(arr,11);
	//printf("%d", res);

	//int left = 0, right = arr->GetLength() - 1;
	//int res = binary_search_recursion(arr, left, right, 4);
	//printf("%d", res);

	Array<int> array(10, 0);
	for (int i = 0; i <= 9; i++) {
		array[i] = i;
	}
	int res = binary_search(array, 6);
	printf("%d", res);
	return 0;
}