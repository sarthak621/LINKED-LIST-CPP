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
    ListNode* middleNode(ListNode* head) {
        //USING THE SLOW AND FAST APPROACH TO FIND THE MIDDLE
        ListNode* slow=head;
        ListNode* fast=head;
  
        
        //if there is no node present
        if(fast==NULL){
            return NULL;
        }

        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
                slow=slow->next;
            }
        }

        return slow;


    }
};