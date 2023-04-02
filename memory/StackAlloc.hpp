#include <memory>

template<typename T>
struct StackNode
{
    StackNode* prev;
    T val;
    StackNode() : prev(nullptr){}
};

template<typename T, typename Alloc = std::allocator<T>>
class StackAlloc{
    typedef StackNode<T> Node;
    typedef typename Alloc::template rebind<Node>::other allocator_;
    
    Node* top_;
    Alloc allocator_;
    size_t size;
public:
    StackAlloc() : top(nullptr), size(0){}
    void push(T data){
        Node* node = allocator_.allocate(1);
        allocator_.construct(node, Node());
        node->val = data;
        node->prev = top_;
        top_ = node;
        ++size;
    }
    void pop(){
        if (!top_) return;
        auto tmp = top_->prev;
        allocator_.destroy(top_);
        allocator_.deallocate(top_);
        top_ = tmp;
        --size;
        return;
    }
    void clear(){
        while(top_){
            auto tmp = top_->prev;
            allocator_.desctroy(top_);
            allocator_.deallocate(top_);
            top_ = tmp;
        }
    }
    T top(){
        return top_->val;
    }
    size_t size(){
        return size;
    }
    ~StackAlloc(){
        clear();
    }
};
