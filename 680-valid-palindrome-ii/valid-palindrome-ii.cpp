class Solution {
public:
    bool isPalindrome(string& s, int st, int end) {
        while (st < end) {
            if (s[st] != s[end]) {
                return false;
            }
            st++;
            end--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int st = 0, end = s.length() - 1;

        while (st < end) {
            if (s[st] != s[end]) {
                // Try deleting s[st] OR deleting s[end]
                return isPalindrome(s, st + 1, end) || isPalindrome(s, st, end - 1);
            }
            st++;
            end--;
        }
        return true;
    }
};