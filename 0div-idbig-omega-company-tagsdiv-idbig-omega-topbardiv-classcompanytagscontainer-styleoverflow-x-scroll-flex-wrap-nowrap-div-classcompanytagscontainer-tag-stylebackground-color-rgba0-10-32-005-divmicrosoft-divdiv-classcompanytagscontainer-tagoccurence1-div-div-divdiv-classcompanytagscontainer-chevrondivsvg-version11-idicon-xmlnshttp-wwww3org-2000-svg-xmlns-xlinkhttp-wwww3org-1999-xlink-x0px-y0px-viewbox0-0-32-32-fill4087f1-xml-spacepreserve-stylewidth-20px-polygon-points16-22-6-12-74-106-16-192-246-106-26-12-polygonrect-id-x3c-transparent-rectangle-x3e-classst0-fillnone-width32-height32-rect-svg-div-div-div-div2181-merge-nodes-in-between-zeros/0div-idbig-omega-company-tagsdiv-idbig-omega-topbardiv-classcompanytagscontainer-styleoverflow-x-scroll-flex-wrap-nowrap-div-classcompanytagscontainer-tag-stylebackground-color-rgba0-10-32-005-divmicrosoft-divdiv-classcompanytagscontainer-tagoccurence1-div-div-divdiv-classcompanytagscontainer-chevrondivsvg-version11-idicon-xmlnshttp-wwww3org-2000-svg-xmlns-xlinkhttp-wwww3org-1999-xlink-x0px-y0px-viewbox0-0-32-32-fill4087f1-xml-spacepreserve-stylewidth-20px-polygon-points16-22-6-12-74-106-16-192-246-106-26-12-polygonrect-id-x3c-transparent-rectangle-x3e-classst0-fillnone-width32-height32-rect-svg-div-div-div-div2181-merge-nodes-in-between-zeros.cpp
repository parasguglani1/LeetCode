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
        ListNode* mergeNodes(ListNode *head)
        {
            int sm = 0;
            ListNode *ans = new ListNode(0);
            ListNode *tail = ans;
            head = head->next;
            while (head)
            {
                if (head->val == 0)
                {

                    tail->next = new ListNode(sm);
                    tail = tail->next;
                    sm = 0;
                }
                else
                {
                    sm+=head->val;
                }
                head = head->next;
            }
            return ans->next;
        }
};