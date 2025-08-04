# GFG - Palindrome Sentence
# Date: 2025-08-05

class Solution:
    def isPalinSent(self, s):
        # code here
        n = len(s)
        i = 0
        j = -1

        while i - n < j:
            while i < n and not s[i].isalnum():
                i += 1
            while abs(j) <= n and not s[j].isalnum():
                j -= 1
            if i - n >= j:
                break
            if s[i].lower() != s[j].lower():
                return False
            i += 1
            j -= 1

        return True
