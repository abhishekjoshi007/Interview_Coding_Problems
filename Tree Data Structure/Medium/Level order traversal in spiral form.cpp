/*Complete the function to find spiral order traversal of a tree. For below tree, function should return 1, 2, 3, 4, 5, 6, 7.

Example 1:

Input:
      1
    /   \
   3     2
Output:1 3 2

Example 2:

Input:
           10
         /     \
        20     30
      /    \
    40     60
Output: 10 20 30 60 40 
Your Task:
The task is to complete the function findSpiral() which returns the elements in spiral form of level order traversal as a list. The newline is automatically appended by the driver code.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
0 <= Number of nodes <= 105
1 <= Data of a node <= 105
*/

vector<int> findSpiral(Node *root)
{
   vector<int> arr;
queue<Node*> q;
q.push(root);
int i=1;
while(!q.empty())
{
int size = q.size();
int flag = arr.size();
while(size--)
{
if(q.front())
{
arr.push_back(q.front()->data);
if(q.front()->left) 
q.push(q.front()->left);

if(q.front()->right) 
q.push(q.front()->right);
}

q.pop();
}
if(i%2!=0)
{
reverse(arr.begin()+flag,arr.end());
}
i++;

}
return arr;
}