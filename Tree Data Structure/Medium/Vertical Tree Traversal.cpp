/*babar
https://www.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1*/

class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        //creating a map with HD, level and list of nodes
        map<int ,map<int,vector<int>>> nodes;
        //Use a queue to facilitate a level order traversal (BFS). Each entry in the queue should 
        //store a node along with its horizontal distance and level.
        queue<pair<Node*,pair<int ,int>>> q;
        //answer 
        vector<int> ans;
        
        //base cond
        if(root==NULL)
        return ans;
        
        q.push(make_pair(root,make_pair(0,0)));
        
        while(!q.empty())
        {
            //temp pair
            pair<Node*, pair<int,int>> temp=q.front();
            q.pop();
            
            Node* front=temp.first;
            int hd=temp.second.first;
            int lvl=temp.second.second;
            
            //this thing will handle sorted order with respect to hd and level will handle sorted order for nodes
            nodes[hd][lvl].push_back(front->data);
            
            if(front->left)
            {
                q.push(make_pair(front->left,make_pair(hd-1,lvl+1)));
            }
             if(front->right)
            {
                q.push(make_pair(front->right,make_pair(hd+1,lvl+1)));
            }
        }
        
        for(auto i:nodes)
        {
            for(auto j:i.second)
            {
                for(auto k:j.second)
                {
                    ans.push_back(k);
                }
            }
        }
        return ans;
        
    }
};
