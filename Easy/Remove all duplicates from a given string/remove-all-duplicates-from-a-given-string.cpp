//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	string removeDuplicates(string str) {
	    // code here
	    string ans="";
        vector<int>c(26,0);
       vector<int> l(26,0);
       for(int i=0;i<str.size();i++)
       {
          if(isupper(str[i]))
          {
              if(c[str[i]-'A']==0)
              {
                  ans+=str[i];
                  c[str[i]-'A']++;
              }
          }
          else
          {
               if(l[str[i]-'a']==0)
              {
                  ans+=str[i];
                  l[str[i]-'a']++;
              }
          }
       }
        return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends