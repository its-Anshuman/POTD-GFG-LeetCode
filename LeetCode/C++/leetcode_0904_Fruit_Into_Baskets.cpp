// LeetCode #904 - Fruit Into Baskets
// Date: 2025-08-04

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int> mp;
        int i = 0, j = 0, res = 0;

        while (j < n) {
            mp[fruits[j]]++;

            if (mp.size() <= 2) {
                res = max(res, j - i + 1);
            } else {
                mp[fruits[i]]--;
                if (mp[fruits[i]] == 0) {
                    mp.erase(fruits[i]);
                }
                i++;
            }
            j++;
        }

        return res;
    }
};
