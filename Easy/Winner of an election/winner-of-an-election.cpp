//{ Driver Code Starts
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        // Your code here
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
        int  maxi=0;
        vector<string> v;
         unordered_map<string,int>map;
        
        for(int i=0; i<n; i++){
            map[arr[i]]++;
            if(map[arr[i]]>=maxi){
                maxi=map[arr[i]];
            }
        }
      for (auto i = map.begin(); i != map.end(); i++){
           if(i->second == maxi){
               v.push_back(i->first);
            }
        }
        sort(v.begin(),v.end());
        
        
        return {v[0],to_string(maxi)};
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr,n);
        
        cout<<result[0] << " " << result[1] << endl;
    }
    return 0;
}

// } Driver Code Ends