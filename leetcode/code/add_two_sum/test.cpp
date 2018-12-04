#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode *setCurrentNode(ListNode *node, int val)
    {
        int carry = 0;

        node->val += val;
        carry = node->val / 10;
        node->val = node->val % 10;

        node->next = (ListNode *)malloc(sizeof(struct ListNode));
        node = node->next;
        node->val = carry;
        node->next = NULL;

        return node;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *ret = (ListNode *)malloc(sizeof(struct ListNode));
        ListNode *source = ret;
        ListNode *before = NULL;

        ret->val = 0;

        while (l1 != NULL && l2 != NULL) {
            before = ret;
            ret = setCurrentNode(ret, l1->val + l2->val);

            l1 = l1->next;
            l2 = l2->next;
        }

        ListNode *no_finish = NULL;
        if (l1 == NULL && l2 == NULL) {
            if (ret->val == 0) {
                free(ret);
                before->next = NULL;
                return source;
            } else {
                ret->val = 1;
                return source;
            }
        } else if (l1 != NULL) {
            no_finish = l1;
        } else if (l2 != NULL) {
            no_finish = l2;
        }

        while (no_finish != NULL) {
            before = ret;
            ret = setCurrentNode(ret, no_finish->val);
            no_finish = no_finish->next;
        }

        if (ret->val == 0) {
            free(ret);
            before->next = NULL;
        }

        return source;
    }
};

int main() { Solution su; }