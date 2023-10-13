/*Given a Binary Tree, print Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as argument.

Left view of following tree is 1 2 4 8.

          1
       /     \
     2        3
   /     \    /    \
  4     5   6    7
   \
     8   

Example 1:

Input:
   1
 /  \
3    2
Output: 1 3

Example 2:

Input:

Output: 10 20 40
Your Task:
You just have to complete the function leftView() that prints the left view. The newline is automatically appended by the driver code.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <= Number of nodes <= 100
1 <= Data of a node <= 1000

*/

void leftviewutil(vector<int> &v,Node *root,int level,int *max_level) 
{
    if(root==NULL)
    return;
    
    if(level> *max_level)
    {
        v.push_back(root->data);
        *max_level=level;
        
    }
     leftviewutil(v,root->left,level+1,max_level);
     leftviewutil(v,root->right,level+1,max_level);
    
    
}
// A wrapper over leftViewUtil()
vector<int> leftView(Node *root)
{
    int max_level=0;
    vector<int> v;
    
    leftviewutil(v,root,1,&max_level) ;
    
    return v;
}
