/*
 * @lc app=leetcode.cn id=3871 lang=cpp
 * @lcpr version=30404
 *
 * [3871] 统计范围内的逗号 II
 */

/*
 * [4248] 统计范围内的逗号 II
 */
#include <iostream>
#include <vector>
#include <cmath>
#include "../../common/ListNode.cpp"
#include "../../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution {
public:
    long long countCommas(long long n) {
        long long res = 0, t =0;
        vector<unsigned int> mods;
        mods.reserve(6);
        for (long long m = n % 1000 , k = n / 1000, i = 1; k > 0; m = k % 1000 , k/=1000 ,++i) {
            mods.push_back(m);
            if (k > 999) {
                t = k/1000;
                for (int j = i; j >=0 ; --j) {
                    res += i * 999*std::pow(1000,j) ;
                }
                res+=i;
                res -= i * std::pow(1000,i);
            }else {
                t = k;
            }
        }
        long long size = mods.size();
        for (int x = 0; x < size; ++x) {
            res += (size)*(mods[x] * std::pow(1000,x));
            res++ ;
        }
        
        res += size *(t-1)*std::pow(1000,size);

        
        //res -= (size) * std::pow(1000,size);
        return res;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    auto res = solution.countCommas(1409752114);
    
    return 0;
}



/*
// @lcpr case=start
// 1002\n
// @lcpr case=end

// @lcpr case=start
// 998\n
// @lcpr case=end

 */

