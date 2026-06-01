/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                          LEETCODE PROBLEM SOLUTION                           ║
╠══════════════════════════════════════════════════════════════════════════════╣
║ Problem ID    : 3507                                                         ║
║ Problem Name  : Minimum Pair Removal to Sort Array I                         ║
║ Difficulty    : Easy                                                         ║
║ Topic         : Array, Simulation                                            ║
╚══════════════════════════════════════════════════════════════════════════════╝

📋 PROBLEM STATEMENT:
Given an array nums, you can perform the following operation any
number of times:

1. Select the adjacent pair with the minimum sum.
2. If multiple such pairs exist, choose the leftmost one.
3. Replace the pair with their sum.

Return the minimum number of operations needed to make the array
non-decreasing.

An array is non-decreasing if every element is greater than or
equal to the previous element.

📝 EXAMPLES:

Input: nums = [5,2,3,1]
Output: 2

Explanation:
(3,1) → 4      => [5,2,4]
(2,4) → 6      => [5,6]

Input: nums = [1,2,2]
Output: 0

Explanation:
Array is already non-decreasing.

🎯 CONSTRAINTS:
- 1 <= nums.length <= 50
- -1000 <= nums[i] <= 1000

⏰ TIME COMPLEXITY: O(n²)
💾 SPACE COMPLEXITY: O(1) (excluding array modification)
*/

class Solution {
public:
    bool isSorted(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1])
                return false;
        }
        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int operations = 0;

        while (!isSorted(nums)) {
            int minSum = INT_MAX;
            int idx = 0;

            for (int i = 0; i < nums.size() - 1; i++) {
                int sum = nums[i] + nums[i + 1];

                if (sum < minSum) {
                    minSum = sum;
                    idx = i;
                }
            }

            nums[idx] = nums[idx] + nums[idx + 1];
            nums.erase(nums.begin() + idx + 1);

            operations++;
        }

        return operations;
    }
};