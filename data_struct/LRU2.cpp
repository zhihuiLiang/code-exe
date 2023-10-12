#include <iostream>
#include <unordered_map>

struct Node {
    int key_, val_;
    Node* prev_;
    Node* next_;

    Node(int key, int val) : key_(key), val_(val) {
        prev_ = nullptr;
        next_ = nullptr;
    }
};

struct BidirList {
    Node* fakeHead_;
    Node* fakeTail_;

    BidirList() {
        fakeHead_ = new Node(-1, 0);
        fakeTail_ = new Node(-1, 0);
        fakeHead_->next_ = fakeTail_;
        fakeHead_->prev_ = nullptr;
        fakeTail_->prev_ = fakeHead_;
        fakeTail_->next_ = nullptr;
    }

    void addNode(int key, int val) {
        Node* newNode = new Node(key, val);
        fakeTail_->prev_->next_ = newNode;
        newNode->prev_ = fakeTail_->prev_;
        fakeTail_->prev_ = newNode;
        newNode->next_ = fakeTail_;
    }

    void moveToEnd(Node* node) {
        node->prev_->next_ = node->next_;
        node->next_->prev_ = node->prev_;
        fakeTail_->prev_->next_ = node;
        node->prev_ = fakeTail_->prev_;
        node->next_ = fakeTail_;
        fakeTail_->prev_ = node;
    }

    void removeHead() {
        auto targetNode = fakeHead_->next_;
        fakeHead_->next_ = targetNode->next_;
        targetNode->next_->prev_ = fakeHead_;
        delete targetNode;
    }

    Node* front() const {
        return fakeHead_->next_;
    }

    Node* back() const {
        return fakeTail_->prev_;
    }

    ~BidirList() {
        Node* cur = fakeHead_->next_;
        while (cur != fakeTail_) {
            auto next = cur->next_;
            delete cur;
            cur = next;
        }
    }
};

class LRUCache {
    std::unordered_map<int, Node*> keyMap_;
    BidirList bidirList;

    size_t cap_;
    size_t size_;

public:
    LRUCache(int size) : cap_(size), size_(0) {
    }

    int get(int key) {
        if (!keyMap_.count(key)) {
            std::cout << "key: " << key << "does not exist" << std::endl;
            return -1;
        }
        auto node = keyMap_[key];
        int ret = node->val_;
        bidirList.moveToEnd(node);
        std::cout << " get-->key: " << key << " val:" << ret << std::endl;
        return ret;
    }

    void eraseHead() {
        auto key = bidirList.front()->key_;
        bidirList.removeHead();
        keyMap_.erase(key);
        size_--;
    }

    void put(int key, int val) {
        if (keyMap_.count(key)) {
            auto node = keyMap_[key];
            node->val_ = val;
            bidirList.moveToEnd(node);
        } else {
            if (size_ == cap_) {
                eraseHead();
            }

            bidirList.addNode(key, val);
            keyMap_[key] = bidirList.back();
            size_++;
        }
    }

    std::ostream& operator<<(std::ostream& os) {
        auto cur = bidirList.front();
        while (cur != bidirList.back()->next_) {
            os << " key: " << cur->key_ << " val: " << cur->val_;
            cur = cur->next_;
        }
        return os;
    }
};

int main() {
    LRUCache lruCache(3);
    lruCache.put(1, 2);
    lruCache.put(2, 3);
    lruCache << std::cout << std::endl;
    lruCache.get(1);
    lruCache << std::cout << std::endl;
    lruCache.put(5, 6);
    lruCache << std::cout << std::endl;
    lruCache.get(1);
    lruCache << std::cout << std::endl;
    lruCache.put(3, 4);
    lruCache << std::cout << std::endl;
    lruCache.put(5, 6);
    lruCache << std::cout << std::endl;
    return 0;
}