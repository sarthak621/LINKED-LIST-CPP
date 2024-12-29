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

    ListNode* reverseLL(ListNode* prev,ListNode* curr ){
        // base case
        if(curr==NULL){
            return prev;
        }

        // 1 case
        ListNode* nextNode=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextNode;

        //baki recursion
         return reverseLL(prev,curr);

    }

    ListNode* reverseList(ListNode* head) {
            ListNode* prev=NULL;
            ListNode* curr=head;
         return reverseLL(prev,curr);
    }
};


//    //reversing the LL 
//             // *************ITERATIVE APPROACH*****************

//             ListNode* prev=NULL;
//             ListNode* curr=head;

//             while(curr!=NULL){
//                 ListNode* nextNode=curr->next;
//                 curr->next=prev;
//                 prev=curr;
//                 curr=nextNode;
//             }       
//             return prev;