# GFG POTD - Longest Subarray with Majority Greater than K
# Date: 2025-08-02

# ************************ Brute Force ************************
class Solution:
    def longestSubarray(self, arr, k):
        # Code Here
        n = len(arr)
        res = 0

        for i in range(n):
            for j in range(i, n):
                cnt = 0
                for s in range(i, j + 1):
                    if arr[s] > k:
                        cnt += 1
                    else:
                        cnt -= 1
                if cnt > 0:
                    res = max(res, j - i + 1)

        return res


# ************************ Better ************************
class Solution:
    def longestSubarray(self, arr, k):
        # Code Here
        n = len(arr)
        res = 0

        for i in range(n):
            cnt = 0
            for j in range(i, n):
                if arr[j] > k:
                    cnt += 1
                else:
                    cnt -= 1
                if cnt > 0:
                    res = max(res, j - i + 1)

        return res


# ************************ Optimal ************************
class Solution:
    def longestSubarray(self, arr, k):
        # Code Here
        n = len(arr)
        max_len = 0
        mp = {0: -1}
        preSum = 0

        for i in range(n):
            preSum += 1 if arr[i] > k else -1

            if preSum > 0:
                max_len = i + 1

            if preSum - 1 in mp:
                max_len = max(max_len, i - mp[preSum - 1])

            if preSum not in mp:
                mp[preSum] = i

        return max_len
