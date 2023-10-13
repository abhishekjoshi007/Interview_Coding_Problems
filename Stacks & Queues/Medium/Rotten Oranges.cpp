/*
Given a matrix of dimension r*c where each cell in the matrix can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges

So, we have to determine what is the minimum time required to rot all oranges. A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. If it is impossible to rot every orange then simply return -1.

Input:
The first line of input contains an integer T denoting the number of test cases. Each test case contains two integers r and c, where r is the number of rows and c is the number of columns in the array a[]. Next line contains space separated r*c elements each in the array a[].

Output:
Print an integer which denotes the minimum time taken to rot all the oranges (-1 if it is impossible).

Constraints:
1 <= T <= 100
1 <= r <= 100
1 <= c <= 100
0 <= a[i] <= 2

Example:
Input:
2
3 5
2 1 0 2 1 1 0 1 2 1 1 0 0 2 1
3 5
2 1 0 2 1 0 0 1 2 1 1 0 0 2 1

Output:
2
-1
*/

#include <bits/stdc++.h>
using namespace std;
#define R 100
#define C 100

int Rotten_o(int mat[R][C], int r, int c)
{
    
    //for time counting
   int timer = -1;
    
    queue<pair<int, int>> qt;
    //checking for rotten oranges and pushing in queue
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(mat[i][j] == 2)
            {
                qt.push({i, j});
                mat[i][j] = 3;
            }
        }
    }
	    
	   while(!qt.empty() )
    {
        int count = qt.size();
        
        for(int k = 0; k < count; k++)
        {
           
            int i = qt.front().first;
            int j = qt.front().second;
            
            if(j+1 < c && mat[i][j+1] == 1)
            {
                qt.push({i, j+1});
                mat[i][j+1] = 3;
            }
            
            if(i+1 < r && mat[i+1][j] == 1)
            {
                qt.push({i+1, j});
                mat[i+1][j] = 3;
            }
            
            if(j-1 >= 0 && mat[i][j-1] == 1)
            {
                qt.push({i, j-1});
                mat[i][j-1] = 3;
            }
            
            if(i-1 >= 0 && mat[i-1][j] == 1)
            {
                qt.push({i-1, j});
                mat[i-1][j] = 3;
            }
            
            qt.pop();
        }
        
        timer++;
    }
	     
	for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(mat[i][j] == 1)
            {
                return -1;
            }
        }
    }
    
    return timer;
    
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int r,c;
	    cin>>r>>c;
	    //important
	    int arr[R][C];
	    for(int i=0;i<r;i++)
	    {
	     for(int j=0;j<c;j++)
	    {
	        cin>>arr[i][j];
	    }   
	    }
	   //Rotten Function
	  cout<<Rotten_o(arr,r,c)<<endl;
	}
	return 0;
}