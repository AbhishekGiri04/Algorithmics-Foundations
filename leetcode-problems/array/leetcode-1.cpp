/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                          LEETCODE PROBLEM SOLUTION                           ║
╠══════════════════════════════════════════════════════════════════════════════╣
║ Problem ID    : 1                                                            ║
║ Problem Name  : Two Sum                                                      ║
║ Difficulty    : Easy                                                         ║
║ Topic         : Array, Hash Table                                            ║
╚══════════════════════════════════════════════════════════════════════════════╝

📋 PROBLEM STATEMENT:
Given an array of integers nums and an integer target,
return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution,
and you may not use the same element twice.

You can return the answer in any order.

📝 EXAMPLES:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]

Input: nums = [3,2,4], target = 6
Output: [1,2]

Input: nums = [3,3], target = 6
Output: [0,1]

🎯 CONSTRAINTS:
- 2 <= nums.length <= 10^4
- -10^9 <= nums[i] <= 10^9
- -10^9 <= target <= 10^9
- Only one valid answer exists

⏰ TIME COMPLEXITY: O(n)
💾 SPACE COMPLEXITY: O(n)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {

            int value = target - nums[i];

            if (mp.find(value) != mp.end()) {
                return {mp[value], i};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};