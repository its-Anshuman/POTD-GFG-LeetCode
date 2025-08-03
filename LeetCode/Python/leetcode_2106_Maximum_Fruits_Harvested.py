# LeetCode #2106 - Maximum Fruits Harvested After at Most K Steps
# Date: 2025-08-03

from bisect import bisect_left, bisect_right
from typing import List

class Solution:
    def maxTotalFruits(self, fruits: List[List[int]], startPos: int, k: int) -> int:
        n = len(fruits)

        indices = [0] * n
        preSum = [0] * n

        for i in range(n):
            indices[i] = fruits[i][0]
            preSum[i] = fruits[i][1] + (preSum[i - 1] if i > 0 else 0)

        maxfruits = 0

        for d in range((k // 2) + 1):
            i = startPos - d
            remain = k - 2 * d
            j = startPos + remain

            left = bisect_left(indices, i)
            right = bisect_right(indices, j) - 1

            if left <= right:
                total = preSum[right] - (preSum[left - 1] if left > 0 else 0)
                maxfruits = max(total, maxfruits)

            j = startPos + d
            i = startPos - remain

            left = bisect_left(indices, i)
            right = bisect_right(indices, j) - 1

            if left <= right:
                total = preSum[right] - (preSum[left - 1] if left > 0 else 0)
                maxfruits = max(total, maxfruits)

        return maxfruits
