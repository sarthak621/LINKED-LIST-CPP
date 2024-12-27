//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* next;

    // Default constructor
    Node() {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};


// } Driver Code Ends
// User function Template for C++

/*class Node {
public:
    int data;
    Node* next;

    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};*/

class Solution {
  public:
  
   void printLL(Node* head){
       Node* temp=head;
       while(temp!=NULL){
           cout<<temp->data<<" ";
           temp=temp->next;
       }
   }
  
    Node* convertToLL(vector<int>& arr){
        Node* head=new Node(arr[0]);
        Node* mover=head;
        
        //traversing further
        for(int i=1;i<arr.size();i++){
            Node* temp=new Node(arr[i]);
            mover->next=temp;
            mover=temp;
        }
        
        printLL(head);
        return head;
        
    }
  
    Node* constructLL(vector<int>& arr) {
        // code here
        Node* head=convertToLL(arr);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        Node* ans = ob.constructLL(arr);
        while (ans) {
            cout << ans->data << " ";
            ans = ans->next;
        }
        cout << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends