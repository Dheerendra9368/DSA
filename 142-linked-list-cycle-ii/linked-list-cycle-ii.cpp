class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        int k=0;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                k=1;
                break;
            }
        }
        if(k==1){
            ListNode* temp=head;
            while(temp!=slow){
                slow=slow->next;
                temp=temp->next;
            }
            return temp;
        }
        return NULL;
    }
};