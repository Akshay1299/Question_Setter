//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    string removeDups(string str) {
        // Your code goes here
        string ans;
      map<char ,int>v;
      for(int i=0;i<str.length();i++)
      {
         char ch=str[i];
         v[ch]++;
        
      }
      for(int i=0;i<str.length();i++)
      {
          char ch=str[i];
          if(v[ch]>1)
          {
              ans.push_back(ch);
              v[ch]=0;
          }
          else if(v[ch]==1)
          {
              ans.push_back(ch);
          }
         
      }
      return ans;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.removeDups(s) << "\n";
    }

    return 0;
}
// } Driver Code Ends