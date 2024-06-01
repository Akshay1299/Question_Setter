//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string oddEven(string s) {
        // code here
        int sum=0;
        unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++) {
            mp[s[i]]++;
        }
        for(auto it:mp) {
            if(it.first%2==1 && it.second%2==1) {
                sum += 1;
            }
            else if(it.first%2==0 && it.second%2==0) {
                sum += 1;
            }
        }
        string ans="";
        if(sum%2==1) {
            ans += "ODD";
        }
        else if(sum%2==0) {
           ans += "EVEN";
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}

// } Driver Code Ends