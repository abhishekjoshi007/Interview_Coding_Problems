/*https://www.naukri.com/code360/problems/reverse-stack-using-recursion_631875?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio&leftPanelTabValue=PROBLEM*/

void insertAtBottom(stack<int> &stack, int element) {
  //base case
  if (stack.empty()) {
      stack.push(element);
      return;
  }

  int num=stack.top();
  stack.pop();

  insertAtBottom(stack, element);
  stack.push(num);
}

void reverseStack(stack<int> &stack) {
    if(stack.empty())
    return;

    int num =stack.top();
    stack.pop();

    reverseStack(stack);

    insertAtBottom(stack,num);
}