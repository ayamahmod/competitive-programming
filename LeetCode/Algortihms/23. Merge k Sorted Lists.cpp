class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head=NULL, * curr=NULL;
        while(l1!= NULL && l2!=NULL){
            ListNode* temp;
            if(l1->val <= l2->val)   {temp=l1;   l1=l1->next;}
            else    {temp=l2;   l2=l2->next;}

            if(curr)  {curr->next=temp;  curr=curr->next;}
            else  curr=temp;
            if(head==NULL)  head=curr;
        }
        if(l1!=NULL){
            if(curr)  curr->next=l1;
            else head=l1;
        }
        if(l2!=NULL){
            if(curr)  curr->next=l2;
            else head=l2;
        }
        return head;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)     return NULL;
        while(lists.size()>1){
            ListNode* merged = mergeTwoLists(lists[lists.size()-1],lists[lists.size()-2]);
            lists.pop_back();   lists.pop_back();
            lists.push_back(merged);
        }
        return lists[0];
    }
};
