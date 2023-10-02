/*
Ques - https://leetcode.com/problems/longest-palindromic-substring/description/

Algorithm

Follow the steps mentioned below to implement the idea:

- Use two pointers, **low** and **hi**, for the left and right end of the current palindromic substring being found.
- Then checks if the characters at **str[low]** and **str[hi]** are the same.
    - If they are, it expands the substring to the left and right by decrementing **low** and incrementing **hi**.
    - It continues this process until the characters at **str[low]** and **str[hi]** are unequal or until the indices are in bounds.
- If the length of the current palindromic substring becomes greater than the maximum length, it updates the maximum length.

*/

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