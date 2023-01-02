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
        ListNode*temp= head;
        int length=0;
        
        while(temp)
        {
            length++;
            temp=temp->next;
        }
        if(length<2)
        {
            return head;
        }
        k=k%length;
        
        for(int i=0;i<k;i++)
        {
            temp=head;
            while(temp&&temp->next &&temp->next->next)
            {
                temp=temp->next;
            }
            ListNode*temp2=temp->next;
            temp2->next=head;
            head=temp2;
            temp->next=NULL;
            
        }
        return head;
    }
};