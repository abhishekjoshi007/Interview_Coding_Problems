/*Given an expression string exp. Examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
For example, the program should print 'balanced' for exp = “[()]{}{[()()]()}” and 'not balanced' for exp = “[(])”

Input:
The first line of input contains an integer T denoting the number of test cases.  Each test case consists of a string of expression, in a separate line.

Output:
Print 'balanced' without quotes if the pair of parenthesis is balanced else print 'not balanced' in a separate line.

Constraints:
1 ≤ T ≤ 100
1 ≤ |s| ≤ 105

Example:
Input:
3
{([])}
()
([]

Output:
balanced
balanced
not balanced
Question Link:https://practice.geeksforgeeks.org/problems/parenthesis-checker/0
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    
	    stack<char> st;
	    int flag=1;
	    for(int i=0;i<s.size();i++)
	    {
	        if (s[i]=='(' || s[i]=='{'|| s[i]=='[' )
	        st.push(s[i]);
	        
	        else if(s[i]==')' && !st.empty())
	        {
	            if (st.top()=='(' )
	            {
	            st.pop();
	            flag=0;
	            }
	          else
	            {
	            flag=1;
	            break;
	                
	            }
	        }
	         else if(s[i]==']' && !st.empty())
	        {
	            if (st.top()=='[')
	            {
	            st.pop();
	            flag=0;
	            }
	            else
	            {
	            flag=1;
	            break;
	                
	            }
	           
	        }
	        else if(s[i]=='}' && !st.empty())
	        {
	            if (st.top()=='{' )
	            {
	            st.pop();
	            flag=0;
	            }
	            else
	            {
	            flag=1;
	            break;
	                
	            }
	        }
	        else 
	        {
	            flag=1;
	            break;
	        }
	    }
	    
	    if(flag==0 && st.empty())
	    cout<<"balanced"<<'\n';
	    else 
	    cout<<"not balanced"<<'\n';
	}
	return 0;
}