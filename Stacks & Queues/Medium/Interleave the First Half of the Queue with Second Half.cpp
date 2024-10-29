
class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        int n=q.size();
        //extra queue
        queue<int> x;
        
        for(int i=0;i<n/2;i++)
        {
            x.push(q.front());
            q.pop();
        }
        
        vector<int> ans;
        
        while(!x.empty())
        {
            ans.push_back(x.front());
            x.pop();
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};