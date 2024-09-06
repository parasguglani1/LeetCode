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
        ListNode* modifiedList(vector<int> &nums, ListNode *head)
        {
            ListNode *ans = new ListNode(0);

            map<int, int> mp;
            ListNode *tail = ans;
            for (auto x: nums)
            {
                mp[x]++;
            }

            while (head)
            {
                if (mp[head->val] == 0)
                {
                    tail->next = head;
                    tail = tail->next;
                }
                head = head->next;
            }
            tail->next = nullptr;
            return ans->next;
        }
};