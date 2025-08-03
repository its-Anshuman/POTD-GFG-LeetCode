// LeetCode #2106 - Maximum Fruits Harvested After at Most K Steps
// Date: 2025-08-03

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        vector<int> indices(n);
        vector<int> preSum(n);

        for (int i = 0; i < n; i++) {
            indices[i] = fruits[i][0];
            preSum[i] = fruits[i][1] + (i > 0 ? preSum[i - 1] : 0);
        }

        int maxfruits = 0;

        for (int d = 0; d <= k / 2; d++) {
            int i = startPos - d;
            int remain = k - 2 * d;
            int j = startPos + remain;

            int left = lower_bound(indices.begin(), indices.end(), i) - indices.begin();
            int right = upper_bound(indices.begin(), indices.end(), j) - indices.begin() - 1;

            if (left <= right) {
                int total = preSum[right] - (left > 0 ? preSum[left - 1] : 0);
                maxfruits = max(maxfruits, total);
            }

            j = startPos + d;
            i = startPos - (k - 2 * d);

            left = lower_bound(indices.begin(), indices.end(), i) - indices.begin();
            right = upper_bound(indices.begin(), indices.end(), j) - indices.begin() - 1;

            if (left <= right) {
                int total = preSum[right] - (left > 0 ? preSum[left - 1] : 0);
                maxfruits = max(maxfruits, total);
            }
        }

        return maxfruits;
    }
};
