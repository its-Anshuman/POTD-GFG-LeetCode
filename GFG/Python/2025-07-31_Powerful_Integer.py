# GFG POTD - Powerful Integer (Optimal Approach)
# Date: 2025-07-31

from typing import List

class Solution:
    def powerfulInteger(self, intervals: List[List[int]], k: int) -> int:
        # Step 1: Difference map to mark range starts and ends
        mp = {}
        for start, end in intervals:
            mp[start] = mp.get(start, 0) + 1
            mp[end + 1] = mp.get(end + 1, 0) - 1

        # Step 2: Apply sweep line prefix logic
        temp = 0
        result = -1
        for point in sorted(mp.keys()):
            # Before changing temp, check if we're ending a high-frequency range
            if mp[point] < 0 and temp >= k:
                result = point - 1

            temp += mp[point]

            # After applying change, check if we're entering a high-frequency range
            if temp >= k:
                result = point

        return result
