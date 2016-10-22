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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      if(l1==NULL) return l2;
      if(l2==NULL) return l1;
      ListNode* result=new ListNode((l1->val+l2->val)%10);
      int carry=(l1->val+l2->val)/10;
      result->next=NULL;
      ListNode* ptr=result;
      l1=l1->next;  l2=l2->next;
      while(l1!=NULL && l2!=NULL){
        ptr->next=new ListNode((l1->val+l2->val+carry)%10);
        carry=(l1->val+l2->val+carry)/10;
        ptr=ptr->next;
        l1=l1->next;    l2=l2->next;
      }
      ListNode* curr=l1==NULL? l2:l1;
      while(curr!=NULL){
        ptr->next=new ListNode((curr->val+carry)%10);
        carry=(curr->val+carry)/10;
        ptr=ptr->next;
        curr=curr->next;
      }
      if(carry)
        ptr->next=new ListNode(carry);

      return result;
    }
};
