/*https://geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1*/

vector<int> diagonal(Node *root)
{
    vector<int> ans;
    queue<Node*> q;
    
    //base cond
    if(root==NULL)
    return ans;
    
    q.push(root);
    
    while(!q.empty())
    {
        Node* temp=q.front();
        q.pop();
        
        while(temp)
        {
            if(temp->left)
            q.push(temp->left);
            
            ans.push_back(temp->data);
            temp=temp->right;
            
            
        }
    }
    return ans;
}