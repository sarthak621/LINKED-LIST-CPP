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

    ListNode* findMiddle(ListNode* head){
        //slow and fast approach
        ListNode* slow=head;
        ListNode* fast=head;
        
        fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* leftHead ,ListNode* rightHead){
        ListNode* dummyNode=new ListNode(-1);
        ListNode* curr=dummyNode;
        
        ListNode* left=leftHead;
        ListNode* right=rightHead;
       
        
        while(left!=NULL && right!=NULL){
            if(left->val<=right->val){
                
                curr->next=left;
                left=left->next;
            }
            else{
                curr->next=right;
                right=right->next;
            }
             curr = curr->next;
        }
        
         // If any remaining nodes in either list, attach them
        if(left!=NULL){
            curr->next=left;
        }

        if(right!=NULL){
             curr->next=right;     
        }

        return dummyNode->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;

        else{
            //find middle by slow and fast way
            ListNode* middle= findMiddle(head);

            //left head and right head
            ListNode* leftHead=head;
            ListNode* rightHead=middle->next;

            middle->next=NULL;

            //apply divide on the left head and right head
            leftHead=sortList(leftHead);
            rightHead=sortList(rightHead);

            return merge(leftHead,rightHead);
        }


        
    }
};