/* Question- https://leetcode.com/problems/subsets/description/ */
/*Algo 
either we will include a no or not include a no. in this way greate a recursion tree 
Base case we a taking one pointer i if i>array sixe return nut first print the output array element 
*/


//For Solution explination https://www.youtube.com/watch?v=iqKwK_o93Gw

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
     solve(nums,output,index+1,ans);

    

 }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int index =0;

        solve(nums, output, index, ans);
        return ans;
        
    }
};