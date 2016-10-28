class Solution {
public:
    ListNode* reverseKnode(ListNode*& firstNode, ListNode* tail){
        ListNode* node1=firstNode;
        ListNode* node2= node1->next;
        node1->next=tail;
        while(node2!=tail){
            ListNode* next=node2->next;
            node2->next=node1;
            node1=node2;
            node2=next;
        }
        return node1;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || k==1)  return head;
        ListNode* prev=NULL, *lastNode=head;
        int counter=0;
        while(lastNode !=NULL){
            counter+=1;
            if(counter==k)  {
                ListNode* tail=lastNode->next, *firstNode;
                if(prev==NULL){firstNode= head;     head=reverseKnode(firstNode, tail);}
                else    {firstNode=prev->next;  prev->next=reverseKnode(firstNode, tail);}
                prev=firstNode;
                lastNode=tail;
                counter=0;
            }
            else lastNode=lastNode->next;
        }
        return head;
    }
};
