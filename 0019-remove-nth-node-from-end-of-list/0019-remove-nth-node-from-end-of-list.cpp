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
        
        ListNode* temp =head;
        int len=0;
        while(temp)
        {
            len++;
            temp=temp->next;
        }
        int remove=len-n;
        // cout<<remove<<" ";
        if (len==1 && n==1 )
        {
            return nullptr;
        }
        if(remove==0)
        {
            return head->next;
        }
        temp=head;
        int pos=0;
        while(pos<remove-1 &&temp->next)
        {
            temp=temp->next;
            pos++;
        }
        temp->next=temp->next->next;
        return head;
    }
};