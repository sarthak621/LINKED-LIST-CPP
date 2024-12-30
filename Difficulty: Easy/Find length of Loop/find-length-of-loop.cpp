//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void loopHere(Node *head, Node *tail, int position) {
    if (position == 0)
        return;

    Node *walk = head;
    for (int i = 1; i < position; i++)
        walk = walk->next;
    tail->next = walk;
}


// } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        
        //approach....
        // step1:find loop present or not
        // step 2:find the starting point 
        // step 3 : mark staring point as slow and move fast till fast->next!=starting point 
        // also increase count in each iteration
        
        Node* fast=head;
        Node* slow=head;
        
        //finding whether there is loop or not
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
        if(fast==NULL){
            return NULL;
        }
        
        // now find the starting point 
        slow=head;
        while(fast!=slow){
            fast=fast->next;
            slow=slow->next;
        }
        
        Node* SP=slow;  //sp=starting point
        int count=1;
        while(fast->next!=SP){
            fast=fast->next;
            count++;
        }
        return count;
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
        int k;
        cin >> k;
        cin.ignore();
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        loopHere(head, tail, k);

        Solution ob;
        cout << ob.countNodesinLoop(head) << endl;
    }
    return 0;
}

// } Driver Code Ends