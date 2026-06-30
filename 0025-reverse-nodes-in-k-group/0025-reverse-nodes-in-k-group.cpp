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
    ListNode* reverse(ListNode* head){
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* getKth(ListNode* head,int k ){
        k--;
        while(head!=nullptr && k>0){
            head = head->next;
            k--;
        }
        return head;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = nullptr;
         if(temp==nullptr|| temp->next==nullptr || k==0){
            return temp;
        }
        while(temp){
            ListNode* kth = getKth(temp,k);
            if(kth==nullptr){
                if(prevLast){
                    prevLast->next=temp;
                    break;
                }
            }
            ListNode* ahead=kth->next;
            kth->next = nullptr;
            reverse(temp);
            if(temp==head){
                head = kth;
            }else{
                prevLast->next = kth;
            }
            prevLast = temp;
            temp = ahead;
        }
        return head;
    }
};