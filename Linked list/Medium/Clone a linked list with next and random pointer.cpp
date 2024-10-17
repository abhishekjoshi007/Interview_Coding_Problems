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