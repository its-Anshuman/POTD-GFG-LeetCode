// GFG POTD - 2D Difference Array
// Date: 2025-08-03

#include <bits/stdc++.h>
using namespace std;

// ************************ Brute Force ************************
class Solution {
  public:
    vector<vector<int>> applyDiff2D(vector<vector<int>>& mat,
                                    vector<vector<int>>& opr) {
        // code here
        int r = mat.size();
        int c = mat[0].size();

        for (auto &o : opr) {
            int v = o[0];
            int r1 = o[1];
            int c1 = o[2];
            int r2 = o[3];
            int c2 = o[4];

            for (int i = r1; i <= r2; i++) {
                for (int j = c1; j <= c2; j++) {
                    mat[i][j] += v;
                }
            }
        }
        return mat;
    }
};

// ************************ Optimal Using 2D Difference Array ************************
class Solution {
  public:
    vector<vector<int>> applyDiff2D(vector<vector<int>>& mat,
                                    vector<vector<int>>& opr) {
        // code here
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> diff(n + 2, vector<int>(m + 2, 0));

        for (auto &o : opr) {
            int v = o[0];
            int r1 = o[1];
            int c1 = o[2];
            int r2 = o[3];
            int c2 = o[4];

            diff[r1][c1] += v;
            diff[r1][c2 + 1] -= v;
            diff[r2 + 1][c1] -= v;
            diff[r2 + 1][c2 + 1] += v;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i > 0) diff[i][j] += diff[i - 1][j];
                if (j > 0) diff[i][j] += diff[i][j - 1];
                if (i > 0 && j > 0) diff[i][j] -= diff[i - 1][j - 1];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mat[i][j] += diff[i][j];
            }
        }

        return mat;
    }
};
