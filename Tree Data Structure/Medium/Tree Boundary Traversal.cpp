/*Babbar
https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1*/

class Solution {
public:
    void leftTraverse(Node* root, vector<int> &ans)
    {
        //base case if root is null or leaf node is reached
        if(root==NULL || (root->left==NULL && root->right==NULL))
        return;
        
        ans.push_back(root->data);
        
        if(root->left)
        leftTraverse(root->left, ans);
        
        else
        leftTraverse(root->right,ans);
    }
    
    void traverseLeaf(Node* root,vector<int> &ans)
    {
        //base case if root is null or leaf node is reached
        if(root==NULL)
        {
            return;
            
        }
        if(root->left==NULL && root->right==NULL)
        {
           ans.push_back(root->data);
           return;
        }
        
      
        traverseLeaf(root->left, ans);
        traverseLeaf(root->right,ans);
    }
    
    void rightTraverse(Node* root,vector<int> &ans)
    {
        //base case if root is null or leaf node is reached
        if(root==NULL || (root->left==NULL && root->right==NULL))
        return;
        
        if(root->right)
        rightTraverse(root->right,ans);
        
        else
        rightTraverse(root->left, ans);
        
        ans.push_back(root->data);
    }
    
    vector <int> boundary(Node *root)
    {
        //ans store
        vector<int> ans;
        
        if(root==NULL)
        return ans;
        
        ans.push_back(root->data);
        
        //left subtree traverse
        leftTraverse(root->left,ans);
        
        //leaf Nodes
        //left subtree
        traverseLeaf(root->left,ans);
        //rigth subtree
        traverseLeaf(root->right,ans);
        
        //rightsubtree traverse
        rightTraverse(root->right,ans);
        
        return ans;
        
    }
};