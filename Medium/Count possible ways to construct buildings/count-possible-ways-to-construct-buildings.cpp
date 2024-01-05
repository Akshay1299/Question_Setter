//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	 int M = 1000000007;
    
	public:
	int TotalWays (int n) {
	    long long a = 1, b = 1;
	    
	    for (int i = 1; i <= n; i++) {
	        long long cur = (a + b) % M;
	        a = b;
	        b = cur;
	    }
	    
	    return (b * b) % M;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends