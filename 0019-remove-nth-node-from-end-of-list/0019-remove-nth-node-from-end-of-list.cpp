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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       int length=0;
        ListNode* temp=head;
        while(temp)
        {
        length++;
        temp=temp->next;    
        }
        int go=length-n;
        if(go==0)
        {
            return head->next;
        }
        temp=head;
    for(int i=0;i<go-1;i++)
    {
        temp=temp->next;
    }
        temp->next=temp->next->next;
        return head;
    }
};