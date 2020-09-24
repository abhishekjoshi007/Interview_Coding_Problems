/*The problem is to count all the possible paths from top left to bottom right of a MxN matrix with the constraints that from each cell you can either move to right or down.

Input:
The first line of input contains an integer T, denoting the number of test cases. The first line of each test case is M and N, M is number of rows and N is number of columns.

Output:
For each test case, print the number of paths.

Constraints:
1 ≤ T ≤ 30
1 ≤ M,N ≤ 10

Example:
Input
2
3 3
2 8

Output
6
8

Explanation:
Testcase 1: Let the given input 3*3 matrix is filled as such:
A B C
D E F
G H I
The possible paths which exists to reach 'I' from 'A' following above conditions are as follows:
ABCFI, ABEHI, ADGHI, ADEFI, ADEHI, ABEFI.

Question link: https://practice.geeksforgeeks.org/problems/number-of-paths/0
*/

#include<bits/stdc++.h>
using namespace std;
main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int r,c;
        cin>>r>>c;
        int dp[r][c];
        for(int i=0;i<c;i++)
        {
            dp[0][i]=1;
        }
        for(int i=0;i<r;i++)
        {
            dp[i][0]=1;
        }
        for(int i=1;i<r;i++)
        {
            for(int j=1;j<c;j++)
            {
            dp[i][j]=dp[i-1][j]+dp[i][j-1];

            }
            }
        cout<<dp[r-1][c-1];
        cout<<endl;
        }

        }


