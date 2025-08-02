// GFG POTD - Longest Subarray with Majority Greater than K
// Date: 2025-08-02

#include <bits/stdc++.h>
using namespace std;

// ************************ Brute Force ************************
class BruteSolution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        int res = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int cnt = 0;
                for (int s = i; s <= j; s++) {
                    if (arr[s] > k) {
                        cnt++;
                    } else {
                        cnt--;
                    }
                }
                if (cnt > 0) {
                    res = max(res, j - i + 1);
                }
            }
        }
        return res;
    }
};

// ************************ Slightly Better ************************
class BetterSolution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        int res = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = i; j < n; j++) {
                if (arr[j] > k) {
                    cnt++;
                } else {
                    cnt--;
                }
                if (cnt > 0) {
                    res = max(res, j - i + 1);
                }
            }
        }
        return res;
    }
};

// ************************ Optimal Solution - Prefix Sum + HashMap ************************
class OptimalSolution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        int n = arr.size();
        int max_len = 0;
        int preSum = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;

        for (int i = 0; i < n; i++) {
            preSum += (arr[i] > k) ? 1 : -1;

            if (preSum > 0) {
                max_len = i + 1;
            }

            if (mp.count(preSum - 1)) {
                max_len = max(max_len, i - mp[preSum - 1]);
            }

            if (!mp.count(preSum)) {
                mp[preSum] = i;
            }
        }

        return max_len;
    }
};
