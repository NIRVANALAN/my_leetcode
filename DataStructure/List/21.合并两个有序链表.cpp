/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */
#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        // return head with smaller value
        ListNode *preHead = new ListNode(-1); //!preHead
        auto prev = preHead;

        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val <= l2->val)
            {
                prev->next = l1;
                l1 = l1->next;
            }
            else
            {
                prev->next = l2;
                l2 = l2->next;
            }
            prev = prev->next;
        }
        prev->next = l1 ? l1 : l2;

        return preHead->next;
    }
    void printList(ListNode *l)
    {
        auto head = l;
        while (head != nullptr)
        {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
};
// @lc code=end
