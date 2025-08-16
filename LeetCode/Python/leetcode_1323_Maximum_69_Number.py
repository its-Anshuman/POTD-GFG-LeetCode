# LeetCode 1323: Maximum 69 Number
# https://leetcode.com/problems/maximum-69-number/

# Approach 1: Mathematical Place Value Method
class Solution:
    def maximum69Number(self, num: int) -> int:
        temp = num
        placeValSix = -1
        placeVal = 0

        while temp > 0:
            rem = temp % 10
            if rem == 6:
                placeValSix = placeVal
            temp //= 10
            placeVal += 1

        if placeValSix == -1:
            return num
        return num + (3 * pow(10, placeValSix))


# Approach 2: String Manipulation
class Solution:
    def maximum69Number(self, num: int) -> int:
        num_str = str(num)
        n = len(num_str)

        for i in range(n):
            if num_str[i] == '6':
                num_list = list(num_str)
                num_list[i] = '9'
                return int(''.join(num_list))

        return num
