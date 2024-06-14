//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<vector<long long>>dp;
    long long solve(unordered_map<int,vector<int>>&mp,int n,int k){
        if(n==1)return 1;
        if(dp[n][k]!=-1)return dp[n][k];
        long long ans=0;
        for(auto ele:mp[k]){
            ans+=(solve(mp,n-1,ele));
        }
        return dp[n][k]=ans;
    }
    long long getCount(int n) {
        // Your code goes here
        unordered_map<int,vector<int>>mp;
        mp[1]={1,2,4};
        mp[2]={1,2,3,5};
        mp[3]={3,2,6};
        mp[4]={1,5,4,7};
        mp[5]={2,4,5,6,8};
        mp[6]={3,5,6,9};
        mp[7]={4,7,8};
        mp[8]={0,7,5,8,9};
        mp[9]={6,8,9};
        mp[0]={0,8};
        dp=vector<vector<long long>>(n+1,vector<long long>(10,-1));
        long long ans=0;
        for(int i=0;i<10;i++)ans+=solve(mp,n,i);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends