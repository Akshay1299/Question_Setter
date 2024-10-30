//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    /* Returns count of pairs with difference k  */
    int countPairsWithDiffK(vector<int>& arr, int k) {
        // code here
        unordered_map<int,int>umap;
        
        //counting frequency        
        for(int i = 0; i < arr.size(); i++){
        	umap[arr[i]]++;
		}
		
		// variable to store ans
		int total = 0;
		
		//checking if k + arr[i] element exists in array
		for(int i = 0; i  < arr.size(); i++){
			
			//main condition 
		    if(umap.count(k+arr[i])){
		            //adding frequency to total
					total += umap[k+arr[i]];
			}
			
		}
		
		return total;
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        auto ans = ob.countPairsWithDiffK(arr, k);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends