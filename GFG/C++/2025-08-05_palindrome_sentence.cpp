// GFG - Palindrome Sentence
// Date: 2025-08-05

class Solution {
  public:
    bool isPalinSent(string &s) {
        // code here
        int n = s.length();
        int i = 0;
        int j = n - 1;

        while (i <= j) {
            while (i < j && !isalnum(s[i])) i++;
            while (i < j && !isalnum(s[j])) j--;

            if (tolower(s[i]) != tolower(s[j])) return false;

            i++;
            j--;
        }

        return true;
    }
};
