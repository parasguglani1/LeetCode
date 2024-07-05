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
        vector<int> nodesBetweenCriticalPoints(ListNode *head)
        {
            vector<int> ans;
            int mn = INT_MAX, mx = INT_MIN;
            int prevVal = head->val;
            head = head->next;
            int lastcriticalpnt = -1;
            int dis = 0;
            int i = 1;
            int firstcriticalpnt=-1;
            while (head->next)
            {
                int next = head->next->val;
                int cur = head->val;
                if ((cur > prevVal && cur > next)|| (cur<prevVal &&cur<next))
                {
                    if (lastcriticalpnt != -1)
                    {
                        dis = i - lastcriticalpnt;
                        mn = min(dis, mn);
                       
                    }
                    lastcriticalpnt = i;
                    if(firstcriticalpnt==-1)
                    {
                        firstcriticalpnt=i;
                    }
                }
                prevVal=cur;
                i++;
                head=head->next;
            }
            
            if(mn==INT_MAX)
            {
                return {-1,-1};
            }
            return {mn,lastcriticalpnt-firstcriticalpnt};
        }
};