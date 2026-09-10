/*
 * @lc app=leetcode.cn id=2265 lang=cpp
 * @lcpr version=30404
 *
 * [2265] 统计值等于子树平均值的节点数
 */

/*
 * [2347] 统计值等于子树平均值的节点数
 */
#include <iostream>
#include <vector>
#include <utility>
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
    int res = 0;
    /**
     * @brief 
     * 
     * @param[out]  root  
     * 
     * @return <num, sum> 
     */
    pair<int, int> postTraverse(TreeNode* root){
        if (nullptr == root) {
            return {0,0};
        }

        auto leftSubTree = postTraverse(root->left);

        auto rightSubTree = postTraverse(root->right);

        int num = leftSubTree.first + rightSubTree.first + 1;
        int sum = leftSubTree.second + rightSubTree.second + root->val;

        if (root->val == (sum/num)) {
            res++;
        }

        return {num,sum};
    }

    int averageOfSubtree(TreeNode* root) {
        if (nullptr == root) {
            return 0;
        }
        auto leftSubTree = postTraverse(root->left);

        auto rightSubTree = postTraverse(root->right);

        int num = leftSubTree.first + rightSubTree.first + 1;
        int sum = leftSubTree.second + rightSubTree.second + root->val;

        if (root->val == (sum/num)) {
            res++;
        }

        return res;

    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// [4,8,5,0,1,null,6]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

