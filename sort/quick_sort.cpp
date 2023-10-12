#include "common.hpp"

// template<typename T>
// void quickSort(T arr[], int begin, int end){
//     if (begin >= end) return;
//     T mid = arr[begin];
//     int left = begin + 1, right = end;
//     while(left < right){
//         while(arr[left] <= mid && left < right) ++left;
//         while(arr[right] >= mid && left < right) --right;
//         swap(arr[left], arr[right]);
//     }
//     if (mid > arr[left]) swap(arr[begin], arr[left]);

//     quickSort(arr, begin, left - 1);
//     quickSort(arr, left, end);
// }

template <typename T>
void quickSort(T[] data, int begin, int end) {
    if (begin >= end)
        return;
    int left = begin + 1, right = end;
    T pivotVal = data[begin];
    while (left < right) {
        while (data[left] <= pivotVal && left < right) left++;
        while (data[right] > pivotVal && left < right) right--;
        std::swap(data[left], data[right]);
    }
    if (pivotVal > data[left])
        std::swap(data[begin], data[left]);
    quickSort(data, begin, left - 1);
    quickSort(data, left, end);
}

template <typename T>
void bubbleSort(std::vector<T>& data) {
    size_t len = data.size();
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len - i - 1; ++j) {
            if (data[j] > data[j + 1]) {
                std::swap(data[j], data[j + 1]);
            }
        }
    }
}

int main() {
    vector<int> arr{1, 3, 5, 8, 4, 6, 9, 5, 2, 4};
    auto arr2 = arr;
    bubbleSort(arr2);
    std::cout << arr2;
    quickSort(arr.data(), 0, arr.size() - 1);

    std::cout << arr;
}