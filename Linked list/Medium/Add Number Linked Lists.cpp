/*
QUESTION LINK-https://www.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1
*/

class Solution {
 private:
 Node* reverse(Node* head)
 {
     Node* prev=NULL;
     Node* curr=head;
     Node* next;
     
     while(curr!=NULL)
     {
         next=curr->next;
         curr->next=prev;
         
         prev= curr;
         curr=next;
         
         
     }
     return prev;
 }
 
 void insertAtHead(Node* &head, Node* &tail, int digit)
 {
     Node* temp= new Node(digit);
     if(head==NULL)
     {
         head=temp;
         return;
     }
     else{
         temp->next=head;
         head=temp;
     }
 }
 
 Node* add(Node* first, Node* second)
 {
     int carry=0;
     Node* ansHead=NULL;
     Node* ansTail=NULL;
     
     //halding cases where we have both elements
     while(first!=NULL || second!=NULL || carry!=0)
     {
         int val1=0;
         if(first!=NULL)
         {
             val1=first->data;
             
         }
         
         int val2=0;
         if(second!=NULL)
         {
             val2=second->data;
             
         }
         
         int sum= carry+val1+val2;
         int digit=sum%10;
         
        //creating node and adding at answer Ll
        insertAtHead(ansHead, ansTail, digit);
        
        carry=sum/10;
        
        if(first!=NULL)
        first=first->next;
        
        if(second!=NULL)
        second=second->next;
     }
    return ansHead;
     
     
 }
 
  public:
    // Function to add two numbers represented by linked list.
    Node* addTwoLists(Node* num1, Node* num2) {
        //reverse LL
        num1=reverse(num1);
        num2=reverse(num2);
        
        Node* ans = add(num1,num2);
        
        
    }
};