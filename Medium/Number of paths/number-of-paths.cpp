//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution
{
    public:
    long long  numberOfPaths(int M, int N)
    {
        // Code Here
           const int mod = 1000000007;

        int n = M + N - 2;
        int r = M - 1;
        long long ans = 1;  // Use long long to prevent integer overflow

        // Calculate (n choose r) % mod
        for (int i = 1; i <= r; i++) {
            ans = (ans * (n - i + 1)) % mod;
            ans = (ans * modInverse(i, mod)) % mod;
        }

        return (ans);
    }
private:
    long long modInverse(long long a, int m) {
        return modPow(a, m - 2, m);
    }

    long long modPow(long long base, int exp, int mod) {
        long long result = 1;

        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }

        return result;
    }
};


//{ Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int N, M;
		cin>>M>>N;
		Solution ob;
	    cout << ob.numberOfPaths(M, N)<<endl;
	}
    return 0;
}
// } Driver Code Ends