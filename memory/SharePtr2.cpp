// #include <atomic>
#include <stdlib.h>

#include <iostream>

// template <class T>
// class SharedPtr {
//     T* mPtr;
//     std::atomic<int>* mRefCntPtr;

// public:
//     SharedPtr() : mPtr(nullptr), mRefCntPtr(nullptr) {}
//     SharedPtr(T* ptr) : mPtr(nullptr), mRefCntPtr(new std::atomic<int>(1)) {}
//     SharedPtr(const SharedPtr& other) {
//         mPtr = other.mPtr;
//         mRefCntPtr = other.mRefCntPtr;
//         ++(*mRefCntPtr);
//     }

//     SharedPtr& operator=(const SharedPtr& other) {
//         mPtr = other.mPtr;
//         (*other.mRefCntPtr)++;
//         (*mRefCntPtr)--;
//         mRefCntPtr = other.mRefCntPtr;
//         return *this;
//     }

//     ~SharedPtr() {
//         if (*mRefCntPtr > 0) {
//             --(*mRefCntPtr);
//         }

//         if (*mRefCntPtr == 0) {
//             delete mPtr;
//             delete mRefCntPtr;
//         }
//         std::cout << "deconstruct func" << std::endl;
//     }

//     T* get() const {
//         return mPtr;
//     }
// };

// template <class T, class... Args>
// SharedPtr<T> makeShared(Args&&... args) {
//     T* objPtr = new T(std::forward<Args>(args)...);
//     return SharedPtr(objPtr);
// }

int main() {
    // SharedPtr<int> ptr(new int(2));
    // ptr = makeShared<int>(3);
    int a = rand() % 5;
    int b[a];
    std::cout << sizeof(b) << std::endl;
}