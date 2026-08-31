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
        vector<int> ans(2,-1);
        int fidx=-1;
        int sidx=-1;
        int f=-1;
        int s=-1;
        ListNode* temp=head->next;
        ListNode* prev=head;
        ListNode* Next=temp->next;
        int i=1;
        int mind=INT_MAX;
        while(Next!=NULL){
            if((temp->val<prev->val && temp->val<Next->val) ||(temp->val>prev->val && temp->val>Next->val)){
                //maxd
                if(fidx==-1) fidx=i;
                else sidx=i;
                //mind
                f=s;
                s=i;
                if(f!=-1){
                    mind=min(mind,s-f);
                }
                }
            
            Next=Next->next;
            temp=temp->next;
            prev=prev->next;
            i++;
        }
        if(sidx==-1) return ans;
        ans[1]=sidx-fidx;
        ans[0]=mind;
        return ans;
    }
};