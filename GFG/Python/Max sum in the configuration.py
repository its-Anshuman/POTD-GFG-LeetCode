class Solution:
    def maxSum(self, arr): 
        # Code here
        n = len(arr)
        res = elSum = temp = 0
        
        for i in range(n):
            temp += (i*arr[i])
            elSum += arr[i]
            
        res = temp
        
        for i in range(1,n):
            temp = temp - elSum + arr[i-1]*n
            res = max(res,temp)
            
        return res
