class Solution {
public:
    ListNode* ans(ListNode* curr, ListNode* prev) {
        if (curr == nullptr)
            return prev;
        ListNode* next = curr->next;
        curr->next = prev;
        return ans(next, curr);
    }
    
    ListNode* reverseList(ListNode* head) {
        return ans(head, nullptr);
    }
};