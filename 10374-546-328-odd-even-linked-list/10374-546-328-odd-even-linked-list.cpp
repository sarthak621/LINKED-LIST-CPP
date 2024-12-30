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
    ListNode* oddEvenList(ListNode* head) {
        //optimal solution

        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode* odd=head;
        ListNode* even=odd->next;
        ListNode* evenHead= even;

       

        while(even!=NULL && even->next!=NULL){
            odd->next=odd->next->next;
            even->next=even->next->next;

            odd=odd->next;
            even=even->next;
        }
        odd->next=evenHead;
        return head;
    }
    
};

//comp
//t.c-->o(n) s.c-->o(1)