//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        // Your code goes here
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int i = 0 , j = 1 , k = n-1;
        int nearest = INT_MAX ;
        while(i<k){
            if(j>=k){
                i++;
                j = i+1;
                k=n-1;
                continue;
            }
            int p = arr[i]+arr[j]+arr[k] ;
            if(p==target)return target ;
            else if(p>target)k--;
            else j++;
            if(abs(target-p)<abs(target-nearest) || ((abs(target - p) == abs(target-nearest)) && p > target))nearest = p ;
        }
        return nearest ;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        // cin.ignore();
        // if (f)
        //     return 0;
        Solution ob;
        cout << ob.threeSumClosest(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends