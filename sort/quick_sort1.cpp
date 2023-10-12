#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

template <class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    for (auto v : vec) {
        os << v << " ";
    }
    os << std::endl;
    return os;
}

template <class T>
int partition(T arr[], int begin, int end) {
    int pivotVal = arr[begin];
    int left = begin + 1, right = end;
    while (left < right) {
        while (arr[left] <= pivotVal && left < right) ++left;
        while (arr[right] >= pivotVal && left < right) --right;
        std::swap(arr[left], arr[right]);
    }
    if (arr[left] < pivotVal) {
        std::swap(arr[left], arr[begin]);
    }
    return left;
}

template <class T>
void quickSort(T arr[], int begin, int end) {
    if (begin >= end)
        return;
    int left = partition(arr, begin, end);
    quickSort(arr, begin, left - 1);
    quickSort(arr, left, end);
}

template <class T>
void quickSortNoRecursive(T arr[], int begin, int end) {
    std::stack<std::pair<int, int>> sta;
    sta.push({begin, end});

    while (!sta.empty()) {
        auto [s, e] = sta.top();
        sta.pop();

        while (s < e) {
            int left = partition(arr, s, e);
            sta.push({left, e});
            e = left - 1;
        }
    }
}

template <class T>
void mergeSort(T arr[], int begin, int end) {
    if (begin >= end) {
        return;
    }

    int mid = (end - begin) / 2 + begin;
    mergeSort(arr, begin, mid);
    mergeSort(arr, mid + 1, end);

    int p1 = begin, p2 = mid + 1, p = 0;
    int size = end - begin + 1;
    T tmp[size];
    while (p1 <= mid && p2 <= end) {
        if (arr[p1] <= arr[p2]) {
            tmp[p++] = arr[p1++];
        } else {
            tmp[p++] = arr[p2++];
        }
    }
    while (p1 <= mid) {
        tmp[p++] = arr[p1++];
    }
    while (p2 <= end) {
        tmp[p++] = arr[p2++];
    }
    for (int i = 0; i < size; ++i) {
        arr[begin++] = tmp[i];
    }
}

int main() {
    std::vector<int> arr{1, 3, 5, 8, 4, 6, 9, 5, 2, 4};
    auto arr2 = arr;
    quickSort(arr2.data(), 0, arr2.size() - 1);
    auto arr3 = arr;
    mergeSort(arr3.data(), 0, arr3.size() - 1);
    auto arr4 = arr;
    quickSortNoRecursive(arr4.data(), 0, arr4.size() - 1);

    std::cout << arr2;
    std::cout << arr3;
    std::cout << arr4;
}