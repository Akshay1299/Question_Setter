//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> modifyAndRearrangeArray(vector<int> &arr) {
        // Complete the function
        int i=0;
        vector<int>ans(arr.size());
        int s = 0;
        int cnt = 0;
        
        while(i < arr.size()-1)
        {
            if(arr[i] == arr[i+1])
            {
                ans[s++] = arr[i]*2;
                cnt++;
                i++;
            }
            else
            {
                if(arr[i] == 0)
                {
                    cnt++;
                }
                else
                {
                    ans[s++] = arr[i];
                }
            }
            i++;
        }
        
        if(i < arr.size() && arr[i] != 0)
        {
            ans[s++] = arr[i];
        }
        
        int j = 0;
        while(j < cnt)
        {
            ans[s++] = 0;
            j++;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> ans = obj.modifyAndRearrangeArray(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends