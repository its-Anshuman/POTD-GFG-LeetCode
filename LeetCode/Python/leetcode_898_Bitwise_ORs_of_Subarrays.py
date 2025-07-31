# LeetCode #898 - Bitwise ORs of Subarrays
# Date: 2025-07-31

# ************************ Brute Force ************************
class BruteSolution:
    def subarrayBitwiseORs(self, arr: List[int]) -> int:
        n = len(arr)
        s = set()
        for i in range(n):
            for j in range(i, n):
                curr = arr[i]
                for k in range(i, j + 1):
                    curr |= arr[k]
                s.add(curr)
        return len(s)

# ************************ Better ************************
class BetterSolution:
    def subarrayBitwiseORs(self, arr: List[int]) -> int:
        n = len(arr)
        s = set()
        for i in range(n):
            curr = 0
            for j in range(i, n):
                curr |= arr[j]
                s.add(curr)
        return len(s)

# ************************ Optimal ************************
class OptimalSolution:
    def subarrayBitwiseORs(self, arr: List[int]) -> int:
        n = len(arr)
        prev = set()
        curr = set()
        res = set()

        for i in range(n):
            for x in prev:
                curr.add(arr[i]|x)
                res.add(arr[i]|x)
            curr.add(arr[i])
            res.add(arr[i])
            prev = curr
            curr = set()
                
        return len(res)
