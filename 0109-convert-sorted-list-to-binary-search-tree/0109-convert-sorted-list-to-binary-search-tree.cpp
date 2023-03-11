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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    TreeNode* buildTree(int st,int end,vector<int> v)
    {
        if(st>end)
        {
            return nullptr;
        }
        int mid=(st+end)/2;
        TreeNode* root=new TreeNode(v[mid]);
        root->left=buildTree(st,mid-1,v);
        root->right=buildTree(mid+1,end,v);
        return root;
        
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> v;
        auto temp=head;
        while(temp)
        {
            v.push_back(temp->val);
            temp=temp->next;
        }
        int n=v.size();
        return buildTree(0,n-1,v);
        
    }
};