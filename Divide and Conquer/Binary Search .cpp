/*
Given a sorted array of integers and a key to be searched in the array. Print the position of the key in the array, if present. If it's not present in the array, report it. 

Input:
The first line contains an integer 'T' denoting the number of test cases. Then 'T' test cases follow. Each test case consists of 3 lines. First line of each test case contains an integer N denoting the size of the array. Second line of each test case consists of 'N' space separated integers denoting the elements of the array A[]. The third line contains a key 'k' .

Output:
Prints the position of the key if its present in the array else print -1 if the key is not present in the array.

User Task:
You don't need to read input or print anything. Your task is to complete the function bin_search() which takes the array A[], key k and the leftmost and the rightmost index in the array (left and right respectively) and returns the position where the key k occurs in the array. If it's not present, return -1.

Expected Time Complexity: O(LogN)
Expected Auxiliary Space: O(LogN) if solving recursively and O(1) otherwise.

Constraints:
1 <= T <= 100
1 <= N <= 104
1 <= arr[i] <= 104

Example:
Input:
2
5
1 2 3 4 5 
4
5
11 22 33 44 55
445

Output:
3
-1

Explanation:
Test Case 1:
4 is present at the index 3 (0-based) in the array.

Test Case 2:
Since 445 is not present in the given array, we return -1. 
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
	    
	    long long int arr[2*n];
	    
	    for(long long int i=0;i<2*n;i++)
	    {
	        cin>>arr[i];
	    }
	    
	    sort(arr,arr+(2*n));
	    
	    
	    cout<<arr[(2*n/2)-1] + arr[2*n/2]<<endl;
	    
	    
	    
	}
	return 0;
}