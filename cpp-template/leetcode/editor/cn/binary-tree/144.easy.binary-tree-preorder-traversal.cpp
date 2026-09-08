/*
 * @lc app=leetcode.cn id=144 lang=cpp
 * @lcpr version=30404
 *
 * [144] 二叉树的前序遍历
 */

/*
 * [144] 二叉树的前序遍历
 */
#include <iostream>
#include <vector>
#include <string>
#include "../../common/ListNode.cpp"
#include "../../common/TreeNode.cpp"

using namespace std;

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    vector<int> preorderTraversal(TreeNode* root) {
        if (nullptr == root) {
            return {};
        }
        vector<int> preOrders;

        preOrders.push_back(root->val);

        auto lefts = preorderTraversal(root->left);

        preOrders.insert(preOrders.end(), lefts.begin(), lefts.end());

        auto rights = preorderTraversal(root->right);

        preOrders.insert(preOrders.end(), rights.begin(), rights.end());

        return preOrders;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// [1,null,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5,null,8,null,null,6,7,9]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

