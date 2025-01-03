//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

void printList(Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
    printf("\n");
}


// } Driver Code Ends
/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  public:
    
    //merging logic
    Node* merge(Node *list1,Node* list2){
        Node* dummyNode=new Node(-1);
        Node* res=dummyNode;
        
        while(list1!=NULL && list2!=NULL){
            if(list1->data<list2->data){
                    res->bottom=list1;
                    res=list1;
                    list1=list1->bottom;
            }
            else{
                    res->bottom=list2;
                    res=list2;
                    list2=list2->bottom;
            }
            res->next=NULL;
        }
        
        if(list1) res->bottom=list1;
        else res->bottom=list2;
        
        return dummyNode->bottom;
    }
    
    
    Node *flatten(Node *root) {
        if(root==NULL || root->next==NULL) return root;
        
        Node* mergedHead=flatten(root->next);
        return merge(root,mergedHead);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        vector<int> work;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            work.push_back(number);
        }
        n = work.size();

        Node *head = NULL;
        Node *pre = NULL;

        for (int i = 0; i < n; i++) {
            int m = work[i] - 1;
            int data;
            cin >> data;
            Node *temp = new Node(data);
            if (head == NULL) {
                head = temp;
                pre = temp;
            } else {
                pre->next = temp;
                pre = temp;
            }

            Node *preB = temp;
            for (int j = 0; j < m; j++) {
                int temp_data;
                cin >> temp_data;
                Node *tempB = new Node(temp_data);
                preB->bottom = tempB;
                preB = tempB;
            }
        }

        Solution ob;
        Node *root = ob.flatten(head);
        printList(root);
    }
    return 0;
}

// } Driver Code Ends