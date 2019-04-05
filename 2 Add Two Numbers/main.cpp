/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ln;
        ListNode* ln1=ln;
        ListNode* temp;
        int i1=0,i2=0;
        int jinwei;
        int cur=0,sum=0;
        int first=0;
        while(l1!=NULL||l2!=NULL||cur!=0)
        {
            if(l1!=NULL)
            {
                i1=l1->val;
            l1=l1->next;
            }
            else i1=0;
            if(l2!=NULL)
            {
                i2=l2->val;
            l2=l2->next;
            }
            else i2=0;
            sum=i1+i2;
            sum=sum+cur;
            if(sum>=10)
               cur=1;
            else cur=0;
            sum=sum%10;
            temp=new ListNode(sum);
            if(first==0)
            {
                ln=temp;
                ln1=temp;
            }
            else{
                ln1->next=temp;
                ln1=ln1->next;
            }

            first=1;
        }
        return ln;
    }
};



