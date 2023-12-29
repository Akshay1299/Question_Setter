//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int kSubstrConcat (int n, string s, int k)
	{
	    // Your Code Here
	     if(n%k!=0) return 0;
       map<string,int>mp;
       string temp="";
       for(int i=0;i<n;i++){
           temp+=s[i];
           if((i+1)%k==0){
               mp[temp]++;
               temp="";
             
           }
       }
       if(mp.size()==1) return 1;
       else if(mp.size()==2){
           bool flag=0;
           for(auto it:mp){
               if(it.second==1){
                   flag=1;
               }
           }
           if(flag) return 1;
           return 0;
       }
       return 0;
	}
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		int k; cin >> k;
        Solution  ob;
		cout << ob.kSubstrConcat (n, s, k) << endl;
	}
}
// } Driver Code Ends