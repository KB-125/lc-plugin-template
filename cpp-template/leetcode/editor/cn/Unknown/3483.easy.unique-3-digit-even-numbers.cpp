/*
 * @lc app=leetcode.cn id=3483 lang=cpp
 * @lcpr version=30404
 *
 * [3483] 不同三位偶数的数目
 */

/*
 * [3799] 不同三位偶数的数目
 */
#include <iostream>
#include <vector>
#include <unordered_set>
#include "../../common/ListNode.cpp"
#include "../../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<bool> evens(1000, false);
        int res = 0;
        for (int i = 0; i<digits.size(); ++i) {
            if (0 == digits[i]) {
                continue;
            }
            for (int j = 0; j<digits.size(); ++j) {
                if (j == i) {
                    continue;
                }
                for (int k = 0; k<digits.size(); ++k) {
                    if (k == i || k == j || digits[k]%2 != 0) {
                        continue;
                    }

                    int n = digits[i]*100+digits[j]*10+digits[k];
                    if(!evens[n]){
                        evens[n] = true;
                        res++;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    vector<int> digits({0,2,2});
    solution.totalNumbers(digits);
}



/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [0,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [6,6,6]\n
// @lcpr case=end

// @lcpr case=start
// [1,3,5]\n
// @lcpr case=end

 */

