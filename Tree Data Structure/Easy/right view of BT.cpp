/*https://www.geeksforgeeks.org/problems/right-view-of-binary-tree/1*/

class Solution
{
    public:
      void solve(Node* root,vector<int> &ans, int lvl)
   {
       if(root==NULL)
       return;
       
       if(lvl==ans.size())
       ans.push_back(root->data);
       
       solve(root->right,ans,lvl+1);
       solve(root->left,ans,lvl+1);
       
       
       
   }
    vector<int> rightView(Node *root)
    {
       vector<int> ans;
        int lvl=0;
        solve(root,ans, lvl);
        return ans;
    }
};