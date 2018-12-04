#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    string longestPalindrome(string s)
    {
        int count = 1;
        int max_count = 1;
        int max_start = 0;
        int is_re = 0;
        cout << s << endl;

        if (s.length() <= 1) {
            return s;
        }

        for (int i = 1, len = s.length() - 1; i <= len; i++) {
            int left_shift = 1;
            int right_shift = 1;

            if (s[i] == s[i - 1] && s[i] == s[i + 1]) {
                ++is_re;
            }
            if (s[i - 1] == s[i + 1] && is_re != 1) {
                left_shift = 1;
                right_shift = 1;
            } else if (s[i + 1] == s[i]) {
                left_shift = 0;
                right_shift = 1;
            } else if (s[i] == s[i - 1]) {
                left_shift = 1;
                right_shift = 0;
            } else {
                continue;
            }

            while ((i - left_shift) >= 0 && (i + right_shift) <= len) {
                if (s[i - left_shift] == s[i + right_shift]) {
                    ++left_shift;
                    ++right_shift;
                } else {
                    break;
                }
            }

            int dis = left_shift + right_shift - 1;
            if (dis > max_count) {
                max_count = dis;
                max_start = i - left_shift + 1;
            }

            if (is_re > 0 && is_re < 2) {
                --i;
            } else {
                is_re = 0;
            }
        }

        char *ret = (char *)malloc(1001);
        s.copy(ret, max_count, max_start);
        return ret;
    }
};

int main()
{
    Solution su;
    string back = su.longestPalindrome(
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaa");
    cout << back << endl;
}