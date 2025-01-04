//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        // Code Here
        int n = arr.size();
        int cnt = 0;

        for (int i = 0; i < n - 2; i++) {
            int low = i + 1, high = n - 1;
            while (low < high) {
                int sum = arr[i] + arr[low] + arr[high];
                if (sum == target) {
                    cnt++;
                
                    int tempLow = low + 1;
                    int tempHigh = high - 1;

                    while (tempLow < high && arr[tempLow] == arr[low]) {
                        cnt++;
                        tempLow++;
                    }
                    while (tempHigh > low && arr[tempHigh] == arr[high]) {
                        cnt++;
                        tempHigh--;
                    }

                    low++;
                    high--;
                }
                else if (sum < target) {
                    low++; 
                }
                else {
                    high--; 
                }
            }
        }

        return cnt;
    }
};

//{ Driver Code Starts.

vector<int> lineArray() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr = lineArray();
        int target;
        cin >> target;
        cin.ignore();

        Solution ob;
        int res = ob.countTriplets(arr, target);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends