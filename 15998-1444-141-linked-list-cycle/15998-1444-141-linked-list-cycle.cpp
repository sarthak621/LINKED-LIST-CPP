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
    bool hasCycle(ListNode *head) {
        // doing it by the slow and fast approach
        // if slow==fast then loop present else not

        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
                slow=slow->next;
            }

            if(fast==slow){
                //loop present
                return true;
            }
        }
        return false;
    }
};


// Time Complexity: O(n), where n is the number of nodes in the linked list.
// Space Complexity: O(1), because the space used does not depend on the size of the input.