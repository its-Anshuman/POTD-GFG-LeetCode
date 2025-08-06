// GFG - Roman Number to Integer
// Date: 2025-08-06

class Solution {
  public:
    int romanToDecimal(string &s) {
        // code here
        unordered_map<char, int> mp = {
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };
        
        int n = s.length();
        int res = 0;
        
        for (int i = 0; i < n; i++) {
            if (i + 1 < n && mp[s[i]] < mp[s[i + 1]]) {
                res -= mp[s[i]];
            } else {
                res += mp[s[i]];
            }
        }
        
        return res;
    }
};
