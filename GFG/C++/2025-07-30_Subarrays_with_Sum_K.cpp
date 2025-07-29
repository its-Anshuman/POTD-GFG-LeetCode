// GFG POTD - Subarrays with Sum K
// Date: 2025-07-30

#include <bits/stdc++.h>
using namespace std;

// ************************ Brute Force ************************
class BruteSolution {
  public:
    int countSubarrays(vector<int> &arr, int k) {
        int n  = arr.size(), cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                int sum = 0;
                for(int s = i; s <= j; s++) {
                    sum += arr[s];
                }
                if(sum == k) cnt++;
            }
        }
        return cnt;
    }
};

// ************************ Better ************************
class BetterSolution {
  public:
    int countSubarrays(vector<int> &arr, int k) {
        int n = arr.size(), cnt = 0;
        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = i; j < n; j++) {
                sum += arr[j];
                if(sum == k) cnt++;
            }
        }
        return cnt;
    }
};

// ************************ Optimal ************************
class OptimalSolution {
  public:
    int countSubarrays(vector<int> &arr, int k) {
        int n = arr.size(), cnt = 0;
        unordered_map<int, int> mp;
        int preSum = 0;
        mp[0] = 1;
        for(int i = 0; i < n; i++) {
            preSum += arr[i];
            if(mp.find(preSum - k) != mp.end()) {
                cnt += mp[preSum - k];
            }
            mp[preSum]++;
        }
        return cnt;
    }
};
