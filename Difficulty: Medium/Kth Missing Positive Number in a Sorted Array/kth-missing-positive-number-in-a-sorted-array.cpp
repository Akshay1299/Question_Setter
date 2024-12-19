//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        // Your code goes here
        vector<int> v;
        int n= arr.size();


        int j=0;
        int i=1;
        for(;i<=arr[n-1];i++){
            while(arr[j]<i){
                v.push_back(i);
                i++;
            }
            if(arr[j]!=i){
                v.push_back(i);
            }
            else{
                j++;
            }
        }
        if(v.size()<k){
            int x = k;
            while(x--){
                v.push_back(i);
                i++;
            }
        }
        return v[k-1];
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.kthMissing(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends