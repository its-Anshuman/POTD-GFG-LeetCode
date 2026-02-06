class Solution:
    def minRemoval(self, nums: List[int], k: int) -> int:
        n = len(nums)
        i = j = 0
        nums.sort()
        mx = mn = nums[0]
        l = 1

        while j<n:
            mx = nums[j]
            mn = nums[i]

            while i<j and mx > k*mn:
                i += 1
                mn = nums[i]
            
            l = max(l,j-i+1)
            j += 1
        
        return n-l

        
