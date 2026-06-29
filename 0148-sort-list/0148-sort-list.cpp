/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* left,ListNode* right){
        if(left==nullptr && right==nullptr) return nullptr;
        ListNode* dummy = new ListNode (-1);
        ListNode* temp = dummy;
        while(left && right){
            if(left->val<=right->val){
                temp->next = left;
                left=left->next;
            }else{
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }
            if(left){
                temp->next = left;
            }
            if(right){
                temp->next = right;
            }
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* middle = mid(head);
        ListNode* rightHead=middle->next;
        middle->next = nullptr;
        ListNode* left = sortList(head);
        ListNode* right = sortList(rightHead); 
        return merge(left,right);
    }
};