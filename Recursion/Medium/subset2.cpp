/* Question- https://leetcode.com/problems/subsets-ii/description/ */
/*Algo 
Either we will include a no or not include a no. in this way greate a recursion tree and before calling to the right tree 
Check do we consecutive no. if we have then i++ i.e skip them 
Base case we a taking one pointer i if i>array sixe return nut first print the output array element 
*/

class Solution {
    void solve(vector<int> nums, vector<int> output, int index,vector<vector<int>> &ans)
 {
     
     
     if (index == nums.size())
     {
         ans.push_back(output);
         
         return ;
     }

     //include 
     output.push_back(nums[index]);
     solve(nums,output,index+1,ans);

     //exclude
     output.pop_back();
     //before giving the next recusrion call check do we have same consecutive no.if we have i++ then skip it all over 
     while (index<nums.size()-1 && nums[index]==nums[index+1])
     index++;

     solve(nums,output,index+1,ans);

    

 }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        //here sequence matter 
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> output;
        int index =0;
        solve(nums, output, index, ans);
        sort(ans.begin(),ans.end());
        return ans; 
        
    }
};