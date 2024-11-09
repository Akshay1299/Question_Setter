//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    string minSum(vector<int> &arr) {
        // code here
        vector<int> first,second,ans;
        sort(arr.begin(), arr.end());
        int n=arr.size();
        for (int i=0; i<n; i++){
            if (i & 1){
                second.push_back(arr[i]);
            }
            else{
                first.push_back(arr[i]);
            }
        }
        int l1 = first.size(), l2 = second.size();
        
        int carry = 0;
        
        int i = first.size()-1, j = second.size()-1;
        while (i >= 0 && j >= 0){
            int curr_t = first[i]+second[j] + carry;
            carry = curr_t > 9 ? 1 : 0;
            ans.push_back(carry ? curr_t-10 : curr_t);
            i--;
            j--;
        }
        string rst = "";
        
        auto concat = [](vector<int>& ans){
            string curr = "";
            for (int i=ans.size()-1; i>=0; i--) curr += to_string(ans[i]);
            return curr;
        };
        
        if (l1 == l2){
            rst = concat(ans);
            if (carry) rst = "1" + rst;
        }
        else{
            rst = concat(ans);
            if (carry) {
                first[0] += carry;
                if (first[0] > 9){
                    first[0]-= 10;
                    rst = "1" + to_string(first[0]) + rst;
                }
                else{
                    rst = to_string(first[0]) + rst;
                }

            }
            else{
                rst = to_string(first[0]) + rst;
            }
        }
        
        for (int i=0; i<rst.size(); i++) {
            if (rst[i] == '0') continue;
            
            return rst.substr(i);
        }
        
        return "-1";
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends