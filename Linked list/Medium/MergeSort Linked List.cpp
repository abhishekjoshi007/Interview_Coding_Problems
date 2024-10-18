/*https://www.naukri.com/code360/problems/mergesort-linked-list_630514?leftPanelTab=0%3Fsource%3Dyoutube&campaign=YouTube_CodestudioLovebabbar5thfeb&utm_source=youtube&utm_medium=affiliate&utm_campaign=YouTube_CodestudioLovebabbar5thfeb&leftPanelTabValue=PROBLEM*/

node *findMid(node *head) {
    node* slow=head;
    node* fast=head->next;

    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    return slow;
    
}

node *merge(node *left, node *right) {
    if(left==NULL)
    return right;

    if(right==NULL)
    return left;

    node* ans=new node(-1);
    node* temp=ans;

    while (left != NULL & right != NULL) {
    if (left->data <= right->data) {
        temp->next=left;
        temp=left;
        left=left->next;
    }
    else{
        temp->next=right;
        temp=right;
        right=right->next;
    }
    }

    //suppose left is non empty but right is
    while (left != NULL) {
    temp->next = left;
    temp = left;
    left = left->next;
    }

    while (right != NULL) {
    temp->next = right;
    temp = right;
    right = right->next;
    }

    //moving ans to next
    ans=ans->next;

    return ans;

}


//main function 

node* mergeSort(node *head) {
    //base case
    if(head==NULL || head->next==NULL)
    return head;

    //find mid
    node* mid= findMid(head);
    node* left=head;
    node* right=mid->next;
    //splitting in 2 parts
    mid->next=NULL;

    //recursive call
    left=mergeSort(left);
    right=mergeSort(right);

    //merge
    node* result= merge(left,right);

    return result;

}