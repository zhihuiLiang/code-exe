
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* sucessor = nullptr;
        const auto reveseA2B = [&](auto&& reveseA2B, ListNode* from, ListNode* to) {
            if (from == to) {
                sucessor = to->next;
                return from;
            }
            auto last = reveseA2B(reveseA2B, from->next, to);
            from->next->next = from;
            from->next = sucessor;
            return last;
        };
        auto a = head, b = head;
        for (int i = 1; i < k; ++i) {
            b = b->next;
            if (!b) {
                return a;
            }
        }
        reverseKGroup(b->next, k);
        auto ans = reveseA2B(reveseA2B, a, b);
        return ans;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    auto fix = head;
    head->next = new ListNode(2);
    head = head->next;
    head->next = new ListNode(3);
    head = head->next;
    head->next = new ListNode(4);
    head = head->next;
    head->next = new ListNode(5);
    head = head->next;
    auto cur = Solution().reverseKGroup(fix, 2);
}