/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // p0=>0 p2=>2 cur=>current
        int p0=0,p2=nums.size()-1, cur=0;
        while(cur<=p2){
            if(nums[cur]==0) swap(nums[p0++], nums[cur++]);
            else if(nums[cur]==2) swap(nums[p2--], nums[cur]);
            else
                cur++;
        }
    }
};
// @lc code=end

