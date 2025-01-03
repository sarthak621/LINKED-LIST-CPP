/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:

    Node* connectNextPointer(Node* head){
        Node* temp=head;
        Node* dummyNode=new Node(-1);
        Node* res=dummyNode;
        
        while(temp!=NULL){
            res->next=temp->next;
            res=res->next;
            temp->next=temp->next->next;
            temp=temp->next;
        }
        return dummyNode->next;
    }

    void connectRandomPointer(Node* head){
        Node* temp=head;
        while(temp!=NULL){
            Node* copyNode=temp->next;
            if(temp->random){
                copyNode->random=temp->random->next;
            }
            else{
                copyNode->random=NULL;
            }
            temp=temp->next->next;
        }
    }

    void insertCopyInBetween(Node* head){
         Node* temp=head;
         while(temp!=NULL){
            
            Node* copyNode=new Node(temp->val);
            copyNode->next=temp->next;
            temp->next=copyNode;
            //new temp
            temp=copyNode->next;
         }
    }

    Node* copyRandomList(Node* head) {

        if(!head) return NULL;
        //step1: insert the copy nodes in b/w

        insertCopyInBetween(head);
        
         
         //step2:connect the random pointers
         connectRandomPointer(head);

         //step3:connect next pointers
        return connectNextPointer(head);
    }
};