//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
     static bool compare(const string &a, const string &b) {
        return (a + b) > (b + a);
    }
    string printLargest(int n, vector<string> &arr) {
        // code here
        sort(arr.begin(), arr.end(), compare);
        string result;
        for (int i = 0; i < n; ++i) {
            result += arr[i];
        }
        while (result[0] == '0' && result.length() > 1) {
            result.erase(0, 1);
        }
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<string> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printLargest(n, arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends