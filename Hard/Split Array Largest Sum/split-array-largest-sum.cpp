//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int n, k;
    bool bin(int arr[], int x){
        int cnt=0, sum=0;
        for(int i=0; i<n;){
            int j=i+1;
            sum = arr[i];
            if (sum<=x){
                while(j<n and sum+arr[j]<=x) sum+=arr[j], j+=1; cnt++;
            }
            else return false;
            i=j;
        }
        if (cnt<=k) return true;
        return false;
    }
    int splitArray(int arr[] ,int n, int k) {
        this->n=n, this->k=k;
        int sum=0;
        for(int i=0; i<n; i++) sum+=arr[i];
        int hi=sum, lo=0, mid;
        while(hi-lo>1){
            mid=(hi+lo)/2;
            if (bin(arr, mid)) hi=mid;
            else lo=mid+1;
        }
        if (bin(arr, lo)) return lo;
        return hi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends