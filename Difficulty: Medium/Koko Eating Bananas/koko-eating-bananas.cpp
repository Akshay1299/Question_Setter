class Solution {
  public:
    int kokoEat(vector<int>& a, int k) {
        // Code here
        int l = 1, r = *max_element(a.begin(), a.end());
        while (l < r) {
            int m = (l + r) / 2, hrs = 0;
            for (int n : a) hrs += (n + m - 1) / m;
            hrs <= k ? r = m : l = m + 1;
        }
        return l;
    }
};