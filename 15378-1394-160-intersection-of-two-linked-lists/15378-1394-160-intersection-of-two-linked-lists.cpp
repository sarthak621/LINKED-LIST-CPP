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

    ListNode* findCollision(ListNode* small,ListNode* high,int diff){
            while(diff){
                diff--;
                high=high->next;
            }

            while(small!=high){
                small=small->next;
                high=high->next;
            }
            return small;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        if(headA==NULL||headB==NULL) return NULL;
        
        //approach of length diffrence
        ListNode* head1=headA;
        ListNode* head2=headB;
        
        //calculating the length of both t1,t2
        int t1=0;
        int t2=0;
        while(head1!=NULL){
           t1++;
           head1=head1->next; 
        }

        while(head2!=NULL){
           t2++;
           head2=head2->next; 
        }   

        head1=headA;
        head2=headB;    

        if(t2>t1){
            return findCollision(head1,head2,(t2-t1));
        } 

        else{
            return findCollision(head2,head1,(t1-t2));
        }

    }
};

//T.C -->O(n1)+O(n2)+O(n2-n1)+O(n1)