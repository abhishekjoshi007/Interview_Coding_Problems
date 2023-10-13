/*Given two numbers represented by two linked lists of size N and M. The task is to return a sum list. The sum list is a linked list representation of the addition of two input numbers.

Example 1:

Input:
N = 2
valueN[] = {4,5}
M = 3
valueM[] = {3,4,5}
Output: 3 9 0  
Explanation: For the given two linked
list (4 5) and (3 4 5), after adding
the two linked list resultant linked
list will be (3 9 0).
Example 2:

Input:
N = 2
valueN[] = {6,3}
M = 1
valueM[] = {7}
Output: 7 0
Explanation: For the given two linked
list (6 3) and (7), after adding the
two linked list resultant linked list
will be (7 0).
Your Task:
The task is to complete the function addTwoLists() which has node reference of both the linked lists and returns the head of the new list.

Expected Time Complexity: O(N) + O(M)
Expected Auxiliary Space: O(N) + O(M)

Constraints:
1 <= N, M <= 5000

QUESTION LINK-https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1
*/

Node*reverse(Node*head)
{
    Node*curr=head;
    Node*next=NULL;
    Node*prev=NULL;
    
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        
    }
    
    return prev;
    
    
}
void addFront(Node *&head, Node *&last, int data){
   
   Node *newNode=new Node(data);
//   newNode->data=data;
   newNode->next=NULL;
   
   if(last==NULL){
       head=newNode;
   }
   else
   {
      newNode->next=head;
      head=newNode;
   }
   last=newNode;
   
}

struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    //for first ll
    Node*head1=reverse(first);
    //for socund ll
    Node*head2=reverse(second);
    //for new ll
    Node*res;
    //for last node of new ll
    Node*last=NULL;
    
    int total,carry=0;
 // One of them not NULL
  while(head1|| head2){
      
      int a=(head1!=NULL)?(head1->data):(0); // If NULL contri is 0
      int b=(head2!=NULL)?(head2->data):(0);
      
      total=a+b+carry;
      carry=total/10;
      total=total%10;
      
      // Add this to front of new list
      addFront(res,last,total);
      
      if(head1){
          head1=head1->next;
      }
      
      if(head2){
           head2=head2->next;
      }
  }
  if(carry!=0){
      addFront(res,last,carry);
  }
 
  return res;
}
