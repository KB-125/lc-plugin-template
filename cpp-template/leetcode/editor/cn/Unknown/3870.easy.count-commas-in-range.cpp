/*
 * @lc app=leetcode.cn id=3870 lang=cpp
 * @lcpr version=30404
 *
 * [3870] 统计范围内的逗号
 */

/*
 * [4245] 统计范围内的逗号
 */
#include <iostream>
#include <vector>
#include <string>
#include "../../common/ListNode.cpp"
#include "../../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution {
public:
    int countCommas(int n) {
        int m = n / 1000;
        if (m > 0) {
            return n - 999;
        }
        return 0;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// 1002\n
// @lcpr case=end

// @lcpr case=start
// 998\n
// @lcpr case=end

 */

