//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution {
  public:        // Code here
        vector<int> rearrange(const vector<int>& ans) {
        // Code here
        int n=ans.size();
        vector<int>arr(n);
        
    priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<n;i++)
        {
        if(ans[i]>-1){
            pq.push(ans[i]);
        }
        }
        for(int i=0;i<n;i++){
            
            if(i==pq.top()){
                arr[i]=pq.top();
                pq.pop();
            }
            else{
                arr[i]=-1;
            }
        }
        
        return arr;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> arr;
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution solution;
        vector<int> ans = solution.rearrange(arr);

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends