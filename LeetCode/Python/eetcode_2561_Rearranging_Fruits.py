# LeetCode #2561 - Rearranging Fruits
# Date: 2025-08-02

from collections import Counter
from typing import List

class Solution:
    def minCost(self, basket1: List[int], basket2: List[int]) -> int:
        mp = Counter()
        minEl = float('inf')

        for x in basket1:
            mp[x] += 1
            minEl = min(minEl, x)

        for x in basket2:
            mp[x] -= 1
            minEl = min(minEl, x)
        
        finalList = []

        for x in mp:
            count = abs(mp[x])

            if count % 2 != 0:
                return -1

            finalList.extend([x] * (count // 2))

        finalList.sort()
        res = 0

        for i in range(len(finalList) // 2):
            res += min(finalList[i], minEl * 2)
        
        return res
