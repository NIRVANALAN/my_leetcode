/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
#include <queue>
using namespace std;
class Solution
{
    // struct ListNode
    // {
    //     int val;
    //     ListNode *next;
    //     ListNode(int x) : val(x), next(NULL) {}
    // };

public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL || head->next == NULL)
            return head;
        queue<ListNode *> list_queue;
        auto iter = head;
        while (1)
        {
            if (list_queue.size() == k + 1)
                list_queue.pop();
            list_queue.push(iter);
            if (iter->next != NULL)
                iter = iter->next;
            else
                break;
        }
        if (list_queue.size() == k)
            return head;

        if (list_queue.size() != k + 1)
        {
            int remain_que_size = list_queue.size() - k % list_queue.size() - 1; //! attention
            for (size_t i = 0; i < remain_que_size; i++)
            {
                list_queue.pop();
            }
        }
        list_queue.back()->next = head;
        head = list_queue.front()->next;
        list_queue.front()->next = NULL;
        return head;
    }
};
// @lc code=end
