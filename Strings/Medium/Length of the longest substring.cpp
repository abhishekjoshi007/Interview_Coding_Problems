/*
Given a string, find the length of the longest substring without repeating characters. For example, the longest substrings without repeating characters for “ABDEFGABEF” are “BDEFGA” and “DEFGAB”, with length 6.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is str.

Output:

Print the length of longest substring.

Constraints:

1 ≤ T ≤ 20
1 ≤ str ≤ 50

Example:

Input:
2
geeksforgeeks
qwertqwer

Output:
7
5
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    int max_m=INT_MIN;
	    for(int i=0;i<s.size();i++)
	    {   
	        int counter=0;
	        //declare here onlyto refresh freq each time outer loop starts
	        int freq[26]={0};
	        for(int j=i;j<s.size();j++)
	    {
	        if(freq[s[j]-'a']==0)
	        {
	            freq[s[j]-'a']++;
	            counter++;
	        }
	        else 
	        break;
	        
	    } 
	    if(counter>max_m)
	    max_m=counter;
	    }
	    cout<<max_m<<endl;
	}
	return 0;
}