//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int isValid(string str) {
        // code here
        int n=str.size(),dotcnt=0;
        if(str[0]=='.' || str[0]=='0'){
            return false;
        }
        for(int i=0;i<n;i++){
            if(str[i]=='.') dotcnt++;
        }
        if(dotcnt!=3){
            return false;
        }
        int j=n-1;
        for(int i=3;i>=0;i--){
            int cnt=0,ans=0;
            
            while(str[j]!='.' && j>=0){
                int d=str[j--]-'0';
                ans+=d*pow(10,cnt);
                cnt++;
                if(j!=0 && str[j-1]=='.' && str[j]==0){
                    return false;
                }
            }
            if(ans>255 || cnt==0){
                return false;
            }
            j--;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends