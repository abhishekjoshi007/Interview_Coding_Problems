/*
Given a sorted and rotated array A of N distinct elements which is rotated at some point, and given an element K. The task is to find the index of the given element K in the array A.

Input:
The first line of the input contains an integer T, denoting the total number of test cases. Then T test cases follow. Each test case consists of three lines. First line of each test case contains an integer N denoting the size of the given array. Second line of each test case contains N space separated integers denoting the elements of the array A. Third line of each test case contains an integer K denoting the element to be searched in the array.

Output:
Corresponding to each test case, output the index of the element found in the array.  If element is not present, then output -1.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 107
0 ≤ Ai ≤ 108
1 ≤ K ≤ 108

Example:
Input:
3
9
5 6 7 8 9 10 1 2 3
10
3
3 1 2
1
4
3 5 1 2
6

Output:
5
1
-1

Explanation:
Testcase 1: 10 is found at index 5.
*/

using namespace std;

int binarysearch(int arr[],int n,int k)
{
    int l=0,h=n-1;
    
    while(l<=h)
    {
        
        int mid=(l+h)/2;
        
        if(arr[mid]==k)
        return mid;
        
        else if(arr[l]<=arr[mid])
        //sorted left side
        {
            if(arr[l]<=k && k<=arr[mid])
            h=mid-1;
            
            else 
            l=mid+1;
        }
        
        else
        {
            if(arr[mid]<=k && k<=arr[h] )
            {
                l=mid+1;
            }
            
            else
            h=mid-1;
            
        }
        
    }
    return -1;
    
}

int main() {
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        int arr[n];
        
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            
        }
        
        int k;
        cin>>k;
        
        cout<<binarysearch(arr,n,k)<<endl;
        
        
    }
	return 0;
}