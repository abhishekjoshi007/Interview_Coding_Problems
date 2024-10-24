/*https://www.geeksforgeeks.org/problems/queue-reversal/1*/

//Function to reverse the queue.
class Solution
{
    public:
    void solve(queue<int>& q){
        if(q.empty()) 
        return;
        
        int f = q.front();
        q.pop();
        solve(q);
        q.push(f);
    }
    
    queue<int> rev(queue<int> q)
    {
        solve(q);
        return q;
    }
};