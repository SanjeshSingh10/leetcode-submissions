class Solution {
public:
    string longestPalindrome(string s) {
          int n = s.size();

        int maxlen = 0;
        int start = 0;

        for (int i = 0; i < n; i++) {

            for (int j = i; j < n; j++) {

                // Check s[i...j] is palindrome
                int low = i;
                int high = j;

                bool isPalindrome = true;

                while (low < high) {

                    if (s[low] != s[high]) {
                        isPalindrome = false;
                        break;
                    }

                    low++;
                    high--;
                }

                // If palindrome, update answer
                if (isPalindrome) {
                    int len = j - i + 1;

                    if (len > maxlen) {
                        maxlen = len;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, maxlen); 
    }
};