class Solution {
  public:
    string addStr(const string &a, const string &b) {
        string res;
        int i = a.size() - 1, j = b.size() - 1, carry = 0;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            res = char(sum % 10 + '0') + res;
            carry = sum / 10;
        }
        return res;
    }

    bool check(const string &s, int start, string a, string b) {
        while (start < s.size()) {
            string sum = addStr(a, b);
            if (s.substr(start, sum.size()) != sum) return false;
            start += sum.size();
            a = b;
            b = sum;
        }
        return true;
    }

    int isSumString(string &s) {
        int n = s.size();
        for (int i = 1; i < n; ++i) {
            string a = s.substr(0, i);
            if (a.size() > 1 && a[0] == '0') continue;
            for (int j = i + 1; j < n; ++j) {
                string b = s.substr(i, j - i);
                if (b.size() > 1 && b[0] == '0') continue;
                if (check(s, j, a, b)) return 1;
            }
        }
        return 0;
    }
};