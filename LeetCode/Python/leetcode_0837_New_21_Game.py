# LeetCode - 0837. New 21 Game
# Solution 1 (Brute Force DP)

class Solution:
    def new21Game(self, n: int, k: int, maxPts: int) -> float:
        prob = [0.0] * (n + 1)
        prob[0] = 1.0

        for i in range(1, n + 1):
            for card in range(1, maxPts + 1):
                if i - card >= 0 and i - card < k:
                    prob[i] += prob[i - card] / maxPts

        return sum(prob[k:n + 1])


# Solution 2 (Optimized Sliding Window DP)

class Solution:
    def new21Game(self, n: int, k: int, maxPts: int) -> float:
        if k == 0 or n >= k + maxPts:
            return 1.0

        prob = [0.0] * (n + 1)
        prob[0] = 1.0
        currProbSum = 1.0

        for i in range(1, n + 1):
            prob[i] = currProbSum / maxPts
            if i < k:
                currProbSum += prob[i]
            if i - maxPts >= 0 and i - maxPts < k:
                currProbSum -= prob[i - maxPts]

        return sum(prob[k:])
