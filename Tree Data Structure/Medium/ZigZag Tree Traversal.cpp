/*https://www.geeksforgeeks.org/problems/zigzag-tree-traversal/1
Babbar
*/

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	vector <int> ans;
    	
    	//base case 
    	if(root==NULL)
    	return ans;
    	
    	queue<Node*> q;
    	q.push(root);
    	
    	//zig zag path indicator 
    	bool leftToRight=true;
    	
    	while(!q.empty())
    	{
    	    int size=q.size();
    	    vector<int> result(size);
    	    
    	    //level process
    	   for(int i=0;i<size;i++)
    	   {
    	       Node* temp=q.front();
    	       q.pop();
    	       
    	       //normal or reverse insert
    	       int index=leftToRight?i:size-i-1;
    	       
    	       result[index]=temp->data;
    	       
    	       if(temp->left)
    	       q.push(temp->left);
    	       
    	       
    	        if(temp->right)
    	       q.push(temp->right);
    	       
    	   }
    	   
    	   //chnaging direction 
    	   leftToRight=!leftToRight;
    	   
    	   for(auto i:result){
    	   ans.push_back(i);
    	   }
    	   
    	}
    	return ans;
    	   

    	
    }
};