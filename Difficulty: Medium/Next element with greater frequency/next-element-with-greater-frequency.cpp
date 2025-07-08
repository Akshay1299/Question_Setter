class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> ans(n,-1);
        
        unordered_map<int,int> mp;
        for(int x : arr) {
            mp[x]++;
        }
        
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            if(!st.empty()){
                while(!st.empty() && mp[st.top()]<=mp[arr[i]]){
                    st.pop();
                }
                if(!st.empty()){
                    ans[i]=st.top();
                }
            }
            st.push(arr[i]);
        }
        return ans;
    }
};
