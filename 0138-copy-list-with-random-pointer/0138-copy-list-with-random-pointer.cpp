/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
    Node* newhead=head;
    map<Node*,Node*>mp;
        while(newhead)
        {
            Node *newnode= new Node(newhead->val);
            mp[newhead]=newnode;
            newhead=newhead->next;
        }
        newhead=head;
        while(newhead)
        {
        mp[newhead]->next=mp[newhead->next];
        mp[newhead]->random=mp[newhead->random];
        newhead=newhead->next;

        }
        return mp[head];
    }
};