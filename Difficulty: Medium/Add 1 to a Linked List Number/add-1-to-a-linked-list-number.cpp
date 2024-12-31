//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
  
    Node* reverse(Node* head){
        Node* prev=NULL;
        Node* curr=head;
        
        while(curr!=NULL){
            Node* newNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=newNode;
        }
        return prev;
    }
  
    Node* addOne(Node* head) {
        // Your Code here
        // return head of list after adding one
        
        //step1: reverse the head
        head= reverse(head);
        Node* temp=head;
        
        //step2 : add 1 to LL
        Node* dummyNode=new Node(-1);
        Node* curr=dummyNode;
        
        int carry=1;
        while(temp!=NULL){
            int sum=carry+temp->data;
            Node* newNode=new Node(sum%10);
            carry=sum/10;
            
            curr->next=newNode;
            curr=curr->next;
            
            temp=temp->next;
        }
        if(carry){
             Node* newNode=new Node(carry);
             curr->next=newNode;
        }
        Node* newHead= dummyNode->next;
        
        return reverse(newHead);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends