/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                          LEETCODE PROBLEM SOLUTION                           ║
╠══════════════════════════════════════════════════════════════════════════════╣
║ Problem ID    : 3713                                                         ║
║ Problem Name  : Longest Balanced Substring I                                 ║
║ Difficulty    : Medium                                                       ║
║ Topic         : String, Hash Map, Sliding Window                             ║
║ Company Tags  : Premium Problem                                              ║
╚══════════════════════════════════════════════════════════════════════════════╝

📋 PROBLEM STATEMENT:
You are given a string s consisting of lowercase English letters.
A substring of s is called balanced if all distinct characters in the 
substring appear the same number of times.
Return the length of the longest balanced substring of s.

📝 EXAMPLES:
Input:  s = "abbac"
Output: 4
Explanation: The longest balanced substring is "abba" because both distinct 
characters 'a' and 'b' each appear exactly 2 times.

Input:  s = "zzabccy"
Output: 4
Explanation: The longest balanced substring is "zabc" because the distinct 
characters 'z', 'a', 'b', and 'c' each appear exactly 1 time.

Input:  s = "aba"
Output: 2
Explanation: One of the longest balanced substrings is "ab" because both 
distinct characters 'a' and 'b' each appear exactly 1 time.

🎯 CONSTRAINTS:
- 1 <= s.length <= 1000
- s consists of lowercase English letters

💡 APPROACH:
Brute Force with Frequency Count
1. Try all possible substrings using two nested loops
2. For each substring, count frequency of each character
3. Check if all distinct characters have same frequency
4. Track maximum length of balanced substring

⏰ TIME COMPLEXITY:  O(n² × 26) = O(n²) - Two loops with constant alphabet check
💾 SPACE COMPLEXITY: O(26) = O(1) - Fixed size frequency array
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int ans = 1; 

        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);

            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;

                int target = 0;
                bool ok = true;

                for (int k = 0; k < 26; k++) {
                    if (freq[k] > 0) {
                        if (target == 0)
                            target = freq[k];
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

int main() {
    Solution sol;
    string s = "abbac";
    cout << "Output: " << sol.longestBalanced(s) << endl;
    return 0;
}
