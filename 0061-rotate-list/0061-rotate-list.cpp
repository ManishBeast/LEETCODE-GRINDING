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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* curr = head;
        if(head==nullptr || head->next==nullptr) return head;
        int len=0;
        ListNode* temp = head;

        while(temp){
            temp=temp->next;
            len++;
        }
        k=k%len;
        if(k==0) return head;

        while(k>0){
                ListNode* curr = head;
            ListNode* node = curr->next;
        
            while(node->next!=nullptr && k>0){
                node=node->next;
                curr=curr->next;
            }
            node->next = head;
            curr->next = nullptr;
           head = node;
           k--;
        }
        return head;
    }
};


