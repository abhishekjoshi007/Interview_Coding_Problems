/*Question link - https://leetcode.com/problems/permutations/submissions/ */

/*
Algo-
The main idea is swapping we will replace consider 123 as example
1- 1 element will be 1 and rest two will exchange position 
    123 -
    > followed by 2 will stay in pos. and rest two will shift 
    123 , 132

    132-
    -> followed by 3 will stay in pos. and rest two will shift 
    132 , 231
 Video - https://www.youtube.com/watch?v=b1iFSSxg9Y8
*/


lass Solution {
public:

    vector<vector<int>> ans;
    void helper(vector<int>& nums, int i)
    {
        if(i==nums.size())
        {
            ans.push_back(nums);
            return;
        }

        for(int j=i;j<nums.size();j++)
        {
            swap(nums[i],nums[j]);
            helper(nums,i+1);

            //backtracting 
            swap(nums[i],nums[j]);

        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int i=0;
        helper(nums,i);
        return ans;
    }
};