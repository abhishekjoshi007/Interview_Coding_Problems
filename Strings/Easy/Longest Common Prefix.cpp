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
    string longestPalindrome(string s) {
        
        //we will have atleast one single char so max_length is 1
        int max_length=1;
        // it will keep track of substring start and end pos
        int st=0,end=0;
        int n=s.length();

        //for odd position
        for (int i=0;i<n-1;i++)
        {
            int l=i,r=i;
            while (l>=0 && r<n)
            {
                if(s[l] == s[r])
                {
                    l--;
                    r++;
                }
                else
                {
                break;
                }
            }

            int len=r-l-1;

            if(len>max_length)
            {
                max_length=len;
                st=l+1;
                end=r-1;
            }
            cout<<max_length;
        }

       //for even position 
        for (int i=0;i<n-1;i++)
        {
            int l=i,r=i+1;
            while (l>=0 && r<n)
            {
                if(s[l] == s[r])
                {
                    l--;
                    r++;
                }
                else
                break;
            }

            int len=r-l-1;

            if(len>max_length)
            {
                max_length=len;
                st=l+1;
                end=r-1;
            }
            cout<<max_length;
        }

    return s.substr(st,max_length);
    }
};