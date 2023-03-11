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

        ListNode* swapNodes(ListNode *head, int k)
        {

            ListNode *node1 = NULL, *node2 = NULL;
            for (auto temp = head; temp != NULL; temp = temp->next)
            {
                if (node2) node2 = node2->next;

                if (!--k)
                {
                    node1 = temp;
                    node2 = head;
                }
            }
            swap(*node1, *node2);
            swap(node1->next, node2->next);
            return head;
        }
};