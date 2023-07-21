class Node
{
    public:
        int val;
    Node * next;

    Node(int val)
    {
        this->val = val;
        this->next = nullptr;
    }
};
class MyLinkedList
{
    public:
    Node *head= NULL, *tail=NULL;
    int size = 0;
    MyLinkedList()
    {
       
    }

    int get(int index)
    {
        if (index >= size)
        {
            return -1;
        }
        else
        {
            Node *temp = head;
            for (int i = 0; i < index ; i++)
            {
                temp = temp->next;
            }
            return temp->val;
        }
    }

    void addAtHead(int val)
    {

        Node *newnode = new Node(val);
        if (size==0)
        {
            tail = newnode;
        }
            newnode->next = head;
            head = newnode;
            size++;

    }

    void addAtTail(int val)
    {       

        if (size==0)
        {
            addAtHead(val);
return;
             }
                size++;

 Node *newnode = new Node(val);
       
            tail->next = newnode;
            tail = tail->next;
        }

    void addAtIndex(int index, int val)
    {
        if(index==0)
        {
            addAtHead(val);
        }
        else if (index == size)
        {
            addAtTail(val);
        }
        else if(index<size)
        {
            size++;
             Node *temp = head;
            for (int i = 0; i < index-1; i++)
            {
                temp = temp->next;
            }
            Node* newnode=new Node(val);
            newnode->next=temp->next;
            temp->next=newnode;
            
        }
    }

    void deleteAtIndex(int index) {
  
        if(index>=size)
        {
            return;
        
        }

   
      
        
        if(index==size-1)
        {
        if (index==0 )
        {
            head=nullptr;
            tail=nullptr;
        }
          else  
        {    tail=nullptr;
            Node*temp2=head;
            while(temp2&& temp2->next)
            {
                tail=temp2;
                temp2=temp2->next;
            }
            tail->next=nullptr;
            }
        }
        else  if(index==0)
        {
            head=head->next;
        }
        else
        {
            int i=0;
            Node*temp2=head;
            while(i<index-1)
            {
                temp2=temp2->next;
                i++;
            }
            temp2->next=temp2->next->next;
            
        }
                         size--;

        
        
    }
};

/**
 *Your MyLinkedList object will be instantiated and called as such:
 *MyLinkedList* obj = new MyLinkedList();
 *int param_1 = obj->get(index);
 *obj->addAtHead(val);
 *obj->addAtTail(val);
 *obj->addAtIndex(index,val);
 *obj->deleteAtIndex(index);
 */