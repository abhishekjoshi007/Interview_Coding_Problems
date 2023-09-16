/* Find majority Number

### Maximum Difference

You are given an array A consisting of N integers, you have to find the maximum value of the following expression:
|Ai−Aj|−  |i−j| where, 0<=i,j<N0<=�,�<� and Ai��, Aj�� are the Array elements.

### Input Format

The first line of input contains an integer T� denoting the number of test cases.
Each test case contains two lines,
the first line contains integer N� where N� is the number of elements in the array.
Second line contains N� space separated integers Ai��.

### Output Format

Print the maximum value of the above given expression, for each test case separated by a new line.

### Constraints

1≤T≤1001≤�≤1001≤N≤1051≤�≤1050≤Ai≤1050≤��≤105

Note: Use Fast I/O (scanf/printf or any other ways) to handle large test files.

### Time Limit

1 second

### Example

### Input

2
3
2 2 2
4
2 3 4 2

### Output

2
4

### Solution

**Method 2 (tricky):** First of all lets make four equations by removing the absolute value signs (“|”). The following 4 equations will be formed, and we need to find the maximum value of these equations and that will be our answer.

1. arr[i] – arr[j] + i – j = (arr[i] + i) – (arr[j] + j)
2. arr[i] – arr[j] – i + j = (arr[i] – i) – (arr[j] – j)
3. arr[i] + arr[j] + i – j = -(arr[i] – i) + (arr[j] – j)
4. arr[i] + arr[j] – i + j = -(arr[i] + i) + (arr[j] + j)

Observe the equations (1) and (4) are identical. Similarly, equations (2) and (3) are identical.

Now the task is to find the maximum value of these equations. So the approach is to form two arrays, first_array[], it will store arr[i] + i, 0 <= i < n, second_array[], it will store arr[i] – i, 0 <= i < n.

Now our task is easy, we just need to find the maximum difference between the two values of these two arrays.

For that, we find the maximum value and minimum value in the first_array and store their difference:

ans1 = (maximum value in first_array – minimum value in first_array)

Similarly, we need to find the maximum value and minimum value in the second_array and store their difference:

ans2 = (maximum value in second_array – minimum value in second_array)

Our answer will be a maximum of ans1 and ans2.

Below is the implementation of the above approach:

*/
#include <bits/stdc++.h>
using namespace std;

// Return maximum |arr[i] - arr[j]| + |i - j|
int findValue(int arr[], int n)
{
    int a[n], b[n], tmp;

    // Calculating first_array and second_array
    for (int i = 0; i < n; i++)
    {
        a[i] = (arr[i] + i);
        b[i] = (arr[i] - i);
    }

    int x = a[0], y = a[0];

    // Finding maximum and minimum value in
    // first_array
    for (int i = 0; i < n; i++)
    {
        if (a[i] > x)
            x = a[i];

        if (a[i] < y)
            y = a[i];
    }

    // Storing the difference between maximum and
    // minimum value in first_array
    int ans1 = (x - y);

    x = b[0];
    y = b[0];

    // Finding maximum and minimum value in
    // second_array
    for (int i = 0; i < n; i++)
    {
        if (b[i] > x)
            x = b[i];

        if (b[i] < y)
            y = b[i];
    }

    // Storing the difference between maximum and
    // minimum value in second_array
    int ans2 = (x - y);

    return max(ans1, ans2);
}

// Driven Code
int main()
{
    int arr[] = {1, 2, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << findValue(arr, n) << endl;

    return 0;
}

/*
**Method – 3**

```
This solution is space optimization on above mentioned (method2) solution.
In Method 2 solution we had used two matrix of size n which laid to O(n) space complexity
but here we only use O(1) space instead of that two n size array
```

**Implementation:**

```cpp
// Optimized CPP program to find maximum value of
// |arr[i] - arr[j]| + |i - j|
*/

#include <bits/stdc++.h>
using namespace std;

// Return maximum |arr[i] - arr[j]| + |i - j|
int findValue(int A[], int n)
{
    /*
        Let us walk through all possible cases in | A[i]-A[j] | + | i-j | ->
            1. A[i]>A[j] , i>j
            A[i]-A[j] --- positive
            i-j	 --- positive
            (A[i]+i)-(A[j]+j) ------------------- Eqn 1

            2. A[i]<A[j] , i<j
            A[i]-A[j] --- negative
            i-j	 --- negative
            -((A[i]+i)-(A[j]+j)) ------------------- Eqn 2

            3. A[i]<A[j] , i>j
            A[i]-A[j] --- negative
            i-j	 --- positive
            (A[j]-j)-(A[i]-i) ------------------- Eqn 3

            4. A[i]>A[j] , i<j
            A[i]-A[j] --- positive
            i-j	 --- negative
            -((A[j]-j)-(A[i]-i)) ------------------- Eqn 4

            Eqn 3 and 4 are the same only difference in sign
            Eqn 1 and 2 are the same only difference in sign,
            So we consider these two sets of equations
    */

    int mx1 = INT_MIN;
    int mn1 = INT_MAX;

    int mn2 = INT_MAX;
    int mx2 = INT_MIN;

    // mx1, mn1 represents the largest and smallest arr[i]+i
    // mx2, mn2 represents the largest and smallest arr[i]-i

    for (int i = 0; i < n; i++)
    {
        mx1 = max(mx1, A[i] + i);
        mn1 = min(mn1, A[i] + i);

        mx2 = max(mx2, A[i] - i);
        mn2 = min(mn2, A[i] - i);
    }
    int res = 0;

    /* First set of equations are-
        1. (A[i]+i)-(A[j]+j)
        2. -((A[i]+i)-(A[j]+j));

        The best solution can only be achieved when ---
            res=max(res,mx1-mn1);
            res=max(res,-(mn1-mx1));

        But these two res's are the same on rearranging, so take either of them
    */
    res = max(res, mx1 - mn1);

    /* Second set of equations are-
            1. (A[j]-j)-(A[i]-i)
            2. -((A[j]-j)-(A[i]-i));

    The best solution can only be achieved when ---
            res=max(res,mx2-mn2);
            res=max(res,-(mn2-mx2));

    But these two res's are the same on rearranging, so take either of them
    */
    res = max(res, mx2 - mn2);
    return res;
}

// Driven Code
int main()
{
    int arr[] = {1, 2, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << findValue(arr, n) << endl;

    return 0;
}

// code by RainX (Abhijit Roy)
```