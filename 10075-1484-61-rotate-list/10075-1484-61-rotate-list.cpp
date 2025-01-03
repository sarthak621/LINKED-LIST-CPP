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
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        while(head==NULL || head->next==NULL) return head;
        
        //step1 find the tail and count of nodes
        ListNode* tail=head;
        int count=1;
        while(tail->next!=NULL){
            tail=tail->next;
            count++;
        }

        if(k%count==0) return head;

        //step2 if k%count is not 0 attach the tail to head and calculate new value of k for{larger k}
        k=k%count;
        tail->next=head;
        
        int diff=count-k;     //traverse to diff
        ListNode* temp=head;
        while(diff>1){
            temp=temp->next;
            diff--;
        }

        //step3 update temp and head value
        head=temp->next;
        temp->next=NULL;
        
        return head;
    }
    
};