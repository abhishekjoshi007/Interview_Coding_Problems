/*Given a linked list of N nodes. The task is to reverse this list.

Example 1:

Input:
LinkedList: 1->2->3->4->5->6
Output: 6 5 4 3 2 1
Explanation: After reversing the list, 
elements are 6->5->4->3->2->1.
Example 2:

Input:
LinkedList: 2->7->8->9->10
Output: 10 9 8 7 2
Explanation: After reversing the list,
elements are 10->9->8->7->2.
Your Task:
The task is to complete the function reverseList() with head reference as the only argument and should return new head after reversing the list.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 104*/
// Should reverse list and return new head.

struct Node* reverseList(struct Node *head)
{
    if(head==NULL)
    return NULL;
    
    struct Node* curr=head;
    struct Node* next=NULL;
    struct Node* prev=NULL;
    
    while(curr!=NULL)
    {   
        // Before changing next of current,store next node
        next=curr->next;
        // Now change next of current
        // This is where actual reversing happens
        curr->next=prev;
        // Move prev and curr one step forward
        prev=curr;
        curr=next;
    }
    
    return prev;
}


//with class implementation

//Iterative way 
Node* reverse(node* &head)
{
node* prevptr=NULL;
node* currptr=head;
node* nextptr;

while(currptr!=NULL)
{
nextptr=currptr->next;
currptr->next=prevptr;

preptr=currptr;
currptr=nextptr;
}
return prevptr;
}