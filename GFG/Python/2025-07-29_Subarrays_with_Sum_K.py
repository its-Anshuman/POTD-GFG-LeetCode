# GFG POTD - Subarrays with Sum K
# Date: 2025-07-29

# ************************ Brute Force ************************
class BruteSolution:
    def countSubarrays(self, arr: List[int], k: int) -> int:
        n = len(arr)
        cnt = 0
        for i in range(n):
            for j in range(i, n):
                total = 0
                for s in range(i, j + 1):
                    total += arr[s]
                if total == k:
                    cnt += 1
        return cnt


# ************************ Better ************************
class BetterSolution:
    def countSubarrays(self, arr: List[int], k: int) -> int:
        n = len(arr)
        cnt = 0
        for i in range(n):
            total = 0
            for j in range(i, n):
                total += arr[j]
                if total == k:
                    cnt += 1
        return cnt


# ************************ Optimal_1 ************************
from collections import defaultdict
class OptimalSolution:
    def countSubarrays(self, arr: List[int], k: int) -> int:
        cnt = 0
        prefix_sum = 0
        mp = defaultdict(int)
        mp[0] = 1  # To count subarrays that directly sum to k

        for num in arr:
            prefix_sum += num
            if (prefix_sum - k) in mp:
                cnt += mp[prefix_sum - k]
            mp[prefix_sum] += 1
        return cnt

# ************************ Optimal_2 ************************


class OptimalSolution:
  def countSubarrays(self, arr, k):
        cnt = 0
        preSum = 0
        mp = {}
        mp = {0:1}
        for num in arr:
            preSum += num
            cnt += mp.get(preSum-k,0)
            mp[preSum] = mp.get(preSum, 0) + 1
        return cnt
