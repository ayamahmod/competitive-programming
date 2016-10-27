class Solution {
public:
  ListNode* swapPairs(ListNode* head) {
      if(head==NULL)  return head;
      if(head->next==NULL)    return head;
      ListNode* node1=head;
      ListNode* node2=head->next;
      ListNode* ptr=NULL;
      while(node2!=NULL){
        node1->next=node2->next;
        node2->next=node1;
        if(ptr==NULL) head=node2;
        else  ptr->next=node2;
        ptr=node1;
        node1=ptr->next;
        if(node1) node2=node1->next;
        else  node2=NULL;
      }
      return head;
  }
};
