/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                          LEETCODE PROBLEM SOLUTION                           ║
╠══════════════════════════════════════════════════════════════════════════════╣
║ Problem ID    : 202                                                          ║
║ Problem Name  : Happy Number                                                 ║
║ Difficulty    : Easy                                                         ║
║ Topic         : Math, Cycle Detection                                        ║
╚══════════════════════════════════════════════════════════════════════════════╝

📋 PROBLEM STATEMENT:
A number is happy if repeatedly replacing it with sum of squares of digits
eventually leads to 1. Otherwise it falls into a cycle.

⏰ TIME COMPLEXITY: O(log n)
💾 SPACE COMPLEXITY: O(1)
*/

class Solution {
public:

    int getSum(int n) {
        int sum = 0;

        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }

        return sum;
    }

    bool isHappy(int n) {

        int slow = n;
        int fast = n;

        // Floyd Cycle Detection
        do {
            slow = getSum(slow);
            fast = getSum(getSum(fast));

        } while (slow != fast);

        return slow == 1;
    }
};