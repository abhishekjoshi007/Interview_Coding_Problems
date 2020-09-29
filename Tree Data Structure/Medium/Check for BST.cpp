/*
Given a binary tree. Check whether it is a BST or not.

Example 1:

Input:
    2
 /    \
1      3
Output: 1
Example 2:

Input:
  2
   \
    7
     \
      6
       \
        5
         \
          9
           \
            2
             \
              6
Output: 0
Your Task:
You don't need to read input or print anything. Your task is to complete the function isBST() which takes the root of the tree as a parameter and returns true if the given binary tree is BST, else returns false. The printing is done by the driver's code.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the BST).

Constraints:
0 <= Number of edges <= 100000

Question link:https://practice.geeksforgeeks.org/problems/check-for-bst/1
*/

bool checknode(Node* root,int min,int max)
{
    if(root==NULL)
    return 1;
    
    if(root->data<min || root->data>max)
    return 0;
    
    else
    {
      //if all elements are same then max or min should be
      //root->data-1 and root->data+1
      checknode(root->left,min,root->data-1) && 
      checknode(root->right,root->data+1,max);  
    }
}

// return true if the given tree is a BST, else return false
bool isBST(Node* root) {

      return checknode(root,INT_MIN,INT_MAX);
      
}

