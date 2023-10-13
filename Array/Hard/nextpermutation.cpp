/*A **permutation** of an array of integers is an arrangement of its members into a sequence or linear order.

- For example, for `arr = [1,2,3]`, the following are all the permutations of `arr`: `[1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1]`.

The **next permutation** of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the **next permutation** of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

- For example, the next permutation of `arr = [1,2,3]` is `[1,3,2]`.
- Similarly, the next permutation of `arr = [2,3,1]` is `[3,1,2]`.
- While the next permutation of `arr = [3,2,1]` is `[1,2,3]` because `[3,2,1]` does not have a lexicographical larger rearrangement.

Given an array of integers `nums`, *find the next permutation of* `nums`.

The replacement must be **[in place](http://en.wikipedia.org/wiki/In-place_algorithm)** and use only constant extra memory.

**Example 1:**

```
Input: nums = [1,2,3]
Output: [1,3,2]

```

**Example 2:**

```
Input: nums = [3,2,1]
Output: [1,2,3]

```

**Example 3:**

```
Input: nums = [1,1,5]
Output: [1,5,1]

```

!https://media.geeksforgeeks.org/wp-content/uploads/20220908060940/Nextpermutation.png
**Follow the steps below to implement the above observation:**

- Iterate over the given array from end and find the first index **(pivot)** which doesn’t follow property of non-increasing suffix, **(i.e, arr[i] < arr[i + 1]).**
- Check if **pivot** index does not exist
    - This means that the given sequence in the array is the largest as possible. So, swap the complete array.
- Otherwise, Iterate the array from the end and find for the **successor** of **pivot** in suffix.
- Swap the **pivot** and **successor**
- Minimize the suffix part by reversing the array from **pivot + 1** till **N**.

Below is the implementation of the above approach:*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {

       int n = nums.size(), i, j;
 
    // Find for the pivot element.
    // A pivot is the first element from
    // end of sequenc ewhich doesn't follow
    // property of non-increasing suffix
    for (i = n - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            break;
        }
    }
 
    // Check if pivot is not found
    if (i < 0) {
        reverse(nums.begin(), nums.end());
    }
 
    // if pivot is found
    else {
 
        // Find for the successor of pivot in suffix
        for (j = n - 1; j > i; j--) {
            if (nums[j] > nums[i]) {
                break;
            }
        }
 
        // Swap the pivot and successor
        swap(nums[i], nums[j]);
 
        // Minimise the suffix part
        reverse(nums.begin() + i + 1, nums.end());
    }

    }
};
