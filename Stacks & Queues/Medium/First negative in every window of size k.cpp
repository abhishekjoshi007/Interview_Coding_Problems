

class Solution {
  public:
    vector<int> printFirstNegativeInteger(vector<int>& arr, int k) {
        //creating a deque
        deque <int> q;
        vector <int> ans;
        
        for(int i=0;i<k;i++)
        {
            if(arr[i]<0)
            {
                q.push_back(i);
            }
        }
        
        if(q.size()>0)
        {
            ans.push_back(arr[q.front()]);
        }
        else{
            ans.push_back(0);
        }
        
        
        //process remaining window
        for(int i=k;i<arr.size();i++)
        {
            //removal from deque
            if(!q.empty() && i-q.front()>=k)
            q.pop_front();
            
             if(arr[i]<0)
            {
                q.push_back(i);
            }
            
        if(q.size()>0)
        {
            ans.push_back(arr[q.front()]);
        }
        else{
            ans.push_back(0);
        }
            
 
            
        }
        return ans;
    }
};