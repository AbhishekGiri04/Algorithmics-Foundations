/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                          LEETCODE PROBLEM SOLUTION                           ║
╠══════════════════════════════════════════════════════════════════════════════╣
║ Problem ID    : 66                                                           ║
║ Problem Name  : Plus One                                                     ║
║ Difficulty    : Easy                                                         ║
║ Topic         : Array, Math                                                  ║
╚══════════════════════════════════════════════════════════════════════════════╝

📋 PROBLEM STATEMENT:
You are given a large integer represented as an integer array digits,
where each digits[i] is the ith digit of the integer.

Increment the integer by one and return the resulting array of digits.

📝 EXAMPLES:

Input: digits = [1,2,3]
Output: [1,2,4]

Explanation:
123 + 1 = 124

Input: digits = [4,3,2,1]
Output: [4,3,2,2]

Explanation:
4321 + 1 = 4322

Input: digits = [9]
Output: [1,0]

Explanation:
9 + 1 = 10

🎯 CONSTRAINTS:
- 1 <= digits.length <= 100
- 0 <= digits[i] <= 9
- No leading zeros

⏰ TIME COMPLEXITY: O(n)
💾 SPACE COMPLEXITY: O(1)
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }

            digits[i] = 0;
        }

        digits.insert(digits.begin(), 1);
        return digits;
    }
};