/**
 *Definition for singly-linked list.
 *struct ListNode {
 *   int val;
 *   ListNode * next;
 *   ListNode() : val(0), next(nullptr) {}
 *   ListNode(int x) : val(x), next(nullptr) {}
 *   ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* deleteMiddle(ListNode *head)
        {
            ListNode *temp = head;
            int count = 0;
            while (temp != NULL)
            {
                temp = temp->next;
                count++;
            }
            int x = count / 2;
            ListNode *temp2 = head;
            x--;
            while (x != 0 &&temp2)
            {
                temp2 = temp2->next;
                x--;
            }
            // cout << count << endl;
            // cout << temp2->val << endl;
           	// ListNode *temp3 = head;
            if(count==1)
            {
                return nullptr;
            }
            if (temp2 )
                temp2->next = temp2->next->next;
            return head;
        }
};