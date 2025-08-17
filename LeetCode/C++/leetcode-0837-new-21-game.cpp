// LeetCode - 0837. New 21 Game
// Solution 1 (Brute Force DP)

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> prob(n + 1, 0.0);
        prob[0] = 1.0;

        for (int i = 1; i <= n; i++) {
            for (int card = 1; card <= maxPts; card++) {
                if (i - card >= 0 && i - card < k) {
                    prob[i] += prob[i - card] / maxPts;
                }
            }
        }

        double ans = 0.0;
        for (int i = k; i <= n; i++) {
            ans += prob[i];
        }
        return ans;
    }
};


// Solution 2 (Optimized Sliding Window DP)

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0 || n >= k + maxPts) return 1.0;

        vector<double> prob(n + 1, 0.0);
        prob[0] = 1.0;
        double currProbSum = 1.0;

        for (int i = 1; i <= n; i++) {
            prob[i] = currProbSum / maxPts;
            if (i < k) {
                currProbSum += prob[i];
            }
            if (i - maxPts >= 0 && i - maxPts < k) {
                currProbSum -= prob[i - maxPts];
            }
        }

        double ans = 0.0;
        for (int i = k; i <= n; i++) {
            ans += prob[i];
        }
        return ans;
    }
};
