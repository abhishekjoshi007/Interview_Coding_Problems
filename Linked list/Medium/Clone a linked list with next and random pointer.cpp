/*https://www.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1*/
class Solution {
  private:
  void insertAtTail(Node* &head, Node* &tail, int data){
      Node* newNode= new Node(data);
      if(head==NULL)
      {
         head=newNode;
         tail=newNode;
         return;
         
      }
      else{
          tail->next=newNode;
          tail=newNode;
      }
  }
  public:
    Node *copyList(Node *head) {
        // create a cloned list 
        Node* cloneHead= NULL;
        Node* cloneTail= NULL;
        
        Node* temp=head;
        
        while(temp!=NULL)
        {
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp=temp->next;
        }
        
        //creating a mapping 
        unordered_map<Node*, Node*>oldToNew;
        Node* originalNode=head;
        Node* cloneNode=cloneHead;
        
        while(originalNode!= NULL)
        {
          oldToNew[originalNode]= cloneNode;
          originalNode= originalNode->next;
          cloneNode=cloneNode->next;
        }
        
        //for Random Pointers 
        originalNode=head;
        cloneNode=cloneHead;
        while(originalNode!= NULL)
        {
          cloneNode->random=oldToNew[originalNode->random];
          originalNode=originalNode->next;
          cloneNode=cloneNode->next;
          
         
        }
        return cloneHead;
    }
};


//approch 2 using hashing 

class Solution {
     private:
    void insertAtTail(Node* &head, Node* &tail, int d) {
        Node* newNode = new Node(d);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail -> next = newNode;
            tail = newNode;
        }
    }
    

    public:
    Node *copyList(Node *head)
    {
        //step 1: Create a Clone List
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        Node* temp = head;
        while(temp != NULL) {
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp -> next;
        }
        
        // step 2: insert nodes of Clone List in between originalList
        
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        
        while(originalNode != NULL && cloneNode != NULL) {
            Node* next = originalNode -> next;
            originalNode -> next = cloneNode;
            originalNode = next;
            
            next = cloneNode -> next;
            cloneNode -> next = originalNode;
            cloneNode  = next;
        }
        
        // step 3: Random pointer copy
        originalNode = head;
        cloneNode = cloneHead;
        
        while(originalNode != NULL && cloneNode != NULL) { 
            
            if(originalNode -> random != NULL) {
                cloneNode -> random = originalNode -> random -> next;
            }
            else
            {
                cloneNode -> random  = NULL;
            }
            
            cloneNode = cloneNode -> next;
            originalNode = originalNode -> next;
        }
        
        //step 4: revert step 2 changes
        Node* original = head;
        Node* copy = cloneHead;
        
         while (original && copy)
            {
                original->next =
                 original->next? original->next->next : original->next;
         
                copy->next = copy->next?copy->next->next:copy->next;
                original = original->next;
                copy = copy->next;
            }

        // step 5 answer return
        return cloneHead;
    }
};