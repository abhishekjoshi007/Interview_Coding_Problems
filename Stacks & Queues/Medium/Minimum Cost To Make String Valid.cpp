/*https://www.naukri.com/code360/problems/minimum-cost-to-make-string-valid_1115770?leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio&leftPanelTabValue=PROBLEM*/


#include <bits/stdc++.h> 
int findMinimumCost(string str) {
  // odd condition 
  if(str.length()%2 ==1)
  return -1;

  //to storwe valid paranthesis/remove eand do rest of the operation 
  stack <char>s;
  for (int i = 0; i < str.length(); i++) {

    char ch=str[i];

    if (ch == '{') {
    s.push(ch);
    } 
    else {

    if (!s.empty() && s.top() == '{') {
      s.pop();
    } else {
      s.push(ch);
    }
    }
  }

  int a=0; int b=0;
  while (!s.empty()) {
  if (s.top() == '{') {
  a++;
  }
  else{
    b++;  
  }
  s.pop();
  }

int ans= (a+1)/2 + (b+1)/2;
return ans;
}