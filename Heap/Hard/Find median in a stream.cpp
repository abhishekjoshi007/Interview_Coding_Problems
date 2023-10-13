/*Given an input stream of N integers. The task is to insert these numbers into a new stream and find the median of the stream formed by each insertion of X to the new stream.

Input:
The first line of input contains an integer N denoting the number of elements in the stream. Then the next N lines contains integer x denoting the number to be inserted into the stream.
Output:
For each element added to the stream print the floor of the new median in a new line.
 
Constraints:
1 <= N <= 106
1 <= x <= 106
 
Example:
Input:
4
5
15
1 
3
Output:
5
10
5
4
 
Explanation:
Testcase 1:
Flow in stream : 5, 15, 1, 3
5 goes to stream --> median 5 (5)
15 goes to stream --> median 10 (5, 15)
1 goes to stream --> median 5 (5, 15, 1)
3 goes to stream --> median 4 (5, 15, 1, 3)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	int d;
	cin>>d;
	int med=d;
	cout<<d<<endl;
	n--;
	//max heap 
	priority_queue<int> max;
	//min heap
	priority_queue<int,vector<int>,greater<int>> min;
    
    max.push(d);
    
    while(n>0)
    {
        cin>>d;
        
        if(max.size()>min.size())
        {
            if(d<med)
            {
                int temp=max.top();
                max.pop();
                min.push(temp);
                max.push(d);
            }
            else
            min.push(d);
            
            med=(max.top()+min.top())/2;
            
        }
        
        else if(max.size()==min.size())
        {
            
            if(d<med)
            {
            max.push(d);
            med=max.top();
            }
            else
            {
                min.push(d);
                med=min.top();
            }
            
            
        }
        else
        {
            if(d>med)
            {
                int temp=min.top();
                min.pop();
                max.push(temp);
                min.push(d);
            }
            else 
            max.push(d);
            
            med=(min.top()+max.top())/2;
            
        }
        cout<<med<<endl;
        n--;
        
        
    }
	
	return 0;
}