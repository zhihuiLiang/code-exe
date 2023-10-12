#include <iostream>
#include <string>
#include <vector>

struct Node {
    int hour;
    int minute;
};

Node tfStrToTime(std::string str) {
    int p = str.find(':');
    std::string sub1 = str.substr(0, p), sub2 = str.substr(p + 1);
    Node node;
    node.hour = std::stoi(sub1);
    node.minute = std::stoi(sub2);
    return node;
}

int main() {
    int in;
    std::cin >> in;
    std::vector<Node> inTime;
    for (int i = 0; i < in; ++i) {
        std::string str;
        std::cin >> str;
        inTime.emplace_back(tfStrToTime(str));
    }

    int out;
    std::cin >> out;
    std::vector<Node> outTime;
    for (int i = 0; i < out; ++i) {
        std::string str;
        std::cin >> str;
        outTime.emplace_back(tfStrToTime(str));
    }

    Node sum;
    for (int i = 0; i < out; ++i) {
    }
}
