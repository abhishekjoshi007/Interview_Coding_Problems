/*Given a linked list of size N. The task is to reverse every k nodes (where k is an input to the function) in the linked list.

Example 1:

Input:
LinkedList: 1->2->2->4->5->6->7->8
K = 4
Output: 4 2 2 1 8 7 6 5
Example 2:

Input:
LinkedList: 1->2->3->4->5
K = 3
Output: 3 2 1 5 4
Your Task:
The task is to complete the function reverse() which should reverse the linked list in group of size k and return the head of the modified linked list.

Expected Time Complexity : O(n)
Expected Auxilliary Space : O(1)
*/

struct node *reverse (struct node* head, int k)
{
	struct node* current = head;
	struct node* next = NULL;
	struct node* prev = NULL;
	int count = 0; 
	
	while (current != NULL && count < k)
	// reversing k elements :
	{
		next = current->next;             // marking next node
		current->next = prev;             // reversing link
		prev = current;                   // updating prev
		current = next;                   // updating current
		count++;
	}
	
	if (next != NULL)       // checking if there are nodes ahead
    	head->next = reverse(next, k);    // reversing those recursively
    
	return prev;            // returning new head
}