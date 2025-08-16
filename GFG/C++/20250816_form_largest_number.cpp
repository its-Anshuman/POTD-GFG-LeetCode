class Solution {
public:
    string findLargest(vector<int> &arr) {
        // Custom comparator
        auto cmp = [](int &a, int &b) {
            string s1 = to_string(a);
            string s2 = to_string(b);
            return s1 + s2 > s2 + s1; // Compare concatenated results
        };
        
        // Sort with custom comparator
        sort(arr.begin(), arr.end(), cmp);

        // If the first element is 0, result is "0"
        if (arr[0] == 0) return "0";
        
        string res = "";
        for (int num : arr) {
            res += to_string(num);
        }
        return res;
    }
};
