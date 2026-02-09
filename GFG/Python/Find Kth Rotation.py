class Solution:
    def findKRotation(self, arr):
        # code here
        n = len(arr)
        l = 0
        r = n-1
        
        while l<r:
            mid = (l+r)//2
            
            if arr[mid] < arr[r]:
                r = mid
            else:
                l = mid+1
        
        return r
        
