/*
 * @lc app=leetcode.cn id=1358 lang=cpp
 * @lcpr version=30403
 *
 * [1358] 包含所有三种字符的子字符串数目
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution {
public:
    int numberOfSubstrings(string s) {
        int res = 0;
        int count[3] = {0,0,0};
        //int length = s.size();
        for (int i = 0,j = 0; j<s.size(); ++j) {
            count[s.at(j) - 'a']++;

            while (count[0] && count[1] && count[2]) {
                res += s.size() - j;
                count[s[i] - 'a']--;
                i++;
            }
        }

        return res;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    auto res = solution.numberOfSubstrings("abcabc");
    std::cout<<res<<std::endl;
}



/*
// @lcpr case=start
// "abcabc"\n
// @lcpr case=end

// @lcpr case=start
// "aaacb"\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n
// @lcpr case=end

 */

