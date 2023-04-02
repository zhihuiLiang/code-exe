#include "common.hpp"

template<typename T>
void quickSort(T arr[], int begin, int end){
    if (begin >= end) return;
    T mid = arr[begin];
    int left = begin + 1, right = end;
    while(left < right){
        while(arr[left] <= mid && left < right) ++left;
        while(arr[right] >= mid && left < right) --right;
        swap(arr[left], arr[right]);
    }
    if (mid > arr[left]) swap(arr[begin], arr[left]);

    quickSort(arr, begin, left - 1);
    quickSort(arr, left, end);
}

int main(){
    vector<int> arr{1, 3, 5, 8, 4, 6, 9, 5, 2, 4};
    quickSort(arr.data(), 0, arr.size() - 1);
    std::cout << arr;
}