//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int nCr(int n, int r) {
        // code here
        if(n<r)
            return 0;
        if(r==0 || r==n)
            return 1;
        if (r > n - r) r = n - r;//this line is optional

    int result = 1;
    for (int i = 1; i <= r; i++) {
        result = (int)(1LL*result * (n - r + i) / i);
    }
    return result;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, r;
        cin >> n >> r;

        Solution ob;
        cout << ob.nCr(n, r) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends