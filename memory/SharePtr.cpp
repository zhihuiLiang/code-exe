#include <iostream>
using namespace std;

template<typename T>
class SharePtr{
public:
    SharePtr() noexcept : ptr_(nullptr), cnt_ptr_(nullptr){}
    SharePtr(T* ptr) noexcept {
        if (ptr == nullptr){
            return;
        }
        ptr_ = ptr;
        cnt_ptr_ = new size_t(1);
    }
    SharePtr(const SharePtr& other){
        ptr_ = other.ptr_;
        ++(*other.cnt_ptr_);
        cnt_ptr_ = other.cnt_ptr_;
    }
    SharePtr& operator=(const SharePtr& other){
        if (this == &other){
            return *this;
        }
        if (cnt_ptr_ != nullptr){
            (*cnt_ptr_)--;
        }
        ptr_ = other.ptr_;
        ++(*other.cnt_ptr_);
        cnt_ptr_ = other.cnt_ptr_;
        return *this;
    }
    SharePtr(SharePtr&& other) = default;
    SharePtr& operator=(SharePtr&& other) = default;
    ~SharePtr(){
        if (cnt_ptr_ == nullptr){
            return;
        }
        --(*cnt_ptr_);
        if (*cnt_ptr_ > 0){
            return;
        }
        std::cout << "deconstruct" << std::endl;
        delete cnt_ptr_;
        delete ptr_; 
    }
    T* operator->()const{
        return ptr_;
    }

    T& operator*() const{
        return *ptr_;
    }

    size_t use_count() const{
        return *cnt_ptr_;
    }
private:
    T* ptr_;
    size_t* cnt_ptr_;
};

int main(){
    const auto a = new int(1);
    {
        SharePtr<int> p1(a);
        std::cout << *p1 << endl;
        SharePtr<int> p2(new int(20));
        std::cout << p1.use_count() << " " << p2.use_count() << endl;
        p1 = p2;
        std::cout << p1.use_count() << " " << p2.use_count() << endl;
    }
}