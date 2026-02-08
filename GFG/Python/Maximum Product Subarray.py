class Solution:
	def maxProduct(self,arr):
		# code here
		n = len(arr)
		prefix_pd = suffix_pd = 1
		res = min(arr)
		
		for i in range(n):
		    if prefix_pd == 0 : 
		        prefix_pd = 1
		    if suffix_pd == 0:
		        suffix_pd = 1
		    
		    prefix_pd *= arr[i]
		    suffix_pd *= arr[n-i-1]
		    
		    res = max(res,prefix_pd,suffix_pd)
		
		
	    return res
