// LeetCode #898 - Bitwise ORs of Subarrays
// Date: 2025-07-31

#include <bits/stdc++.h>
using namespace std;

// ************************ Brute Force ************************
class BruteSolution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        set<int> s;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int curr = arr[i];
                for (int k = i; k <= j; k++) {
                    curr |= arr[k];
                }
                s.insert(curr);
            }
        }
        return s.size();
    }
};

// ************************ Better ************************
class BetterSolution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        set<int> s;
        for (int i = 0; i < n; i++) {
            int curr = 0;
            for (int j = i; j < n; j++) {
                curr |= arr[j];
                s.insert(curr);
            }
        }
        return s.size();
    }
};

// ************************ Optimal ************************
class OptimalSolution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> prev, curr, res;

        for (int i = 0; i < n; i++) {
            curr.clear();
            for (auto &x : prev) {
                curr.insert(arr[i] | x);
                res.insert(arr[i] | x);
            }
            curr.insert(arr[i]);
            res.insert(arr[i]);
            prev = curr;
            curr.clear();
        }

        return res.size();
    }
};
