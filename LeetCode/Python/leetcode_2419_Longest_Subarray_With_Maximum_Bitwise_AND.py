# LeetCode POTD - 2419_Longest Subarray With Maximum Bitwise AND
# Date: 2025-07-30

class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        maxi = max(nums)
        res = 1
        curr_len = 0

        for num in nums:
            if num == maxi:
                curr_len += 1
            else:
                res = max(res, curr_len)
                curr_len = 0

        res = max(res, curr_len)
        return res
        
    
