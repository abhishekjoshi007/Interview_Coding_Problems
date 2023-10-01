/*
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

 

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
*/

class Solution {
public:
    string reverseWords(string s) {

        string res;
        int n=s.length();
        int i=0;
    while (i<n) {
            
            while (i<n && s[i] == ' ')
            i++;

            if(i>=n)
            {
            break;}

            int j=i+1;
            while (j<n && s[j]!= ' ')
            j++;

            string sub=s.substr(i,j-i);
                /*string substr (size_t pos, size_t len) const;
                pos: Position of the first character to be copied.
                len: Length of the sub-string.
                size_t: It is an unsigned integral type.
                
                // Take any string
                    string s1 = "Geeks";
                
                    // Copy two characters of s1 (starting
                    // from position 3)
                    string r = s1.substr(3, 2);
                
                    // prints the result
                    cout << "String is: " << r;

                    o/p ks
                */



            if(res.length()==0)
            {
                res=sub;
            }
            else{
                res=sub+" "+res;
            
            }
            i=j+1;
    }
    return res;

    }
};