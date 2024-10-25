/*https://www.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1*/

class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        stack <int> s;
        
        //removala and put in stack 
        
        for(int i=0;i<k;i++)
        {
            int temp=q.front();
            q.pop();
            s.push(temp);
        }
        
        //remove from stack and push in queue
        for(int i=0;i<k;i++)
        {
            int temp=s.top();
            s.pop();
            q.push(temp);
        }
        
        
        int x=q.size()-k;
        
        for(int i=0;i<x;i++)
        {
            int temp=q.front();
            q.pop();
            q.push(temp);
        }
        
        return q;
        
    }
};
