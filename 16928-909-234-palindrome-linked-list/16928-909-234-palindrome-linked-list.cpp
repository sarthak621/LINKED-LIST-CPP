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

    ListNode* middle(ListNode* head){
        //slow and fast approach
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast->next!=NULL){
            fast=fast->next;
            if(fast->next!=NULL){
                fast=fast->next;
                slow=slow->next;
            }
        }
        return slow;
    }

    ListNode* reverseHead2(ListNode* prev,ListNode* curr){
        //recursive way
        if(curr==NULL){
            return prev;
        }
        
        ListNode* temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;

        return reverseHead2(prev,curr);

    }

    bool compareList(ListNode* head, ListNode* head2){
        
        if(head==head2){
            return false;
        }
        while(head2!=NULL){
            if(head->val==head2->val){
                head=head->next;
                head2=head2->next;
            }
            else{
                return false;
            }
        }
        return true;
    }

    bool isPalindrome(ListNode* head) {
        
        // bruteforce--------->>>>>>>>> REVERSE AND CHECK WHETHER IT IS PALINDROME OR NOT
        
        // BETTER WAY  
             //BREAK INTO 2 PARTS
             //REVERSE THE SECOND PART
             //COMPARE BOTH LL

         //step1 breaking in to two halves
          ListNode* midNode= middle(head);
          ListNode* head2= midNode->next;

          //step2 reverse the second part
          ListNode* prev=NULL;
          ListNode* curr=head2;
          head2=reverseHead2(prev,curr);

          //step3 compare the LL
          bool ans= compareList(head,head2);
          return ans;
    }
};