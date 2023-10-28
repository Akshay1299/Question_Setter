//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
	int is_bleak(int n)
	{
	    // Code here.
	    int flag=0;
        //int p=n-ceil(log(n));
        int i=n-ceil(log2(n))-1;
        while(i<=n)
        {
            if((i+(__builtin_popcount(i)))==n)
            {
                flag=1;
                break;
            }
            i++;
        }
        if(flag)
        return 0;
        else
        return 1;
	}
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	Solution ob;
    	int ans = ob.is_bleak(n);
    	cout << ans << "\n";
    }
	return 0;
}

// } Driver Code Ends