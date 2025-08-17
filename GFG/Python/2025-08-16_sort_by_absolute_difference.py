"""
Problem: Sort by Absolute Difference
Platform: GeeksforGeeks
Difficulty: Medium
Date: 2025-08-16

You are given a number x and array arr[]. Your task is to rearrange the elements
of the array according to the absolute difference with x, i.e., an element having
minimum difference comes first, and so on.

Note: If two or more elements are at equal distances, arrange them in the same 
sequence as in the given array.

Constraints:
1 ≤ x ≤ 10^5
1 ≤ arr.size() ≤ 10^5
1 ≤ arr[i] ≤ 10^5
"""

class Solution:
    def rearrange(self, arr, x):
        # Sort array by absolute difference with x
        arr.sort(key=lambda a: abs(a - x))
