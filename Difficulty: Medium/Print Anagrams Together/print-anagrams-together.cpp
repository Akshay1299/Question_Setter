//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        // code here
        vector<pair<string,int>>v;
        int n = arr.size();
        for(int i=0;i<n;i++){
            string st = arr[i];
            sort(st.begin(),st.end());
            v.push_back({st,i});
        }
        sort(v.begin(),v.end());
        int i=0;
        vector<vector<string>>ans;
        while(i<n){
            vector<string>group;
            group.push_back(arr[v[i].second]);
            i++;
            while(i<n && v[i].first==v[i-1].first){
                group.push_back(arr[v[i].second]);
                i++;
            }
            ans.push_back(group);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<string> arr;
        string input_line;
        getline(cin, input_line);
        stringstream ss(input_line);
        string word;
        while (ss >> word) {
            arr.push_back(word);
        }

        Solution ob;
        vector<vector<string> > result = ob.anagrams(arr);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result[i].size(); j++) {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends