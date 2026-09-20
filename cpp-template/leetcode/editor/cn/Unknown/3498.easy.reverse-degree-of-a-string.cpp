/*
 * @lc app=leetcode.cn id=3498 lang=cpp
 * @lcpr version=30404
 *
 * [3498] 字符串的反转度
 */

/*
 * [3811] 字符串的反转度
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
    int reverseDegree(string s) {
        unsigned int sum = 0;
        for (int i = 0; i<s.length(); ++i) {
            //char c = s.at(i);
            unsigned int invert = abs(s.at(i)-'z' - 1);
            sum +=(invert * (i + 1));
        }
        return sum;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// "abc"\n
// @lcpr case=end

// @lcpr case=start
// "zaza"\n
// @lcpr case=end

 */

