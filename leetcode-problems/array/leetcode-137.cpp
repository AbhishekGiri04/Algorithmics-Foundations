/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                          LEETCODE PROBLEM SOLUTION                           ║
╠══════════════════════════════════════════════════════════════════════════════╣
║ Problem ID    : 137                                                          ║
║ Problem Name  : Single Number II                                             ║
║ Difficulty    : Medium                                                       ║
║ Topic         : Array, Bit Manipulation                                      ║
╚══════════════════════════════════════════════════════════════════════════════╝

📋 PROBLEM STATEMENT:
Given an integer array nums where every element appears
exactly three times except for one element, which appears
exactly once.

Find and return that single element.

You must implement a solution with:
- O(n) time complexity
- O(1) extra space

📝 EXAMPLES:

Input:
nums = [2,2,3,2]

Output:
3

Input:
nums = [0,1,0,1,0,1,99]

Output:
99

⏰ TIME COMPLEXITY:
- O(n)

💾 SPACE COMPLEXITY:
- O(1)
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int ones = 0;
        int twos = 0;

        for (int x : nums) {

            ones = (ones ^ x) & (~twos);

            twos = (twos ^ x) & (~ones);
        }

        return ones;
    }
};