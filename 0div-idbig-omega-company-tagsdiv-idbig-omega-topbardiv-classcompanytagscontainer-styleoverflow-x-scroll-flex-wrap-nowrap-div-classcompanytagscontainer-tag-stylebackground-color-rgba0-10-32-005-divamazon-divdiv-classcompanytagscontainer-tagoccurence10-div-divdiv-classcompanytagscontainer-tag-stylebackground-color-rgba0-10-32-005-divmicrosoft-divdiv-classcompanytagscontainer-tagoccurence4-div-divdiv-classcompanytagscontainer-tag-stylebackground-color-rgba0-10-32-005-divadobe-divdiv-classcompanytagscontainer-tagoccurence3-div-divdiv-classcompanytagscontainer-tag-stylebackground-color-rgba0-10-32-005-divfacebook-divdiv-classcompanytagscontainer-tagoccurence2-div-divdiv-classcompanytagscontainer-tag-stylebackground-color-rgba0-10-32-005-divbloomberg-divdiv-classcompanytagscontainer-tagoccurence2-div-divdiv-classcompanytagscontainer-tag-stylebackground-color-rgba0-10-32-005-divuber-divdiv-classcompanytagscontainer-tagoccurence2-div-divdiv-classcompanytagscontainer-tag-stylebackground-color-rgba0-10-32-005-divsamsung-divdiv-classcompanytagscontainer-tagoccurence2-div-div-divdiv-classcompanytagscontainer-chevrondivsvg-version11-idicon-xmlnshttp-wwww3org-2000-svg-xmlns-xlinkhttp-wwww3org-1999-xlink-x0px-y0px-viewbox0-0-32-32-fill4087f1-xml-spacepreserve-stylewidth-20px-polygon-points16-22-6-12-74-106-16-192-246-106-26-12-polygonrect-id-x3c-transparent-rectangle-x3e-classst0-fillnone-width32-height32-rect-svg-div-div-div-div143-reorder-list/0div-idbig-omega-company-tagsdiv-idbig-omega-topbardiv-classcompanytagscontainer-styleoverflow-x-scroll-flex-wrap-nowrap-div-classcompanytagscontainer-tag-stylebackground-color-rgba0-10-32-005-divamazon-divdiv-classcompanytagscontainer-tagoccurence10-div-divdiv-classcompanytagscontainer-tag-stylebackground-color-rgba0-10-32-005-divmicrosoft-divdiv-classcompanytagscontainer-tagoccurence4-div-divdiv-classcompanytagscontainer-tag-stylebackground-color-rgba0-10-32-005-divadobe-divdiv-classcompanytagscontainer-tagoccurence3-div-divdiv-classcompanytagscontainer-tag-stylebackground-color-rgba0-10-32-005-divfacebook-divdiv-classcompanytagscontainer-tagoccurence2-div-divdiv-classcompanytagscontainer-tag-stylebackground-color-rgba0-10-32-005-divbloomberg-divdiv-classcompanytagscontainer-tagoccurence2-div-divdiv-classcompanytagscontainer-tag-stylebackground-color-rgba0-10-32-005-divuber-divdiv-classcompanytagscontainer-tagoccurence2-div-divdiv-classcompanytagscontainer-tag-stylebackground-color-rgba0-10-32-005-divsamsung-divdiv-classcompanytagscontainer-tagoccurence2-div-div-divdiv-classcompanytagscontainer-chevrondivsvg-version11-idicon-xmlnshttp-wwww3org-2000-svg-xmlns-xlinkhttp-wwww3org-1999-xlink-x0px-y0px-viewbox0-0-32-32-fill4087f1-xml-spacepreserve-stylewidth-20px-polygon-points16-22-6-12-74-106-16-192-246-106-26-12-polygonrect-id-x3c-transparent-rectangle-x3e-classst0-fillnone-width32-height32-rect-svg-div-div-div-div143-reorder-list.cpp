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
    void reorderList(ListNode* head) {
       map<int,ListNode*> mp;
        ListNode* temp=head;
        int i=0;
        while(temp)
        {
            mp[i++]=temp;
            ListNode* t2=temp;
            temp=temp->next;
            t2->next=nullptr;
        }
        int n=i;
        i=0;
        
        ListNode* tail=head;
        tail->next=mp[n-1];
        tail=tail->next;
        // cout<<"n "<<n<<endl;
//         for(auto x:mp)
//         {
//             cout<<x.first<<' '<<x.second->val<<endl;
            
//         }
        for(int i=1;i<n/2;i++)
        {
            
            // cout<<"here"<<endl;
            tail->next=mp[i];
            // cout<<tail->val<<endl;
            tail=tail->next;
            // cout<<tail->val<<endl;

            tail->next=mp[n-i-1];
            tail=tail->next;
                                    // cout<<tail->val<<endl;

        }
        if(n%2)
        {
            tail->next=mp[(n)/2];
            tail=tail->next;
        }
        tail->next=nullptr;
        
    }
};