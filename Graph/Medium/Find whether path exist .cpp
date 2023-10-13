/*
Given a N X N matrix (M) filled with 1, 0, 2, 3. The task is to find whether there is a path possible from source to destination, while traversing through blank cells only. You can traverse up, down, right and left.

A value of cell 1 means Source.
A value of cell 2 means Destination.
A value of cell 3 means Blank cell.
A value of cell 0 means Blank Wall.
Note: there is only single source and single destination.

 

Input:
The first line of input is an integer T denoting the no of testcases. Then T test cases follow. Each test case consists of 2 lines. The first line of each test case contains an integer N denoting the size of the square matrix. Then in the next line are N*N space separated values of the matrix (M).

Output:
For each test case in a new line print 1 if the path exist from source to destination else print 0.

Constraints:
1 <= T <= 20
1 <= N <= 20

Example:
Input:
2
4
3 0 0 0 0 3 3 0 0 1 0 3 0 2 3 3 
3
0 3 2 3 0 0 1 0 0

Output:
1
0

Explanation:
Testcase 1: The matrix for the above given input is:
3 0 0 0
0 3 3 0
0 1 0 3
0 2 3 3
From the matrix we can see that there exists a path from to reach destination 2 from source 1.
Testcase 2: The matrix for the above given input is:
0 3 2
3 0 0
1 0 0
From the matrix we can see that there does not exists any path to reach destination 2 from source 1.
*/

#include <bits/stdc++.h>
using namespace std;

int dfs(int x,int y, vector<vector<int>> &arr,int n,bool & vis)
{
   
    if(x>=0 && x<n && y>=0 && y<n && (arr[x][y]==1 || arr[x][y]==2 || arr[x][y]==3))
    {
    
    
    if(arr[x][y]==2)
    vis=true;
    
     arr[x][y]=4;
    
    dfs(x-1,y, arr,n,vis);
    dfs(x+1,y, arr,n,vis);
    dfs(x,y-1, arr,n,vis);
    dfs(x,y+1, arr,n,vis);

    }
    
    return vis;
}

int main() {
	
	int t;
	cin>>t;
	
	while(t--)
	{
	int n;
	cin>>n;
	vector<vector<int>> arr(n,vector<int> (n));
	
	
	int x,y;  //to tack source pos.
	for(int i=0;i<n;i++)
	{
	  for(int j=0;j<n;j++)
	{
	    int temp;
	    cin>>temp;
	    arr[i][j]=temp;
	    if(arr[i][j]==1)
	    {
	        x=i;
	        y=j;
	    }
	    
	}  
	}
	 
	bool vis=false;//for returning true or false

	if(dfs(x,y,arr,n,vis))
	cout<<1<<endl;
	else cout<<0<<endl;

	
	}
	return 0;
}