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

class Solution
{
    public:
        Node* copyRandomList(Node *head)
        {
            Node *temp = head;
           	//step 1 make only the next nodes and insert in between
            while (temp != NULL)
            {
                Node *newNode = new Node(temp->val);
                newNode->next = temp->next;
                temp->next = newNode;
                temp = temp->next->next;
            }
           	//step 2 assign random pointers of our nodes
            Node *itr = head;
            while (itr != NULL)
            {
                if (itr->random != NULL)
                    itr->next->random = itr->random->next;
                itr = itr->next->next;
            }
           	//step 3 seperate the two lists
            Node *dummy = new Node(0);
            itr = head;
            temp = dummy;
            Node * fast;
            while (itr != NULL)
            {
                fast = itr->next->next;
                temp->next = itr->next;
                itr->next = fast;
                temp = temp->next;
                itr = fast;
            }
            return dummy->next;
        }
};