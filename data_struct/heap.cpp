#include "common.hpp"


// Index 0 is empty data
template <typename T, typename Cmp = less<T>>
class Heap{
    T* data_;
    size_t cap_;
    size_t size_;
public:
    Heap() : cap_(0), size_(0){};
    Heap(size_t n){
        data_ = new T[n];
        cap_ = n;
        size_ = 1;
    }
    int parentIdx(int idx){
        return idx / 2;
    }
    size_t size(){
        return size_ - 1;
    }
    void siftUp(){
        int idx = size_ - 1, p_idx = parentIdx(idx);
        while(idx > 0 && Cmp()(data_[idx], data_[p_idx])){
            swap(data_[idx], data_[p_idx]);
            idx = p_idx;
            p_idx = parentIdx(idx);
        } 
    }
    T insert(T val){
        if (size_ + 1 > cap_) return -1;
        data_[size_] = val;
        size_ += 1;
        siftUp();
        return 0;
    }
    T getHeapTop(){
        if (size_ <= 1) throw out_of_range("Heap out of range");
        return data_[1];
    }
    void popHeapTop(){
        if (size_ <= 1) return;
        int ans = data_[1];
        swap(data_[1], data_[size_]);
        size_ -= 1;
        int idx = 1;
        while (idx * 2 <= size_){
            int left = idx * 2, right = left + 1, k = left;
            if (right <= size_ && Cmp()(data_[right], data_[left])){
                k = right;
            }
            if (Cmp()(data_[idx], data_[k])){
                break;    
            }
            swap(data_[idx], data_[k]);
            idx = k;
        }
        
    }

    friend ostream& operator<<(ostream& out, const Heap& h){
        for (int i = 1; i < h.size_; ++i){
            out << h.data_[i] << " ";
        }
        out << endl;
        return out;
    }
    ~Heap(){
        delete data_;
    }
};

int main(){
    Heap<int> h(10);

    random_device r;
    mt19937 gen(r());
    uniform_int_distribution<> distr(1, 100);
    for (int i = 0; i < 8; ++i){
        h.insert(distr(gen));
    }
    for (int i = 0; i < 8; ++i){
        cout << h;
        h.popHeapTop();
    }
    cout << h;
}