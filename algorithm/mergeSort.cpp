#include "Array.hpp"

template<class T>
void merge(Array<T> arr, int l, int mid, int r) {
    vector<int> temp(r - l + 1);
    int i = l;        // 左区间起点
    int j = mid + 1;  // 右区间起点
    int k = 0;        // 临时数组下标

    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= r) {
        temp[k++] = arr[j++];
    }

    for (int p = 0; p < temp.size(); ++p) {
        arr[l + p] = temp[p];
    }
}

template<class T>
void mergeSort(Array<T> arr, int l, int r) {
    if (l >= r) return;

    int mid = l + (r - l) / 2;

    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}