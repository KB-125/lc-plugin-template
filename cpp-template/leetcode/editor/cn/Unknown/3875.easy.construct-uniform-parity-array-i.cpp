/*
 * @lc app=leetcode.cn id=3875 lang=cpp
 * @lcpr version=30404
 *
 * [3875] 构造奇偶一致的数组 I
 */

/*
 * [4256] 构造奇偶一致的数组 I
 */
#include <iostream>
#include <vector>
#include <map>
#include "../../common/ListNode.cpp"
#include "../../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
       /*  bool allOdd = true;
        bool allEven = true;

        for (int i = 0; i<nums1.size(); ++i) {
            bool isEven = nums1[i]%2==0;
            bool isOdd = !isEven;
            for (int j = 0; j < nums1.size(); ++j) {
                if (j == i) {
                    continue;
                }
                bool localEven = (nums1[i]-nums1[j])%2==0;
                isEven |= localEven; 
                isOdd |= !localEven;
                
            }
            allEven &= isEven;
            allOdd &= isOdd;
            if (!(allEven || allOdd)) {
                return false;
            }
        }
        return true; */

        return true;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    std::vector<int> data{2,3};
    solution.uniformArray(data);
}



/*
// @lcpr case=start
// [2,3]\n
// @lcpr case=end

// @lcpr case=start
// [4,6]\n
// @lcpr case=end

 */

