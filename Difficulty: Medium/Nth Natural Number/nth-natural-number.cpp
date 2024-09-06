//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

#define ll long long
class Solution{
    public:
    ll cnt(ll val)
    {
        if(val < 1)
        {
            return 0; // No numbers less than 1.
        }
        
        string s = to_string(val);
        ll ans = 0;
        ll res = 1;
        vector<ll> dp(19, 0);
    
        // Precompute dp array for dynamic programming.
        for(int i = 0; i < s.size(); i++)
        {
            dp[i] = res;
            res *= 9;
        }
    
        // Count numbers with fewer digits.
        ans = dp[s.size() - 1];
        
        for(int i = 0; i < s.size(); i++)
        {
            ll rem = s.size() - 1 - i;
            ll d = s[i] - '0';
            ll adder = 0;
    
            if(i == 0)
            {
                adder += (d > 1 ? (d - 1) * dp[rem] : 0);
            }
            else
            {
                adder += (d > 0 ? d * dp[rem] : 0);
            }
    
            ans += adder;
            
            if(d == 9)
            {
                break;
            }
    
            if(i == s.size() - 1 && d < 9)
            {
                ans += 1;
            }
        }
    
        return ans-1;
    }
    long long findNth(long long N)
    {
        long long ans;
        ll l = 1;
        ll r = 1e13;
        while(l <= r)
        {
            ll mid = (l+r)/2;
            ll val = cnt(mid);
            if(val < N)
            {
                l = mid+1;
            }
            else
            {
                if(val == N)
                {
                    ans = mid;
                }
                r = mid-1;
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
        long long n, ans;
        cin >> n;
        Solution obj;
        ans = obj.findNth(n);
        cout << ans << endl;
    }
}

// } Driver Code Ends