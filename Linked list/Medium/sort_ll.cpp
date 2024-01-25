/*
question - https://leetcode.com/problems/sort-list/description/

Solution - https://www.youtube.com/watch?v=8ocB7a_c-Cc&list=RDCMUCJskGeByzRRSvmOyZOz61ig&index=3
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 ListNode* findMiddle(ListNode* head)
 {
  //tortoise and hare algorithm
 ListNode* slow=head;
 ListNode* fast=head->next;

 while(fast!=NULL && fast->next!=NULL)
 {
     slow=slow->next;
     fast=fast->next->next;

 }

 return slow;

 }
ListNode* mergeTwoList(ListNode* left, ListNode* right)
{
    ListNode* dummyNode=new ListNode(-1);
    ListNode* temp=dummyNode;


while(left!=NULL && right!=NULL)
{
    if(left->val < right->val)
    {
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
if(left)
{
    temp->next=left;

}
else{
    temp->next=right;
}

return dummyNode->next;
}

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
        return head;

        ListNode* middle=findMiddle(head);
        ListNode* rightHead=middle->next;
        middle->next=NULL;
        ListNode* leftHead=head;

        leftHead=sortList(leftHead);
        rightHead=sortList(rightHead);
        return mergeTwoList(leftHead,rightHead);

        
    }
};