/*Given an input stream of n integers, find the kth largest element for each element in the stream.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains two lines. The first line of each test case contains two space separated integers k and n . Then in the next line are n space separated values of the array.

Output:
For each test case, in a new line, print the space separated values denoting the kth largest element at each insertion, if the kth largest element at a particular insertion in the stream doesn't exist print -1.

Constraints:
1 <= T <= 100
1 <= K <= n
1 <= n <= 106
1 <= stream[] <= 105

Example:
Input:
2
4 6
1 2 3 4 5 6
1 2
3 4

Output:
-1 -1 -1 1 2 3
3 4 

Explanation:
Testcase1:
k = 4
For 1, the 4th largest element doesn't exist so we print -1.
For 2, the 4th largest element doesn't exist so we print -1.
For 3, the 4th largest element doesn't exist so we print -1.
For 4, the 4th largest element is 1 {1, 2, 3, 4}
For 5, the 4th largest element is 2 {2, 3, 4 ,5}
for 6, the 4th largest element is 3 {3, 4, 5}
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int k,n;
	    cin>>k>>n;
	    int a[n];

        // Syntax to create a min heap for priority queue
        //priority_queue <int, vector<int>, greater<int>> g = gq;
	    priority_queue<int,vector<int>,greater<int>> q;
	    
	    for(int i=0;i<n;i++)
	    
	    {
	        
	        cin>>a[i];
	        
	       
	        if(i<k-1)
	        {
	            q.push(a[i]);
	            cout<<"-1"<<" ";
	            
	        }
	        
	        else if(i==k-1)
	        {
	        q.push(a[i]);
	        cout<<q.top()<<" ";
	        }
	        else 
	        {
	            if(a[i]>q.top())
	        {   
	            q.pop();
	            q.push(a[i]);
	           
	        }
	         cout<<q.top()<<" ";
	        }
	    }
	   
	    cout<<endl;
	    
	}
	
	return 0;
}