//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
     int f(int n,int m,int i,int j,vector<vector<int>>&M,vector<vector<int>>&dp){
        if(i<0 || i==n || j<0 || j==m){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int northEast=M[i][j]+f(n,m,i-1,j+1,M,dp); // Go up and right 
        int east=M[i][j]+f(n,m,i,j+1,M,dp);  //Go right
        int southEast=M[i][j]+f(n,m,i+1,j+1,M,dp);  //Go down and right
        dp[i][j]=max(northEast,max(east,southEast));
        return dp[i][j];
    }
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        int maxValue=0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            maxValue=max(maxValue,f(n,m,i,0,M,dp));//Update max value for each start value.
        }
        return maxValue;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends