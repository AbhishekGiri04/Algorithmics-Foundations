/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                          LEETCODE PROBLEM SOLUTION                           ║
╠══════════════════════════════════════════════════════════════════════════════╣
║ Problem ID    : 1480                                                         ║
║ Problem Name  : Running Sum of 1d Array                                      ║
║ Difficulty    : Easy                                                         ║
║ Topic         : Array, Prefix Sum                                            ║
╚══════════════════════════════════════════════════════════════════════════════╝

📋 PROBLEM STATEMENT:
Given an array nums, return the running sum of nums where:
runningSum[i] = sum(nums[0]…nums[i])

📝 EXAMPLES:
Input: nums = [1,2,3,4]
Output: [1,3,6,10]

Input: nums = [1,1,1,1,1]
Output: [1,2,3,4,5]

Input: nums = [3,1,2,10,1]
Output: [3,4,6,16,17]

🎯 CONSTRAINTS:
- 1 <= nums.length <= 1000
- -10^6 <= nums[i] <= 10^6

⏰ TIME COMPLEXITY: O(n)
💾 SPACE COMPLEXITY: O(1)
*/

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {

        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            nums[i] = sum;
        }

        return nums;
    }
};