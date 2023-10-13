/*
Given a boolean 2D matrix (0-based index), find whether there is path from (0,0) to (x,y) and if there is one path, print the minimum no of steps needed to reach it, else print -1 if the destination is not reachable. You may move in only four direction ie up, down, left and right. The path can only be created out of a cell if its value is 1.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains two lines . The first line of each test case contains two integers n and m denoting the size of the matrix. Then in the next line are n*m space separated values of the matrix. The following line after it contains two integers x and y denoting the index of the destination.

Output:
For each test case print in a new line the min no of steps needed to reach the destination.

Constraints:
1<=T<=100
1<=n,m<=20

Example:
Input:
2
3 4
1 0 0 0 1 1 0 1 0 1 1 1
2 3
3 4
1 1 1 1 0 0 0 1 0 0 0 1
0 3
Output:
5
3
*/

#include <bits/stdc++.h>
using namespace std;
 
void dfs(vector<vector<int>> &grid, int m, int n, int i, int j, int &count, int &minCount, int x, int y){
    if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==0){
        return;
    }
    if(i==x && j==y){
        minCount = min(minCount, count);
        return;
    }
    grid[i][j]=0;
    count++;
    
    dfs(grid, m, n, i+1, j, count, minCount, x, y);
    dfs(grid, m, n, i, j+1, count, minCount, x, y);
    dfs(grid, m, n, i, j-1, count, minCount, x, y);
    dfs(grid, m, n, i-1, j, count, minCount, x, y);
    grid[i][j]=1;
    count--;
}
 
int main() {
    //code
    int t, m, n, x, y;
    cin>>t;
    for(int T=0; T<t; T++){
        cin>>m>>n;
        vector<vector<int>> grid(m, vector<int>(n));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                cin>>grid[i][j];
            }
        }
        cin>>x>>y;
        int minCount = INT_MAX;
        int count=0;
        dfs(grid, m, n, 0, 0, count, minCount, x, y);
        if(minCount == INT_MAX){
            cout<<"-1"<<endl;
        }else{
            cout<<minCount<<endl;
        }
    }
    return 0;
}