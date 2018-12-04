# 题目描述
>Given a string, find the length of the longest substring without repeating characters.

Example 1:

    Input: "abcabcbb"
    Output: 3 
    Explanation: The answer is "abc", with the length of 3. 

Example 2:

    Input: "bbbbb"
    Output: 1
    Explanation: The answer is "b", with the length of 1.

Example 3:

    Input: "pwwkew"
    Output: 3
    Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

# 我的代码

# 官方代码

    https://leetcode.com/problems/longest-substring-without-repeating-characters/solution/

# 思路
## 我的思路
寻找不重复的子字符串，则依次从字符串中每个字符开始寻找，创建一个**hashmap**的集合，对于每个字符，判断其是否在集合中，如果不在则将其添加到集合中，如果存在在结束，判断当前不重复字符串的长度，如果大于已知的最大的不重复字符串长度，则用当前值替换最大值。对于每个字符都执行这样的操作，知道字符串结束，即可找出最长的不重复字符串。
## 官方思路
与我的思路不同的是，对于一个字符如`a`查找从其开始的不重复字符串，当找到一个字符存在已知字符集合中时，不清空当前集合并从`a`的下一个字符查找，而是从重复的这个字符设置为其实字符，继续从当前位置查找