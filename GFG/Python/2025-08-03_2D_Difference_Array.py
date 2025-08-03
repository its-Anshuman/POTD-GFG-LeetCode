# GFG POTD - 2D Difference Array
# Date: 2025-08-03

# ************************ Brute Force ************************
class Solution:
    def applyDiff2D(self, mat, opr):
        # code here 
        for x in opr:
            v = x[0]
            r1 = x[1]
            c1 = x[2]
            r2 = x[3]
            c2 = x[4]
            
            for i in range(r1, r2 + 1):
                for j in range(c1, c2 + 1):
                    mat[i][j] += v
                    
        return mat


# ************************ Optimal Using 2D Difference Array ************************
class Solution:
    def applyDiff2D(self, mat, opr):
        # code here 
        n = len(mat)
        m = len(mat[0])
        
        diff = [[0] * (m + 2) for _ in range(n + 2)]
        
        for x in opr:
            v = x[0]
            r1 = x[1]
            c1 = x[2]
            r2 = x[3]
            c2 = x[4]
            
            diff[r1][c1] += v
            diff[r1][c2 + 1] -= v
            diff[r2 + 1][c1] -= v
            diff[r2 + 1][c2 + 1] += v
            
        for i in range(n):
            for j in range(m):
                if i > 0:
                    diff[i][j] += diff[i - 1][j]
                if j > 0:
                    diff[i][j] += diff[i][j - 1]
                if i > 0 and j > 0:
                    diff[i][j] -= diff[i - 1][j - 1]
                    
        for i in range(n):
            for j in range(m):
                mat[i][j] += diff[i][j]
                    
        return mat
