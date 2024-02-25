//{ Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// } Driver Code Ends

class Solution
{
    int ans=0;
    public:
    // Complete this function
    long long int count(long long int n)
    {
    	vector<int >dp(n+1);
    	dp[0]=1;
    	for(auto x:{3,5,10}) 
            for(int i=x;i<=n;i++)dp[i]+=dp[i-x];
        return dp[n];
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		Solution obj;
		cout<<obj.count(n)<<endl;
	}
	return 0;
}
// } Driver Code Ends