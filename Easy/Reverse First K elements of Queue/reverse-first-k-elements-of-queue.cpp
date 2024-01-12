//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        // add code here.
           vector<int> v;
        queue<int> qn;
        int i = 0;
        while(!q.empty() && i<k) {
            v.push_back(q.front());
            q.pop();
            i++;
        }
        
        reverse(v.begin(), v.end());
        for(int j = 0; j<k; j++){
            qn.push(v[j]);
        }
        while (!q.empty()) {
            qn.push(q.front()); 
            q.pop(); 
        }
        
        return qn;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        Solution ob;
        queue<int> ans = ob.modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends