class Solution:
    def smallestDiff(self,a, b, c):
        #code here.
        """
        Finds three elements (one from each array) such that
        the maximum difference among them is minimized.

        Args:
            a, b, c: Input integer arrays

        Returns:
            List of three integers in descending order
        """
        a.sort()
        b.sort()
        c.sort()
        
        i = j = k = 0
        n = len(a)
        
        min_diff = float("inf")
        
        res = [0,0,0]
        
        while i<n and j<n and k<n:
            x, y, z = a[i], b[j], c[k]
            
            curr_min = min(x, y, z)
            curr_max = max(x, y, z)
            
            diff = curr_max - curr_min
            
            if diff<min_diff:
                min_diff = diff
                res = [x, y, z]
            
            if curr_min == x:
                i += 1
            elif curr_min == y:
                j += 1
            else:
                k += 1
        
        res.sort(reverse = True)
        return res
