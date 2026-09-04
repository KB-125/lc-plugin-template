/*
 * @lc app=leetcode.cn id=3903 lang=cpp
 * @lcpr version=30404
 *
 * [3903] 最小稳定下标 I
 */

/*
 * [4284] 最小稳定下标 I
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include "../../common/ListNode.cpp"
#include "../../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int max = nums[0];
        //auto min_iter = std::min_element(nums.begin(), nums.end());
        int min_index = std::min_element(nums.begin(), nums.end()) - nums.begin();
        for (int i = 0; i < nums.size(); ++i) {
            if ((max - nums[min_index] )<= k) {
                return i;
            }
            if (i == (nums.size()-1)) {
                return -1;
            }
            int nextIndex = i+1;
            max = max > nums[nextIndex] ? max : nums[nextIndex];
            if (min_index < nextIndex) {
                min_index = std::min_element((nums.begin() + nextIndex), nums.end()) - nums.begin();
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

