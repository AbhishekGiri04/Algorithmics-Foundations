/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                          LEETCODE PROBLEM SOLUTION                           ║
╠══════════════════════════════════════════════════════════════════════════════╣
║ Problem ID    : 136                                                          ║
║ Problem Name  : Single Number                                                ║
║ Difficulty    : Easy                                                         ║
║ Topic         : Array, Bit Manipulation                                      ║
╚══════════════════════════════════════════════════════════════════════════════╝

📋 PROBLEM STATEMENT:
Given a non-empty array of integers nums, every element appears
exactly twice except for one element which appears only once.

Find and return that single element.

You must implement a solution with:
- O(n) time complexity
- O(1) extra space

📝 EXAMPLES:

Input:
nums = [2,2,1]

Output:
1

Input:
nums = [4,1,2,1,2]

Output:
4

Input:
nums = [1]

Output:
1

⏰ TIME COMPLEXITY:
- O(n)

💾 SPACE COMPLEXITY:
- O(1)
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int XOR = 0;

        for (int x : nums) {
            XOR ^= x;
        }

        return XOR;
    }
};