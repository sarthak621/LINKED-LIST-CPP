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
    ListNode *detectCycle(ListNode *head) {
        
       
        // doing it by the slow and fast approach
        // if slow==fast then loop present else not

        ListNode* slow=head;
        ListNode* fast=head;

        // step 1 : LOOP FINDING
        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
                slow=slow->next;
            }

            if(fast==slow){
                break;
            }
        }
      
      //STEP 2: SLOW=HEAD

      slow=head;

      //step 3: slow and next ko 1 step move karo
        if(fast==NULL){
            return NULL;
        }
  
      while(fast!=slow){
        slow=slow->next;
        fast=fast->next;
      }

      return slow;
    }
    
};