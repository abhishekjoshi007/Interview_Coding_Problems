/*https://www.naukri.com/code360/problems/sort-a-stack_985275?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio&leftPanelTabValue=PROBLEM*/


#include <bits/stdc++.h>

void sortedOrder(stack<int> &stack, int element) {
if(stack.empty() || (!stack.empty() && stack.top()<element))
{
  stack.push(element);
  return;
}

int num=stack.top();
stack.pop();

sortedOrder(stack, element);

stack.push(num);
}
void sortStack(stack<int> &stack)
{
  if (stack.empty()) {
    return;
  }

  int num = stack.top();
  stack.pop();

  sortStack(stack);

  sortedOrder(stack, num);
}