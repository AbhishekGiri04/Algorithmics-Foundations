/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                          LEETCODE PROBLEM SOLUTION                           ║
╠══════════════════════════════════════════════════════════════════════════════╣
║ Problem ID    : 3713                                                         ║
║ Problem Name  : Longest Balanced Substring I                                 ║
║ Difficulty    : Medium                                                       ║
║ Topic         : String, Frequency Counting                                   ║
╚══════════════════════════════════════════════════════════════════════════════╝

📋 PROBLEM STATEMENT:
Find the longest substring where all distinct characters appear equal number of times.

⏰ TIME COMPLEXITY: O(n² * 26)
💾 SPACE COMPLEXITY: O(1)
*/

class Solution {
public:
    int longestBalanced(string s) {

        int n = s.size();
        int ans = 1;

        for (int i = 0; i < n; i++) {

            vector<int> freq(26, 0);

            for (int j = i; j < n; j++) {

                freq[s[j] - 'a']++;

                int target = 0;
                bool ok = true;

                for (int k = 0; k < 26; k++) {

                    if (freq[k] > 0) {

                        if (target == 0) {
                            target = freq[k];
                        }
                        else if (freq[k] != target) {
                            ok = false;
                            break;
                        }
                    }
                }

                if (ok) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};