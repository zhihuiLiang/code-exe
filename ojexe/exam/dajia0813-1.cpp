#include <iostream>
#include <memory>
#include <string>
#include <vector>

struct Node;
using NodePtr = std::shared_ptr<Node>;

struct Node {
    std::string name;
    std::vector<NodePtr> children;
};

int main() {
    std::string str;
    std::cin >> str;
    int n;
    std::cin >> n;
    std::vector<std::string> contents;
    for (int i = 0; i < n; ++i) {
        std::string tmp;
        std::cin >> tmp;
        contents.push_back(tmp);
    }

    NodePtr root = std::make_shared<Node>();
    root->name = contents[0];

    const auto dfs = [&](auto&& dfs, int& start, int depth) -> std::vector<NodePtr> {
        std::vector<NodePtr> children;
        NodePtr newNode = std::make_shared<Node>(Node{contents[start], {}});
        children.push_back(newNode);
        ++start;
        while (start < n) {
            int curDepth = contents[start].find_last_of('-') + 1;
            if (curDepth != depth) {
                newNode->children = dfs(dfs, start, depth + 1);
                break;
            }
            children.push_back();
            ++start;
        }

        return children;
    };
    root->children = dfs(dfs, 0, 0);

    return 0;
}