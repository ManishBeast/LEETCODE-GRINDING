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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> temp;
        while(head){
            temp.push_back(head->val);
            head = head->next;
        }
        vector<int> maxi;
        for(int i=1;i<temp.size()-1;i++){
            if(temp[i]>temp[i-1] && temp[i]>temp[i+1]){
                maxi.push_back(i);
            }
           if(temp[i]<temp[i-1] && temp[i]<temp[i+1]){
                maxi.push_back(i);
            }
        }
        sort(maxi.begin(),maxi.end());
        int a=0;
        int b=INT_MAX;
        if(maxi.size()<=1){
            a = -1;
        }else{
            a = maxi[maxi.size()-1]-maxi[0];
        }
        if(maxi.size()<=1){
            b=-1;
        }else{
        for(int i=1;i<maxi.size();i++){
            int k = maxi[i]-maxi[i-1];
            b = min(b,k);
        }
        }

        return {b,a};  
    }
};