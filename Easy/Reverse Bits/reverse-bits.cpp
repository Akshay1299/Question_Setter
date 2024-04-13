//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long reversedBits(long long x) {
        // code here
        x = (unsigned) x;
        int size = sizeof(int)*8 - 1;
        unsigned res = 0;
        
        for(int i = 0 ; size != -1 ; i++){
            int bit = x & 1 ;
            unsigned num = bit * pow( 2, size);
            res = res | num ; 
            // cout << num << endl;
            x >>=1  ;
            size -= 1 ;
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends