/*Given two singly linked lists of size N and M, write a program to get the point where two linked lists intersect each other.

Y ShapedLinked List
Above diagram shows an example with two linked list having 15 as intersection point.

Example 1:

Input:
LinkList1 = {10,20,5,10}
LinkList2 = {30,40,50,5,10}
Output: 5
Explanation:The point of intersection of
two linked list is 5, means both of them
get linked (intersects) with each other
at node whose value is 5.
Your Task:
The task is to complete the function intersetPoint() which finds the point of intersection of two linked list. The function should return data value of a node where two linked lists merge. If linked list do not merge at any point, then it should return -1.

Challenge : Try to solve the problem without using any extra space.

Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 100
1 <= value <= 1000
*/

int intersectPoint(Node* head1, Node* head2)
{
  Node *temp = head1;
while(temp)
{
temp->data = -1 * (temp->data+1);
temp = temp->next;
}
temp = head2;
int ans = -1,p=0;
while(temp){
if(temp->data < 0){
p=1;
ans = -1*temp->data;
break;
}
temp=temp->next;
}

if(p=1)
return (ans-1);
else 
return ans;


}

