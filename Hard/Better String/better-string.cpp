//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int disSubseq(string &s){
        long endsWith[26] = {};
        for (char c : s)
            endsWith[c - 'a'] = accumulate(begin(endsWith), end(endsWith), 1L);
        return accumulate(begin(endsWith), end(endsWith), 0L) + 1;
    }
    string betterString(string str1, string str2) {
        int l1 = disSubseq(str1);
        int l2 = disSubseq(str2);
        
        return (l1 > l2 ? str1 : (l1 == l2 ? str1 : str2));
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        Solution obj;
        string ans = obj.betterString(str1, str2);
        cout << ans << "\n";
    }
}

// } Driver Code Ends