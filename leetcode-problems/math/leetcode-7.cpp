/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                          LEETCODE PROBLEM SOLUTION                           ║
╠══════════════════════════════════════════════════════════════════════════════╣
║ Problem ID    : 7                                                            ║
║ Problem Name  : Reverse Integer                                              ║
║ Difficulty    : Medium                                                       ║
║ Topic         : Math, Integer Manipulation                                   ║
╚══════════════════════════════════════════════════════════════════════════════╝

📋 PROBLEM STATEMENT:
Given a signed 32-bit integer x, return x with its digits reversed.
If reversing causes overflow outside [-2^31, 2^31 - 1], return 0.

⏰ TIME COMPLEXITY: O(log x)
💾 SPACE COMPLEXITY: O(1)
*/

class Solution {
public:
    int reverse(int x) {

        int res = 0;

        while (x != 0) {

            int digit = x % 10;
            x /= 10;

            if (res > INT_MAX / 10 || res < INT_MIN / 10) {
                return 0;
            }

            res = res * 10 + digit;
        }

        return res;
    }
};