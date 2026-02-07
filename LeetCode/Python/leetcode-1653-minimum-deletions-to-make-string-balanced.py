//1

class Solution:
    def minimumDeletions(self, s: str) -> int:
        a_right_count = [0]*len(s)

        for i in range(len(s)-2,-1,-1):
            a_right_count[i] = a_right_count[i+1]
            a_right_count[i] += 1 if s[i+1] == 'a' else 0
        
        b_count_left = 0
        res = len(s)

        for i, c in enumerate(s):
            res = min(res,b_count_left+a_right_count[i])
            if(c=='b'):
                b_count_left += 1
        
        return res

//2

class Solution:
    def minimumDeletions(self, s: str) -> int:
        a_right_count = 0

        for i in range(len(s)-1,-1,-1):
            a_right_count += 1 if s[i] == 'a' else 0
        
        b_count_left = 0
        res = len(s)

        for i, c in enumerate(s):
            if s[i] == 'a':
                a_right_count -= 1
            res = min(res,b_count_left+a_right_count)
            if c=='b':
                b_count_left += 1
        
        return res
