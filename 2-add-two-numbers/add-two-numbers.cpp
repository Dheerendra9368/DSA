
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        ListNode* t=new ListNode(-1);
        ListNode* t2=t;
        int c=0;
        while(temp1!=NULL && temp2!=NULL){
            int sum=(temp1->val)+(temp2->val);
            int Val=sum;
            if(c>0){
                Val+=1;
                c--;
            }
            if(Val>=10){
                c++;
            }
    
            ListNode* NewN=new ListNode((Val%10));
            t->next=NewN;
            t=t->next;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        while(temp1!=NULL){
            int Val=temp1->val;
            if(c>0){
                Val+=1;
                c--;
            }
            if(Val>=10) c++;
           ListNode* NewN=new ListNode((Val%10));
            t->next=NewN;
            t=t->next; 
            temp1=temp1->next;
        }
        while(temp2!=NULL){
            int Val=temp2->val;
            if(c>0){
                Val+=1;
                c--;
            }
            if(Val>=10) c++;
           ListNode* NewN=new ListNode((Val%10));
            t->next=NewN;
            t=t->next; 
            temp2=temp2->next;
        }
        while(c>0){
            ListNode* NewN=new ListNode(c);
            t->next=NewN;
            t=t->next;
            c--;
        }
        return t2->next;
    }
};