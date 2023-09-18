/*## 5- Zig Zag Array

### Array Zigzag

You are given an array of N integers. You have to make the given array into a zigzag array. During converting given array into a zigzag array you can perform a move, which consists of choosing any element and decreasing it by 11.

An array A� is a zigzag array if either:
1. Every even-indexed element is greater than adjacent elements, ie. A[0]>A[1]<A[2]>A[3]<A[4]>...�[0]>�[1]<�[2]>�[3]<�[4]>...
2. OR, every odd-indexed element is greater than adjacent elements, ie. A[0]<A[1]>A[2]<A[3]>A[4]<...�[0]<�[1]>�[2]<�[3]>�[4]<...

Print the minimum number of moves to transform the given array into a zigzag array.

### Input Format

The first line contains an integer N� size of the array.
The second line contains N� space-separated integers.

### Output Format

Print an integer the minimum number of moves to transform the given array into a zigzag array.

### Constraint

2≤N≤1052 ≤ � ≤ 1051≤arr[i]≤1031 ≤ ���[�] ≤103

### Time Limit

11 second

### Example

### Input 1

3
2 3 4

### Output 1

2

### Input 2

5
10 7 2 7 3

### Output 2

4

### Sample test case explanation

In the first example:
array = [2,3,4][2,3,4]
We can decrease 33 to 11 to form [2,1,4][2,1,4] so all even indexed elements are greater than the neighbors. Hence the output is 22.

Solution 
check for an even position by decreasing all odd elements and then check for the odd position by decreasing all even positions. Store count in separate variable and then take minimum of that one. 
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
 int n,i,d,count_e=0,count_o=0,flag;
 cin>>n;
 int a[n],b[n]; //Taking 2 array for even changes and odd changes
 for(i=0;i<n;i++)
 {
   cin>>a[i];
 }
 for(i=0;i<n;i++)
 {
   b[i]=a[i];
 }
 flag=0;
 //For Odd  pos. decrement even element by one
 for(i=0;i<n-1;i++) //till n-1 coz last element will not found i+1 element and
 {                  // hence garbage value is given
   
     if(flag==0)
     {
       if(a[i]>=a[i+1])
       {
         d=a[i]-a[i+1]+1;
         a[i]=a[i]-d;
         count_o+=d;
       }
     }
     
   else
   {
     if(a[i]<=a[i+1])
     {
       
       d=(a[i+1]-a[i])+1;
       a[i+1]=a[i+1]-d;
       count_o+=d;
     }
   }
   
   flag= !flag; //assigning not equal to.
 
 }
 flag=0;
  
 //For eve  pos. decrement odd element by one
 for(i=0;i<n-1;i++) //till n-1 coz last element will not found i+1 element and
 {                  // hence garbage value is given
   
     if(flag==0)
     {
       if(b[i]<=b[i+1])
       {
         d=b[i+1]-b[i]+1;
         b[i+1]=b[i+1]-d;
         count_e+=d;
       }
     }
     
   else
   {
     if(b[i]>=b[i+1])
     {
       
       d=(b[i]-b[i+1])+1;
       b[i]=b[i]-d;
       count_e+=d;
     }
   }
   
   flag= !flag; //assigning not equal to.
 
 }

 
 cout<<min(count_e,count_o);
  return 0;
}
