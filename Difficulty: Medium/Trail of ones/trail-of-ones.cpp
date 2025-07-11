class Solution {
  public:
    int countConsec(int n) {
        // code here
        int dp[n+1];

        dp[1] = 0;
        dp[2] = 1;
        dp[3] = 3;

        for(int i = 4; i<=n; i++){
            dp[i] = dp[i-1] * 2 + pow(2, i-3) - dp[i-3];
        }

        return dp[n];
    }
};