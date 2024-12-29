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


// Time Complexity Analysis
// Each recursive call processes one node in the linked list and performs constant work (updating pointers).
// The recursion continues until the curr pointer becomes NULL, which happens after visiting every node in the linked list.
// If there are n nodes in the list, the recursion will happen n times.
// Thus, the time complexity is O(n), where n is the number of nodes in the linked list.

// Space Complexity Analysis
// The space complexity comes from the recursive calls. In the worst case, where the linked list has n nodes, there will be n recursive calls on the stack (one for each node).
// Therefore, the space complexity is O(n) due to the recursion depth.
