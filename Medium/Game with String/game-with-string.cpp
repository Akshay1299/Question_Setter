//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s1, int k){
        // code here
         int s=s1.length();
       
        unordered_map<char, int> m; 
      
        priority_queue<int> q;
        int ans=0;
        for(int i=0; i<s; i++){
            m[s1[i]]++;
        }
        for(auto i:m){
            q.push(i.second);
        }
        while(k>0){
            int x=q.top();
            x=x-1;
            q.pop();
            q.push(x);
            k--;
        }
        while(!q.empty()){
              int x=q.top();
              x=x*x;
              ans=ans+x;
              q.pop();
              
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends