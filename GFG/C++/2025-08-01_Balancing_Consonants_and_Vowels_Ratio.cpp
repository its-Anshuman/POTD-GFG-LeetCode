// GFG POTD - Balancing Consonants and Vowels Ratio
// Date: 2025-08-01

#include <bits/stdc++.h>
using namespace std;

// ************************ Helper ************************
bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

// ************************ Brute Force ************************
class BruteSolution {
public:
    bool isBalanced(string &s) {
        int vow = 0;
        for (char c : s)
            if (isVowel(c)) vow++;
        int cons = s.length() - vow;
        return vow == cons;
    }

    int countBalanced(vector<string> &arr) {
        int n = arr.size(), res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                string curr = "";
                for (int k = i; k <= j; k++) curr += arr[k];
                if (isBalanced(curr)) res++;
            }
        }
        return res;
    }
};

// ************************ Better (String Building On-the-Go) ************************
class BetterSolution {
public:
    bool isBalanced(string &s) {
        int vow = 0;
        for (char c : s)
            if (isVowel(c)) vow++;
        return vow == (s.length() - vow);
    }

    int countBalanced(vector<string> &arr) {
        int n = arr.size(), res = 0;
        for (int i = 0; i < n; i++) {
            string curr = "";
            for (int j = i; j < n; j++) {
                curr += arr[j];
                if (isBalanced(curr)) res++;
            }
        }
        return res;
    }
};

// ************************ Optimal (Prefix Sum + HashMap) ************************
class OptimalSolution {
public:
    int countBalanced(vector<string> &arr) {
        unordered_map<int, int> freq;
        freq[0] = 1;

        int balance = 0, res = 0;

        for (string &s : arr) {
            for (char c : s) {
                if (isVowel(c)) balance++;
                else balance--;
            }
            res += freq[balance];
            freq[balance]++;
        }

        return res;
    }
};
