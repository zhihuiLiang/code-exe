#include <iostream>
#include <memory>

template <class TKey, class TVal>
struct Node;

template <class TKey, class TVal>
using NodePtr = std::shared_ptr<Node<TKey, TVal>>;

template <class TKey, class TVal>
struct Node {
    TKey key;
    TVal val;
    NodePtr<TKey, TVal> left;
    NodePtr<TKey, TVal> right;

    Node(TKey k, TVal v) : key(k), val(v), left(nullptr), right(nullptr) {}
};

template <class TKey, class TVal>
class BinarySearchTree {
public:
    NodePtr<TKey, TVal> root;

    BinarySearchTree() : root(nullptr) {}

    static NodePtr<TKey, TVal> search(const NodePtr<TKey, TVal>& cur, TKey k) {
        if (!cur)
            return cur;
        if (cur->key > k) {
            return search(cur->right, k);
        } else if (cur->key < k) {
            return search(cur->left, k);
        } else {
            return cur;
        }
    }

    static NodePtr<TKey, TVal> insert(NodePtr<TKey, TVal>& cur, TKey k, TVal v) {
        if (!cur) {
            cur = std::make_shared<Node<TKey, TVal>>(k, v);
            return cur;
        }
        if (cur->key > k) {
            cur->left = insert(cur->left, k, v);
        } else if (cur->key < k) {
            cur->right = insert(cur->right, k, v);
        }
        return cur;
    }

    static NodePtr<TKey, TVal> remove(NodePtr<TKey, TVal>& cur, TKey k) {
        if (!cur)
            return cur;

        if (cur->key > k) {
            cur->left = remove(cur->left, k);
        } else if (cur->key < k) {
            cur->right = remove(cur->right, k);
        } else {
            if (!cur->left && !cur->right) {
                cur = nullptr;
            } else if (cur->left && !cur->right) {
                cur = cur->left;
            } else if (cur->right && !cur->left) {
                cur = cur->right;
            } else {
                auto next = cur->left;
                while (next->rchild) {
                    next = next->rchild;
                }
                cur->key = next->key;
                cur->val = next->val;
                cur->left = remove(next, k);
            }
        }
        return cur;
    }

    static void travese(NodePtr<TKey, TVal> node) {
        if (!node)
            return;
        travese(node->left);
        std::cout << "key: " << node->key << " val: " << node->val << std::endl;
        travese(node->right);
    }
};

int main() {
    BinarySearchTree<int, int> bst;
    BinarySearchTree<int, int>::insert(bst.root, 1, 2);
    BinarySearchTree<int, int>::insert(bst.root, 4, 3);
    BinarySearchTree<int, int>::insert(bst.root, 8, 1);
    BinarySearchTree<int, int>::insert(bst.root, 2, 4);
    BinarySearchTree<int, int>::insert(bst.root, 6, 3);
    BinarySearchTree<int, int>::insert(bst.root, 5, 2);
    BinarySearchTree<int, int>::travese(bst.root);
}