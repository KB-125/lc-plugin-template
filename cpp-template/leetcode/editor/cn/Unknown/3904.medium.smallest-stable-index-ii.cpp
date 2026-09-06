/*
 * @lc app=leetcode.cn id=3904 lang=cpp
 * @lcpr version=30404
 *
 * [3904] 最小稳定下标 II
 */

/*
 * [4285] 最小稳定下标 II
 */
#include <iostream>
#include <vector>
#include <limits>
#include "../../common/ListNode.cpp"
#include "../../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int pre_max = std::numeric_limits<int>::min();
        vector<int> suf_min(nums.size(),0);
        
        suf_min[nums.size()-1] = nums[nums.size()-1];
        for (int i =1,j=nums.size()-2; i<nums.size(); ++i,--j) {
            //pre_max[i] = pre_max[i-1]>nums[i]?pre_max[i-1]:nums[i];
            suf_min[j] = suf_min[j+1]<nums[j]?suf_min[j+1]:nums[j];
        }

        for (int i = 0; i<nums.size(); ++i) {
            pre_max = pre_max>nums[i] ? pre_max : nums[i];
            if ((pre_max-suf_min[i]) <= k) {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// [5,0,1,4]\n3\n
// @lcpr case=end

// @lcpr case=start
// [3,2,1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [0]\n0\n
// @lcpr case=end

 */

