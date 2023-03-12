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
        ListNode* mergeKLists(vector<ListNode*> &lists)
        {
            ListNode *head = new ListNode(-100000), *tail = head;
            int n = lists.size();
            if(n>0)
            head->next = lists[0];

            for (int i = 1; i < n; i++)
            {
                tail = head;
                ListNode *temp = head->next;
                ListNode *temp2 = lists[i];
                while (temp && temp2)
                {
                    if (temp->val < temp2->val)
                    {
                        tail->next = temp;
                        temp = temp->next;
                    }
                    else
                    {
                        tail->next = temp2;
                        temp2 = temp2->next;
                    }
                    tail = tail->next;
                }
                if (temp)
                {
                    tail->next = temp;
                }
                if (temp2)
                {
                    tail->next = temp2;
                }
                // tail->next=nullptr;
            }
            return head->next;
        }
};