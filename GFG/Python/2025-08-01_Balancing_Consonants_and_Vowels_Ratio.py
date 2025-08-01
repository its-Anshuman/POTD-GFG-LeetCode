# GFG POTD - Balancing Consonants and Vowels Ratio
# Date: 2025-08-01

from typing import List
from collections import defaultdict

# ************************ Brute Force ************************
class BruteSolution:
    def isBalanced(self, s: str) -> bool:
        vowels = set('aeiou')
        vow = sum(1 for c in s if c in vowels)
        return vow == (len(s) - vow)

    def countBalanced(self, arr: List[str]) -> int:
        n = len(arr)
        res = 0
        for i in range(n):
            for j in range(i, n):
                curr = "".join(arr[i:j+1])
                if self.isBalanced(curr):
                    res += 1
        return res


# ************************ Better ************************
class BetterSolution:
    def isBalanced(self, s: str) -> bool:
        vowels = set('aeiou')
        vow = sum(1 for c in s if c in vowels)
        return vow == (len(s) - vow)

    def countBalanced(self, arr: List[str]) -> int:
        n = len(arr)
        res = 0
        for i in range(n):
            curr = ""
            for j in range(i, n):
                curr += arr[j]
                if self.isBalanced(curr):
                    res += 1
        return res


# ************************ Optimal (Prefix Balance + defaultdict) ************************
class OptimalSolution1:
    def countBalanced(self, arr: List[str]) -> int:
        mp = defaultdict(int)
        mp[0] = 1
        bal = 0
        res = 0
        for word in arr:
            for c in word:
                if c in 'aeiou':
                    bal += 1
                else:
                    bal -= 1
            res += mp[bal]
            mp[bal] += 1
        return res


# ************************ Optimal (Manual HashMap) ************************
class OptimalSolution2:
    def countBalanced(self, arr: List[str]) -> int:
        mp = {0: 1}
        bal = 0
        res = 0
        for word in arr:
            for c in word:
                if c in 'aeiou':
                    bal += 1
                else:
                    bal -= 1
            res += mp.get(bal, 0)
            mp[bal] = mp.get(bal, 0) + 1
        return res
