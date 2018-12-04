# 题目描述
 >You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 >You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 ## exmple
    Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    Output: 7 -> 0 -> 8
    Explanation: 342 + 465 = 807.

# 我的代码

# 官方代码
    https://leetcode.com/problems/add-two-numbers/solution/

# 区别
当其中一个链表结束，而另一个没有结束时，我使用的是退出当前循环，然后再将没有结束的链表复制到新链表中，
官方的代码则是判断链表有没有结束，没有结束时该链表的值使用当前节点的值表示，而结束后当前链表的值使用0表示，这样在加法中，0不影响另一个链表的值，加起来后结果和复制链表结果一样，但是相对于复制链表，这种方法下代码十分简洁明了。