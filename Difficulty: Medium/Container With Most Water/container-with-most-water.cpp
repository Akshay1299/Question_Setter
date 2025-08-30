class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n=arr.size();
        int i=0, j=n-1, ans=0;
        while(i!=j){
            int base=0;
            if(arr[i] >= arr[j]){
                base=j-i;
                ans=max(ans, arr[j]*base);
                j--;
            }
            else{
                base=j-i;
                ans=max(ans, arr[i]*base);
                i++;
            }
        }
        return ans;
    }
};