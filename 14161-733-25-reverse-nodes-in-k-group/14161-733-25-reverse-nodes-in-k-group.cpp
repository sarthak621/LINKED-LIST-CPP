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
    
    ListNode* reverseLL(ListNode* temp){
            ListNode* prev=NULL;
            ListNode* curr=temp;

            while(curr!=NULL){
                ListNode* nextNode=curr->next;
                curr->next=prev;
                prev=curr;
                curr=nextNode;
            }       
            return prev;
    }

    ListNode* findKthNode(ListNode* temp, int k){
        if (temp == nullptr || k <= 0) {
        // Handle edge case: empty list or invalid k
        return nullptr;
       }
        
        ListNode* curr=temp;
        while(k>1 && curr!=NULL){
            k--;
            curr=curr->next;
        }
        return curr;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head==NULL && head->next==NULL) return head;
        
        ListNode* temp=head;
        ListNode* prevNode=NULL;
        
        while(temp!=NULL){
                ListNode* KthNode=findKthNode(temp,k);

                if(KthNode==NULL){
                    if(prevNode) prevNode->next=temp;
                    break;
                }

                ListNode* nextNode=KthNode->next;
                KthNode->next=NULL;

                //reverse the K nodes
                reverseLL(temp);

                if(temp==head){
                    head=KthNode;
                }
                else{
                    prevNode->next=KthNode;
                }

                prevNode=temp;
                temp=nextNode;
        }
        return head;
    }
};