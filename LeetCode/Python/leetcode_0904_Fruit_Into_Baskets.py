# LeetCode #904 - Fruit Into Baskets
# Date: 2025-08-04

from collections import defaultdict
from typing import List

class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        n = len(fruits)
        mp = defaultdict(int)
        i = 0
        j = 0
        res = 0

        while j < n:
            mp[fruits[j]] += 1

            if len(mp) <= 2:
                res = max(res, j - i + 1)
            else:
                mp[fruits[i]] -= 1
                if mp[fruits[i]] == 0:
                    del mp[fruits[i]]
                i += 1
            j += 1

        return res
