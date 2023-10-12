#include <iostream>
#include <unordered_map>

class LRUCache
{

    struct Node
    {
        int key = 0, val = 0;
        Node *prev = nullptr;
        Node *next = nullptr;
    };

    std::unordered_map<int, Node *> map;
    Node *fakeHead;
    Node *fakeTail;

    size_t size = 0;
    size_t capicity = 0;

    void moveToEnd(Node *node_ptr)
    {
        removeNode(node_ptr);
        fakeTail->prev->next = node_ptr;
        node_ptr->prev = fakeTail->prev;
        fakeTail->prev = node_ptr;
        node_ptr->next = fakeTail;
    }

    void pop_front()
    {
        removeNode(fakeHead->next);
        size--;
    }

    void deleteNode(Node *node_ptr)
    {
        removeNode(node_ptr);
        map.erase(node_ptr->key);
        delete node_ptr;
    }

    void addNode(Node *node_ptr)
    {
        fakeTail->prev->next = node_ptr;
        node_ptr->prev = fakeTail->prev;
        fakeTail->prev = node_ptr;
        node_ptr->next = fakeTail;
        map[node_ptr->key] = node_ptr;
        ++size;
    }

    void removeNode(Node *node_ptr)
    {
        node_ptr->prev->next = node_ptr->next;
        node_ptr->next->prev = node_ptr->prev;
        node_ptr->prev = nullptr;
        node_ptr->next = nullptr;
    }

public:
    LRUCache(int cap)
    {
        fakeHead = new Node();
        fakeTail = new Node();
        fakeHead->next = fakeTail;
        fakeTail->prev = fakeHead;
        capicity = cap;
    }

    int get(int key)
    {
        if (!map.count(key))
        {
            return -1;
        }
        Node *node_ptr = map[key];
        int ret = node_ptr->val;
        moveToEnd(node_ptr);
        std::cout << " get-->key: " << key << " val:" << ret << std::endl;
        return ret;
    }
    void put(int key, int val)
    {
        if (map.count(key))
        {
            Node *node_ptr = map[key];
            node_ptr->val = val;
        }
        if (size == capicity)
        {
            pop_front();
        }
        Node *newNode = new Node{key, val};
        addNode(newNode);
    }
    void erase(int key)
    {
        if (!map.count(key))
            return;
        Node *node_ptr = map[key];
        removeNode(node_ptr);
    };

    std::ostream &operator<<(std::ostream &os)
    {
        Node *cur = fakeHead->next;
        while (cur != fakeTail)
        {
            os << " key: " << cur->key << " val: " << cur->val;
            cur = cur->next;
        }
        return os;
    }
};

int main()
{
    LRUCache lruCache(2);
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