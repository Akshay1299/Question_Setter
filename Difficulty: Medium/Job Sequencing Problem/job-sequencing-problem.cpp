//{ Driver Code Starts
// Driver code
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        vector<pair<int,int>> v;
        int n = deadline.size();
        int maxProfit = 0 , maxJobs = 0;
        for(int i = 0 ; i < n ; i ++)
            v.push_back({profit[i],deadline[i]});
        sort(v.begin(),v.end(),[](pair<int,int> &a, pair<int,int> &b){
            return a.first > b.first;
        });
        vector<int> hashArray(*max_element(deadline.begin(),deadline.end()) + 1,-1);
        
        for(int i = 0 ; i < n ; i++){
            int k = v[i].second;
            while(true){
                if(hashArray[k] == -1){
                    hashArray[k] = i;
                    maxProfit += v[i].first;
                    maxJobs++;
                    break;
                } else {
                    k--;
                    if(k == 0)
                        break;
                }
            }
        }
        
        return {maxJobs,maxProfit};
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> deadlines, profits;
        string temp;
        getline(cin, temp);
        int x;
        istringstream ss1(temp);
        while (ss1 >> x)
            deadlines.push_back(x);

        getline(cin, temp);
        istringstream ss2(temp);
        while (ss2 >> x)
            profits.push_back(x);

        Solution obj;
        vector<int> ans = obj.jobSequencing(deadlines, profits);
        cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends