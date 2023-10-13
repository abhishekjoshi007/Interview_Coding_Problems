/*
Given a square grid of size N, each cell of which contains integer cost which represents a cost to traverse through that cell, we need to find a path from top left cell to bottom right cell by which total cost incurred is minimum. You can move in 4 directions : up, down, left an right.

Note : It is assumed that negative cost cycles do not exist in input matrix.

Input:
The first line of input will contain number of testcases T. Then T test cases follow. Each test case contains 2 lines. The first line of each test case contains an integer N denoting the size of the grid. Next line of each test contains a single line containing N*N space separated integers depicting the cost of respective cell from (0,0) to (N,N).

Output:
For each test case output a single integer depecting the minimum cost to reach the destination.

Constraints:
1 <= T <= 100
1 <= N <= 100
1 <= grid[i][j] <= 104

Example:
Input:
2
5
31 100 65 12 18 10 13 47 157 6 100 113 174 11 33 88 124 41 20 140 99 32 111 41 20
2
42 93 7 14

Output:
327
63

Explanation:
Testcase 1:
Grid is:
31, 100, 65, 12, 18,
10, 13, 47, 157, 6,
100. 113, 174, 11, 33,
88, 124, 41, 20, 140,
99, 32, 111, 41, 20
A cost grid is given in below diagram, minimum
cost to reach bottom right from top left
is 327 (31 + 10 + 13 + 47 + 65 + 12 + 18 + 6 + 33 + 11 + 20 + 41 + 20)

using priority queue and pairs
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    
	    //creating 2 d array
        vector<vector<int >> arr(n,vector<int >(n));
        vector<vector<int >> dist(n,vector<int >(n));
        	  
	    for(int i=0;i<n;i++)
	    {
	      for(int j=0;j<n;j++)
	    {
	        cin>>arr[i][j];
	        dist[i][j]=INT_MAX;
	    }  
	    }
	    
	   dist[0][0]=arr[0][0];
	   
	  //creating min priority queue
      priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
	  pq.push(make_pair(arr[0][0],make_pair(0,0)));
	  
	  //for all four direction
	  int dx[]={-1,1,0,0};
	  int dy[]={0,0,-1,1};
	  
	  while(!pq.empty())
	  {
	      pair<int,pair<int,int>> p=pq.top();
	      pq.pop();
	      
	      int i=p.second.first;
	      int j=p.second.second;
	      
	      
	      for(int k=0;k<4;k++)
	      {
	          int x=i+dx[k];
	          int y=j+dy[k];
	          
	          if(x>=0 && x<n && y>=0 && y<n)
	          {
	              if(dist[x][y]>dist[i][j]+arr[x][y])
	              {
	                  dist[x][y]=dist[i][j]+arr[x][y];
	                  pq.push(make_pair(dist[x][y],make_pair(x,y)));
	                  
	              }
	          }
	          
	      }
	      
	  }
	  cout<<dist[n-1][n-1]<<"\n";
	    
	}
	return 0;
}
