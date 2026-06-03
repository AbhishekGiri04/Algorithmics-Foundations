/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                          LEETCODE PROBLEM SOLUTION                           ║
╠══════════════════════════════════════════════════════════════════════════════╣
║ Problem ID    : 110                                                          ║
║ Problem Name  : Balanced Binary Tree                                         ║
║ Difficulty    : Easy                                                         ║
║ Topic         : Binary Tree, DFS, Recursion                                  ║
╚══════════════════════════════════════════════════════════════════════════════╝

📋 PROBLEM STATEMENT:
Given a binary tree, determine if it is height-balanced.

A height-balanced binary tree is a binary tree in which the depth of
the two subtrees of every node never differs by more than one.

📝 EXAMPLES:
Input: root = [3,9,20,null,null,15,7]
Output: true

Input: root = [1,2,2,3,3,null,null,4,4]
Output: false

Input: root = []
Output: true

🎯 CONSTRAINTS:
- The number of nodes in the tree is in the range [0, 5000].
- 10^4 <= Node.val <= 10^4

⏰ TIME COMPLEXITY: O(n²)
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
    int height(TreeNode* root) {
        if (root == NULL)
            return 0;

        return 1 + max(height(root->left), height(root->right));
    }

    bool isBalanced(TreeNode* root) {
        if (root == NULL)
            return true;

        int left = height(root->left);
        int right = height(root->right);

        if (abs(left - right) > 1)
            return false;

        return isBalanced(root->left) && isBalanced(root->right);
    }
};