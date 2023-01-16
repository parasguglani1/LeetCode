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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
  int n1=0,n2=0;
        ListNode* temp1=headA,*temp2=headB;
        while(temp1)
        {
            temp1=temp1->next;
            n1++;
            
        }
         while(temp2)
        {
            temp2=temp2->next;
            n2++;
            
        }
        temp1=headA;
        temp2=headB;
        if(n1>n2)
        {
        int i=n1-n2;
            
            
            while(i--)
            {
                temp1=temp1->next;
            }
        }
        
        else
        {
            int i=n2-n1;
            while(i--)
            {
                temp2=temp2->next;
            }
        }
        while(temp1&&temp2)
        {
            if(temp1==temp2)
            {
                return temp1;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return nullptr;
        
    }
};