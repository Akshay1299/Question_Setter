class Solution {
  public:
    int maxSum(vector<int> &arr) {
        // code here
        int maxsum=0;
        for(int i=0;i<arr.size()-1;i++){
            maxsum=max(maxsum,arr[i]+arr[i+1]);
        }
        return maxsum;
    }
};