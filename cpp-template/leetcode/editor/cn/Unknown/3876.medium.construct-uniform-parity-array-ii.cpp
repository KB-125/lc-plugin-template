/*
 * @lc app=leetcode.cn id=3876 lang=cpp
 * @lcpr version=30404
 *
 * [3876] 构造奇偶一致的数组 II
 */

/*
 * [4258] 构造奇偶一致的数组 II
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
    bool uniformArray(vector<int>& nums1) {
       //ugly
       /*int minOdd = std::numeric_limits<int>::max();
       //int minEven = std::numeric_limits<int>::max();
       for (auto num : nums1) {
            if ((num & 1) == 1) {
                minOdd = minOdd < num ? minOdd : num;
            }
       } 
       
       
        // All Even
       bool allEven = true;
       for (int i = 0; i<nums1.size(); ++i) {
            bool isEven = (nums1[i] & 1) == 0;
            if (isEven) {
               continue;
            }else {
                bool valid = (nums1[i] - minOdd) >=1;
                if (!valid) {
                    allEven = false;
                    break;
                }
            }
       }
       //All Odd
       bool allOdd = true;
       for (int i = 0; i<nums1.size(); ++i) {
            bool isOdd = (nums1[i] & 1 )== 1;
            if (isOdd) {
               continue;
            }else {
                bool valid = (nums1[i] - minOdd) >=1;
                if (!valid) {
                    allOdd = false;
                    break;
                }
            }
       }
       if (!(allEven||allOdd)) {
        return false;
       }

       return true; */
        /* 找到 nums1(数值均不同) 的最小值来确定奇偶性质
        如果最小值为奇数，那其它的数字无论是奇数还是偶数都满足要求
        如果最小值为偶数，则需全为偶数，那其他数字只能为偶数:因为若有一个奇数，则需有一小于其的奇数用于相减，如此循环，总会存在一最小奇数无法满足。 */
       auto minNum = *std::min_element(nums1.begin(), nums1.end());
       if ((minNum & 1) == 0) {
            for (auto num : nums1) {
                if ((num & 1) == 1) {
                    return false;
                }
            }
       }
       return true;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// [1,4,7]\n
// @lcpr case=end

// @lcpr case=start
// [2,3]\n
// @lcpr case=end

// @lcpr case=start
// [4,6]\n
// @lcpr case=end

 */

