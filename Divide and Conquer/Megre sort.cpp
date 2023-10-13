/*

The task is to complete merge() function which is used to implement Merge Sort.

Example 1:

Input:
5
4 1 3 9 7

Output: 
1 3 4 7 9
Example 2:

Input:
10
10 9 8 7 6 5 4 3 2 1

Output: 
1 2 3 4 5 6 7 8 9 10
Your Task:
You don't need to take the input or print anything. Your task is to complete the function merge() which takes the array arr[], the starting position of the first array (l),  the ending position of the first array (m) and the ending position of the second array (r) as its inputs and modifies the array arr[] such that it is sorted from position l to position r. The range [l,m] and [m+1,r] are already sorted.

Expected Auxiliary Space: O(n)
Expected Time Complexity: O(n)  (for the merge() function) 

Constraints:
1 <= N <= 105
1 <= arr[i] <= 103

*/

// C program for implementation of Merge Sort
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int r);

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}// } Driver Code Ends


/* The task is to complete merge() which is used
   in below mergeSort() */
/*   l is for left index and r is right index of the
   sub-array of arr to be sorted
void mergeSort(int arr[], int l, int r) {
    if (l < r)   {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
} */

// Merges two subarrays of arr[].  First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    
     int n1=m-l+1,n2=r-m;
     int left[n1],right[n2],i,j,k;
    
     
     for(i=0;i<n1;i++)
     {
         left[i]=arr[l+i];
     }
     
     for(j=0;j<n2;j++)
     {
         right[j]=arr[m+j+1];
     }
     
     i=0,j=0,k=l;
     
     while(i<n1 && j<n2)
     {
         if(left[i] <= right[j])
         {
             arr[k]=left[i];
             i++;
             
         }
         
         else
         {
             arr[k]=right[j];
             j++;
             
             
         }
         k++;
     }
     
     while(i < n1)
     {
         arr[k]=left[i];
         i++;
         k++;
         
     }
     
     while(j < n2)
     {
         arr[k]=right[j];
         j++;
         k++;
         
     }
     
}