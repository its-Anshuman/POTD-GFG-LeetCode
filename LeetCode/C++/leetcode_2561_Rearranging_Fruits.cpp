// LeetCode #2561 - Rearranging Fruits
// Date: 2025-08-02

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> mp;
        long long res = 0;
        vector<int> finalList;
        int minEl = INT_MAX;

        for (int &b1 : basket1) {
            mp[b1]++;
            minEl = min(minEl, b1);
        }

        for (int &b2 : basket2) {
            mp[b2]--;
            minEl = min(minEl, b2);
        }

        for (auto &it : mp) {
            int cost = it.first;
            int count = abs(it.second);

            if (cost == 0) {
                continue;
            }

            if (count % 2 != 0) {
                return -1;
            }

            for (int c = 1; c <= count / 2; c++) {
                finalList.push_back(cost);
            }
        }

        sort(finalList.begin(), finalList.end());

        for (int i = 0; i < finalList.size() / 2; i++) {
            res += min(finalList[i], minEl * 2);
        }

        return res;
    }
};
