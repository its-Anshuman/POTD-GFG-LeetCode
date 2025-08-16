// LeetCode 1323: Maximum 69 Number
// https://leetcode.com/problems/maximum-69-number/

// Approach 1: String Manipulation
class Solution {
public:
    int maximum69Number(int num) {
        string num_str = to_string(num);
        int n = num_str.length();

        for (int i = 0; i < n; i++) {
            if (num_str[i] == '6') {
                num_str[i] = '9';
                break;
            }
        }
        return stoi(num_str);
    }
};


// Approach 2: Mathematical Place Value Method
class Solution {
public:
    int maximum69Number(int num) {
        int temp = num;
        int placeValSix = -1;
        int placeVal = 0;

        while (temp != 0) {
            int rem = temp % 10;
            if (rem == 6) {
                placeValSix = placeVal;
            }
            temp /= 10;
            placeVal++;
        }
        return num + (3 * pow(10, placeValSix));
    }
};
