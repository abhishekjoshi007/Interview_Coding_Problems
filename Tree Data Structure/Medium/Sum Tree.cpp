/*babbar 
https://www.geeksforgeeks.org/problems/sum-tree/1*/

class Solution {
  public:
   pair <bool,int> sumTreefast(Node* root)
   {   
       //base case 
       if(root==NULL)
       {
          pair <bool,int> p=make_pair(true,0);
          
          return p;
       }
       
       //checking for leaf node
       if(root->left==NULL && root->right==NULL)
       {
           pair <bool,int> p=make_pair(true,root->data);
           return p;
       }
       
        pair <bool,int> leftAns= sumTreefast(root->left);
        pair <bool,int> rightAns= sumTreefast(root->right);
        
        int left=leftAns.first;
        int right=rightAns.first;
        
        bool cond= root->data==(leftAns.second+ rightAns.second);
        
        pair <bool,int> ans;
        
        if(left && right && cond)
        {
            ans.first=true;
            ans.second=2*root->data;
        }
        else{
             ans.first=false;
        }
        
        return ans;
        
        
       
   }
    bool isSumTree(Node* root) {
        return sumTreefast(root).first;
    }
};