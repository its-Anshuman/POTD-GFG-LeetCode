// 0274-h-index.cpp
// Problem: H-Index
// Difficulty: Medium
// Accuracy: 53.4%
// Submissions: 51K+
// Points: 4
//
// You are given an array citations[], where each element citations[i]
// represents the number of citations received by the ith paper of a researcher.
// The H-index is defined as the maximum value H, such that the researcher
// has published at least H papers, and all those papers have citation value
// greater than or equal to H.
//
// Examples:
// Input: citations = [3, 0, 5, 3, 0] → Output: 3
// Input: citations = [5, 1, 2, 4, 1] → Output: 2
// Input: citations = [0, 0] → Output: 0
//
// Constraints:
// 1 ≤ citations.size() ≤ 1e6
// 0 ≤ citations[i] ≤ 1e6

class Solution {
public:
    // Function to find H-index
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> freq(n + 1);

        for (int i = 0; i < n; i++) {
            if (citations[i] >= n) 
                freq[n]++;
            else 
                freq[citations[i]]++;
        }

        int Hindex = n;
        int num = freq[n];

        while (num < Hindex) {
            Hindex--;
            num += freq[Hindex];
        }

        return Hindex;
    }
};
