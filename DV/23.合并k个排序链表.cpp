/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个排序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct listnode {
 *     int val;
 *     listnode *next;
 *     listnode(int x) : val(x), next(null) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    // struct ListNode
    // {
    //     int val;
    //     ListNode *next;
    //     ListNode(int x) : val(x), next(nullptr) {}
    // };

public:
    ListNode *mergeTwoList_GT(ListNode *a, ListNode *b)
    {
        if (!a || !b)
            return a ? a : b;
        ListNode head(0), *tail = &head;
        while (a && b)
        {
            if (a->val <= b->val)
            {
                tail->next = a;
                a = a->next;
            }
            else
            {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }
        tail->next = a ? a : b; //* append remaining list
        return head.next;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        return merge(lists, 0, lists.size() - 1);
        // if (!lists.size())
        //     return nullptr; //!
        // while (lists.size() > 1)
        // {
        //     vector<ListNode *> tmp;
        //     int half = lists.size() / 2;
        //     for (size_t i = 0; i < half; i++)
        //     {
        //         tmp.push_back(mergeTwoList_GT(lists[i * 2], lists[i * 2 + 1]));
        //     }
        //     if (lists.size() % 2)
        //         tmp.push_back(lists.back());
        //     lists = tmp;
        // }
        // return lists[0];
    }
    ListNode *merge(vector<ListNode *> &lists, int l, int r)
    {
        if (l == r)
            return lists[l];
        if (l > r)
            return nullptr;
        int mid = (l + r) >> 1;
        return mergeTwoList_GT(merge(lists, l, mid), merge(lists, mid + 1, r));
    }
};
// @lc code=end
