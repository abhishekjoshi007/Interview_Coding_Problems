/*https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1*/

class Solution {
  public:
    vector <int> bottomView(Node *root) {
         //map for HD and nodes
       map<int , int> topNode;
       //answer 
       vector<int> ans;
       if(root==NULL)
       return ans;
       
       //queue for traversal 
       queue<pair<Node*, int>> q;
       
       q.push(make_pair(root,0));
       
       while(!q.empty())
       {
           pair<Node*,int> temp=q.front();
           q.pop();
           
           Node* front=temp.first;
           int hd=temp.second;
           
            //just replace element so that we get the bottom element view 
            
                topNode[hd] = front->data;
            
           
           if(front->left)
           q.push(make_pair(front->left,hd-1));
           
           if(front->right)
           q.push(make_pair(front->right,hd+1));
           
       }
       
       for(auto i:topNode)
       {
           
               ans.push_back(i.second);
           
       }
       return ans;
    
    }
};