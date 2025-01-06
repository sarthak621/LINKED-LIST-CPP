//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
  
  
   int get(int num, int i){
       if((num>>i & 1)!=0){
           return 1;
       }
       return 0;
   }
  
   int set(int num, int i){
       return (num | 1<<i);
   }
   
   int clear(int num, int i){
       return (num & ~(1<<i));
   }
  
    void bitManipulation(int num, int i) {
        int ans1= get(num,i-1);
        int ans2= set(num,i-1);
        int ans3= clear(num,i-1);
        
        cout<<ans1<<" "<<ans2<<" "<<ans3;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n >> i;
        Solution ob;
        ob.bitManipulation(n, i);
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends