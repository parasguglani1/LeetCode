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
    ListNode* reverseList(ListNode* head) {
        ListNode* curr,*prev,*forward=nullptr;
        ListNode* temp=new ListNode();
        
        prev=nullptr;
        curr=head;
        if(head)
        forward=head->next;
        while(forward)
   {     
        curr->next=prev;
        prev=curr;
        curr=forward;
        forward=forward->next;
        
        }
        if(curr)
        curr->next=prev;
        
     return curr;   
    }
};