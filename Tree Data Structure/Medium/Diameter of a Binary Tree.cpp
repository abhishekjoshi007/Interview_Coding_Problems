/*https://www.geeksforgeeks.org/problems/diameter-of-binary-tree/1*/


class Solution {
  public:
  pair<int, int> dimeterFast(Node* root)
  {
      if(root==NULL)
      {
       pair<int, int > p=make_pair(0,0);
       return p;
      }
       
       pair<int, int> left=dimeterFast(root->left);
       pair<int, int> right=dimeterFast(root->right);
       
       int op1=left.first;
       int op2=right.first;
       int op3=left.second+right.second+1;
       
       pair<int, int> ans;
       
       ans.first=max(op1,max(op2,op3));
       ans.second=max(left.second,right.second)+1;
       
       return ans;
       
       
  }
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
       return dimeterFast(root).first;
    }
};