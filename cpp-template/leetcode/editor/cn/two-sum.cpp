/*
 * @lc app=leetcode.cn id=1 lang=cpp
 * @lcpr version=30403
 *
 * [1] 两数之和
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> twoSum(const vector<int>& nums, int target) {
        std::unordered_map<int, int> hash_map;
                
        for (int i = 0; i<nums.size(); ++i) {
            int value = target - nums[i];
            if(hash_map.end() !=  hash_map.find(value)){
                return {hash_map[value], i};
            }else {
                hash_map.emplace(nums[i],i);
            }
        }
        return {0,0};
    }
};
// @lc code=end



int main() {
    Solution solution;
    // your test code here
    auto res = solution.twoSum({3,2,4}, 6);
    std::copy(res.begin(), res.end(), 
    std::ostream_iterator<int>(std::cout, " "));
}



/*
// @lcpr case=start
// [2,7,11,15]\n9\n
// @lcpr case=end

// @lcpr case=start
// [3,2,4]\n6\n
// @lcpr case=end

// @lcpr case=start
// [3,3]\n6\n
// @lcpr case=end

 */

