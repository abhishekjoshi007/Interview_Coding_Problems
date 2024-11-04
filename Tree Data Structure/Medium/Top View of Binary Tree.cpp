/*babbar
https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1
*/

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
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
           
            // Only store the first node at each horizontal distance
            /*This line checks if the key hd is already in topNode.
            If topNode.find(hd) == topNode.end() is true, it means hd is not present in topNode, 
            so we insert front->data at that key.(.end ) represent a position not in map.
            This ensures that only the first occurrence of each horizontal distance (hd) is stored in 
            topNode, as you desired.*/
            if (topNode.find(hd) == topNode.end()) {
                topNode[hd] = front->data;
            }
           
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