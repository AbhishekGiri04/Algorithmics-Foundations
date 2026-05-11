/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                          LEETCODE PROBLEM SOLUTION                           ║
╠══════════════════════════════════════════════════════════════════════════════╣
║ Problem ID    : 344                                                          ║
║ Problem Name  : Reverse String                                               ║
║ Difficulty    : Easy                                                         ║
║ Topic         : Two Pointers, String                                         ║
╚══════════════════════════════════════════════════════════════════════════════╝

📋 PROBLEM STATEMENT:
Reverse a string in-place using O(1) extra space.

⏰ TIME COMPLEXITY: O(n)
💾 SPACE COMPLEXITY: O(1)
*/

class Solution {
public:
    void reverseString(vector<char>& s) {

        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};