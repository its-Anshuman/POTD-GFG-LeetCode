// LeetCode #118 - Pascal's Triangle
// Date: 2025-08-01

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pasTr;

        for (int i = 0; i < numRows; i++) {
            vector<int> curr(i + 1, 1);

            for (int j = 1; j < i; j++) {
                curr[j] = pasTr[i - 1][j - 1] + pasTr[i - 1][j];
            }

            pasTr.push_back(curr);
        }

        return pasTr;
    }
};
