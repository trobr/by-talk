# Longest Palindromic Substring

# 题目描述
> Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
> 求字符串的最长回文子字符串

Example 1:

    Input: "babad"
    Output: "bab"
    Note: "aba" is also a valid answer.

Example 2:

    Input: "cbbd"
    Output: "bb"

# 思路
选择一个字符`s[i]`作为中心，依次判断字符左边`s[i-left]`和右边`s[i+right]`是否相等，相等则`left,right + 1`，否则退出，记录最长的子字符串。
`left,right + 1`的值根据字符串的类型是`aba`还是`abba`来改变。

# 我的代码

# 官方代码
    https://leetcode.com/problems/longest-palindromic-substring/solution/

# 总结
除了这种方法外，还有动态规划法和[Manacher's Algorithm][1]算法。


[1]: https://articles.leetcode.com/longest-palindromic-substring-part-ii/