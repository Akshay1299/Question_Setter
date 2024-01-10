//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	    vector<int>dp;
       dp.push_back(0);
       for(int i=0;i<n;++i){
           int ele = (dp.back() + arr[i])%k;
           dp.push_back(ele);
       }
       unordered_map<int,int>um;
       for(int i=0;i<=n;++i){
           um[dp[i]]=i;
       }
       int ans = 0;
       for(int i=1;i<n;++i){
           int prev = dp[i-1];
           if(um.find(prev)!=um.end()) ans = max(ans,um[prev]-i+1);
           prev = dp[i-1]+k;
           if(um.find(prev)!=um.end()) ans = max(ans,um[prev]-i+1);
           prev = dp[i-1]-k;
           if(um.find(prev)!=um.end()) ans = max(ans,um[prev]-i+1);
       }
       return ans;
	}
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}

// } Driver Code Ends