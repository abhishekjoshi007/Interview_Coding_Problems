/*/https://leetcode.com/problems/longest-palindromic-substring/description/

Algorithm 

1. Initialize an empty string ans to store the common prefix.
2. Sort the input list v lexicographically. This step is necessary because the common prefix should be common to all the strings, so we need to find the common prefix of the first and last string in the sorted list.
This in most of the sorting 
coz elements of vector are in lexicographic order and we are cheking only the first and the last element to check the common words 
3. Iterate through the characters of the first and last string in the sorted list, stopping at the length of the shorter string.
4. If the current character of the first string is not equal to the current character of the last string, return the common prefix found so far.
5. Otherwise, append the current character to the ans string.
6. Return the ans string containing the longest common prefix.*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        sort(strs.begin(),strs.end());

        int n=strs.size();
        string first=strs[0],sec=strs[n-1];
        for (int i=0;i<min(first.size(),sec.size());i++)
        {
            if(first[i]!=sec[i])
            {
                return ans;
            }
            ans+=first[i];
        }
         return ans;
    }
   
};