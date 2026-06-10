/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                          LEETCODE PROBLEM SOLUTION                           ║
╠══════════════════════════════════════════════════════════════════════════════╣
║ Problem ID    : 55                                                           ║
║ Problem Name  : Jump Game                                                    ║
║ Difficulty    : Medium                                                       ║
║ Topic         : Array, Greedy                                                ║
╚══════════════════════════════════════════════════════════════════════════════╝

📋 PROBLEM STATEMENT:
You are given an integer array nums. You are initially positioned
at the array's first index, and each element in the array
represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

📝 EXAMPLES:

Input: nums = [2,3,1,1,4]
Output: true

Explanation:
- Start at index 0.
- Jump to index 1.
- From index 1, jump directly to the last index.
- Therefore, the last index is reachable.

Input: nums = [3,2,1,0,4]
Output: false

Explanation:
- You will eventually reach index 3.
- nums[3] = 0, so you cannot move further.
- Hence, the last index is not reachable.

🎯 CONSTRAINTS:
- 1 <= nums.length <= 10^4
- 0 <= nums[i] <= 10^5

⏰ TIME COMPLEXITY: O(n)
💾 SPACE COMPLEXITY: O(1)
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i > farthest) {
                return false;
            }

            farthest = max(farthest, i + nums[i]);

            if (farthest >= nums.size() - 1) {
                return true;
            }
        }

        return true;
    }
};