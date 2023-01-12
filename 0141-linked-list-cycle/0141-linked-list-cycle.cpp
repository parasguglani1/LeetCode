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
    bool hasCycle(ListNode *head) {
        ListNode* temp1=head,*temp2=head;
        if(!head||!head->next)
        {
            return false;
        }
        do
        {
            temp1=temp1->next;
             if(!temp2->next)
            {
                return false;
            }
            temp2=temp2->next->next;
           
        }
        while(temp2&& temp2->next &&temp1!=temp2);
        
        if(!temp2|| !temp2->next)
        {
            return false;
        }
        return true;
    }
};