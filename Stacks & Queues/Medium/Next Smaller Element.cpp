/*https://www.naukri.com/code360/problems/next-smaller-element_1112581?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio&leftPanelTabValue=PROBLEM
*/

#include<stack>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
  //to store element and compare
  stack<int> s;
  s.push(-1);

  vector<int> ans(n);

  for (int i = n-1; i >= 0; i--) {

      int curr=arr[i];

      while (curr <= s.top()) {
      s.pop();
      }

      ans[i]=s.top();
      s.push(curr);
      
  }

    return ans;
}