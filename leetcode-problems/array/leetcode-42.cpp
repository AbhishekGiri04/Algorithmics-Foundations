/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                          LEETCODE PROBLEM SOLUTION                           ║
╠══════════════════════════════════════════════════════════════════════════════╣
║ Problem ID    : 42                                                           ║
║ Problem Name  : Trapping Rain Water                                          ║
║ Difficulty    : Hard                                                         ║
║ Topic         : Array, Two Pointers, Dynamic Programming                     ║
╚══════════════════════════════════════════════════════════════════════════════╝

📋 PROBLEM STATEMENT:
Given n non-negative integers representing an elevation map where the
width of each bar is 1, compute how much water it can trap after raining.

📝 EXAMPLES:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6

Input: height = [4,2,0,3,2,5]
Output: 9

🎯 CONSTRAINTS:
- n == height.length
- 1 <= n <= 2 * 10^4
- 0 <= height[i] <= 10^5

⏰ TIME COMPLEXITY: O(n)
💾 SPACE COMPLEXITY: O(n)
*/

class Solution {
public:
    vector<int> left(vector<int>& height) {
        int n = height.size();
        vector<int> leftMax(n);

        leftMax[0] = height[0];

        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }

        return leftMax;
    }

    vector<int> right(vector<int>& height) {
        int n = height.size();
        vector<int> rightMax(n);

        rightMax[n - 1] = height[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }

        return rightMax;
    }

    int trap(vector<int>& height) {
        vector<int> leftMax = left(height);
        vector<int> rightMax = right(height);

        int n = height.size();
        int rain = 0;

        for (int i = 0; i < n; i++) {
            rain += min(leftMax[i], rightMax[i]) - height[i];
        }

        return rain;
    }
};