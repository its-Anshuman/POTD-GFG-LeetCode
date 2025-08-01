# LeetCode #118 - Pascal's Triangle
# Date: 2025-08-01

from typing import List

class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        pasTr = []
        for i in range(numRows):
            curr = [1] * (i + 1)
            for j in range(1, i):
                curr[j] = pasTr[i - 1][j - 1] + pasTr[i - 1][j]
            pasTr.append(curr)
        return pasTr
