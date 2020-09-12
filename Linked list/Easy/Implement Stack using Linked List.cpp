/* Let give it a try! You have a linked list and you have to implement the functionalities push and pop of stack using this given linked list. Your task is to use the class as shown in the comments in the code editor and complete the functions push() and pop() to implement a stack. 

Example 1:

Input: 
push(2)
push(3)
pop()
push(4) 
pop()
Output: 3, 4
Explanation: 
push(2)    the stack will be {2}
push(3)    the stack will be {2 3}
pop()      poped element will be 3,
           the stack will be {2}
push(4)    the stack will be {2 4}
pop()      poped element will be 4
Example 2:

Input: 
pop()
push(4)
push(5)
pop()
Output: -1, 5
Your Task: You are required to complete two methods push() and pop(). The push() method takes one argument, an integer 'x' to be pushed into the stack and pop() which returns an integer present at the top and popped out from the stack. If the stack is empty then return -1 from the pop() method.

Expected Time Complexity: O(1) for both push() and pop().
Expected Auxiliary Space: O(1) for both push() and pop().

Constraints:
1 <= Q <= 100
1 <= x <= 100

Question link:https://practice.geeksforgeeks.org/problems/implement-stack-using-linked-list/1
*/

/* The method push to push element
   into the stack */
void MyStack ::push(int x) {
    StackNode*newnode=new StackNode( x);
    
    if(top==NULL)
    {
    top=newnode;
  
    }
    else
    {
    newnode->next=top;
    top=newnode;
    }
}

/* The method pop which return the element
  poped out of the stack*/
int MyStack ::pop() {
    int x;
    if(top==NULL)
    return -1;
    else
    {
         x=top->data;
        top=top->next;
    }
    return x;
}
