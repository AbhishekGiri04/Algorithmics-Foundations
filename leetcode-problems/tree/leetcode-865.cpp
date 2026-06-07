/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                          LEETCODE PROBLEM SOLUTION                           ║
╠══════════════════════════════════════════════════════════════════════════════╣
║ Problem ID    : 865                                                          ║
║ Problem Name  : Smallest Subtree with all the Deepest Nodes                  ║
║ Difficulty    : Medium                                                       ║
║ Topic         : Binary Tree, DFS, Recursion, LCA                             ║
╚══════════════════════════════════════════════════════════════════════════════╝

📋 PROBLEM STATEMENT:
Given the root of a binary tree, return the smallest subtree that
contains all the deepest nodes.

A deepest node is a node having the maximum depth in the tree.

The answer is the root of the Lowest Common Ancestor (LCA) of all
deepest nodes.

📝 EXAMPLES:
Input: root = [3,5,1,6,2,0,8,null,null,7,4]
Output: [2,7,4]

Input: root = [1]
Output: [1]

Input: root = [0,1,3,null,2]
Output: [2]

🎯 CONSTRAINTS:
- The number of nodes in the tree is in the range [1, 500].
- 0 <= Node.val <= 500
- All node values are unique.

⏰ TIME COMPLEXITY: O(n)
💾 SPACE COMPLEXITY: O(h)
(h = height of tree)
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    pair<TreeNode*, int> dfs(TreeNode* root) {
        if (root == NULL)
            return {NULL, 0};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        if (left.second > right.second)
            return {left.first, left.second + 1};

        if (right.second > left.second)
            return {right.first, right.second + 1};

        return {root, left.second + 1};
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).first;
    }
};