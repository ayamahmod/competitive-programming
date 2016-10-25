/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL)  return head;
        ListNode* fast=head;
        ListNode* slow=NULL;
        int ctr=1;
        while(fast!=NULL){
            if(ctr==n+1)    slow=head;
            else if(slow)    slow=slow->next;
            fast=fast->next;
            ctr++;
        }
        if(slow){
            ListNode* ptr=slow->next->next;
            delete slow->next;
            slow->next=slow->next->next;
        }
        else if(ctr==n+1){
            ListNode* ptr=head->next;
            delete head;
            head=ptr;
        }
        return head;

    }
};
