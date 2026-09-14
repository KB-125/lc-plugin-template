/*
 * @lc app=leetcode.cn id=836 lang=cpp
 * @lcpr version=30404
 *
 * [836] 矩形重叠
 */

/*
 * [866] 矩形重叠
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
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        //分离轴
        if (!(rec1[2] <= rec2[0] || rec2[2] <= rec1[0]) && 
        !(rec1[3] <= rec2[1] || rec2[3] <= rec1[1]) ) {
            return true;
        }
        return false;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// [0,0,2,2]\n[1,1,3,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,1,1]\n[1,0,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,1,1]\n[2,2,3,3]\n
// @lcpr case=end

 */

