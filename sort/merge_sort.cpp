// #include "common.hpp"

// template<typename T>
// void merge(T arr[], T tmp[], int begin, int end){
//     int mid = (end + begin) / 2;
//     int p1 = begin, p2 = mid + 1, p = begin;
//     while(p1 <= mid && p2 <= end){
//         if (arr[p1] < arr[p2]){
//             tmp[p++] = arr[p1++];
//         }else{
//             tmp[p++] = arr[p2++];
//         }
//     }
//     while(p1 <= mid){
//         tmp[p++] = arr[p1++];
//     }
//     while(p2 <= end){
//         tmp[p++] = arr[p2++];
//     }
//     for (int i = begin; i <= end; ++i){
//         arr[i] = tmp[i];
//     }

// }

// template<typename T>
// void mergeSort(T arr[], T tmp[], int begin, int end){
//     if (begin >= end) return;
//     int mid = (end + begin) / 2;
//     mergeSort(arr, tmp, begin, mid);
//     mergeSort(arr, tmp, mid + 1, end);
//     merge(arr, tmp, begin, end);
// }

// int main()
// {
//     vector<int> arr{1, 3, 5, 8, 4, 6, 9, 2, 4};
//     vector<int> tmp(arr.size());
//     mergeSort(arr.data(), tmp.data(), 0, arr.size() - 1);
//     std::cout << arr;
// }

template <typename T>
void mergeSort(T arr[], int start, int end)
{
}