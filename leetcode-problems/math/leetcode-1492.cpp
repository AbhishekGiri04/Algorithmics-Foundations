/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                          LEETCODE PROBLEM SOLUTION                           ║
╠══════════════════════════════════════════════════════════════════════════════╣
║ Problem ID    : 1492                                                         ║
║ Problem Name  : The kth Factor of n                                          ║
║ Difficulty    : Medium                                                       ║
║ Topic         : Math, Number Theory                                          ║
╚══════════════════════════════════════════════════════════════════════════════╝

📋 PROBLEM STATEMENT:
Return the kth factor of n in sorted order, or -1 if it doesn't exist.

⏰ TIME COMPLEXITY: O(√n)
💾 SPACE COMPLEXITY: O(1)
*/

class Solution {
public:
    int kthFactor(int n, int k) {

        vector<int> small, large;

        for (int i = 1; i * i <= n; i++) {

            if (n % i == 0) {

                small.push_back(i);

                if (i != n / i) {
                    large.push_back(n / i);
                }
            }
        }

        if (k <= small.size()) {
            return small[k - 1];
        }

        k -= small.size();

        if (k <= large.size()) {
            return large[large.size() - k];
        }

        return -1;
    }
};