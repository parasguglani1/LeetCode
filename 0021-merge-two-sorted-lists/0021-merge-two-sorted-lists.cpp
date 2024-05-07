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
        ListNode* mergeTwoLists(ListNode *list1, ListNode *list2)
        {
            if (!list1) return list2;
            if (!list2) return list1;

            ListNode *head = nullptr;
            ListNode *curr = nullptr;
            ListNode *curr1 = list1;
            ListNode *curr2 = list2;

            if (curr1->val <= curr2->val)
            {
                curr = curr1;
                curr1 = curr1->next;
            }
            else
            {
                curr = curr2;
                curr2 = curr2->next;
            }
            head=curr;

            while (curr1 && curr2)
            {
                if (curr1->val <= curr2->val)
                {
                    curr->next = curr1;
                    curr1 = curr1->next;
                }
                else
                {
                    curr->next = curr2;
                    curr2 = curr2->next;
                }
                curr = curr->next;
            }

            curr->next = curr1 ? curr1 : curr2;

            return head;
        }
};