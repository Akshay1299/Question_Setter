//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool dfs(int i, int p, vector<vector<int>>&ed, vector<bool>&vis){
        if(vis[i] == true) return true;
        
        vis[i] = true;
        bool ok = false;
        for(int j : ed[i]){
            if(j == p) continue;
            
            ok = ok | dfs(j, i, ed, vis);
        }
        return ok;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<bool>vis(V, false);
        for(int i = 0; i < V; i++){
            if(vis[i] == true) continue;
            
            if(dfs(i,-1, edges, vis)) return true;
        }
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCycle(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends