 /*
╔══════════════════════════════════════════════════════════════════════════════╗
║                          LEETCODE PROBLEM SOLUTION                           ║
╠══════════════════════════════════════════════════════════════════════════════╣
║ Problem ID    : 9                                                            ║
║ Problem Name  : Palindrome Number                                            ║
║ Difficulty    : Easy                                                         ║
║ Topic         : Math, Number Manipulation                                    ║
╚══════════════════════════════════════════════════════════════════════════════╝

📋 PROBLEM STATEMENT:
Given an integer x, return true if x is a palindrome, otherwise false.

A palindrome reads the same forward and backward.

⏰ TIME COMPLEXITY: O(log n)
💾 SPACE COMPLEXITY: O(1)
*/

class Solution {
public:
    bool isPalindrome(int x) {

        if (x < 0) return false;

        if (x % 10 == 0 && x != 0) return false;

        int reversedHalf = 0;

        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }
        
        return (x == reversedHalf || x == reversedHalf / 10);
    }
};