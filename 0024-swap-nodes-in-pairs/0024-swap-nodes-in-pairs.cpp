/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *    ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* swapPairs(ListNode *head)
        {
            ListNode *head2 = new ListNode(0);
            head2->next = head;
            bool flag = 1;
            ListNode *temp = head2-> next;

            while (temp && temp->next)
            {
                if (flag)
                {
                    // ListNode *node1 = temp, *node2 = temp->next;

                    // swap(*node1, *node2);
                    swap(temp->val, temp->next->val);
                    flag = 0;
                }
                else
                {
                    flag = 1;
                }
                temp=temp->next;
            }
            return head2->next;
        }
};