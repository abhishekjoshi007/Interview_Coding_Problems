/*https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/*/


class Solution {
private: 
int findLen(ListNode* head)
{
    int count=0;
    ListNode* temp=head;
    while(temp!=NULL){
        count=count+1;
        temp=temp->next;

    }
    return count;
}
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        //finding length of linked list 
        int l= findLen(head);
        int ans=l-n;

        if(ans<=0)
        {
            return head->next; ;
        }
         
         // Step 3: Traverse to the node just before the one to be deleted
        ListNode* temp = head;
        for (int i = 0; i < ans - 1; i++) {
            temp = temp->next;
        }

        // Step 4: Remove the nth node from the end
        if (temp->next != NULL) {
            temp->next = temp->next->next;
        }

        // Step 5: Return the updated head
        return head;
        
    }
};