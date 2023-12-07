//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    long countSubarrays(int a[], int n, int L, int R)
    {
        // Complete the function
        int p=0;
       long long ans=0;
       int indx=-1;
       for(int i=0;i<n;i++)
       {
           if(a[i]>R)
           {
             p=i+1;  
             indx=-1;
             continue;
           }
           else if(a[i]<=R&&a[i]>=L)
           {
               indx=i;
           }
          
          if(indx!=-1)
              ans+=indx-p+1;
       }
        return ans;
        
    }
};

//{ Driver Code Starts.
// driver program
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        
        int n ,l,r;
        cin >> n>>l>>r;
        int a[n];
        for(int i=0;i<n;i++)
        cin >> a[i];
        Solution ob;
    	cout << ob.countSubarrays(a, n, l, r)<<endl;
    }
	return 0;
}

// } Driver Code Ends