class Solution:
    def findLargest(self, arr):
        # Convert all integers to strings
        arr_str = list(map(str, arr))
        
        # Sort using custom rule: compare concatenations
        arr_str.sort(key=lambda x: x*10, reverse=True)  # multiply to avoid length mismatch

        # If the largest number is "0", the whole number is "0"
        if arr_str[0] == "0":
            return "0"
        
        # Concatenate and return
        return ''.join(arr_str)
