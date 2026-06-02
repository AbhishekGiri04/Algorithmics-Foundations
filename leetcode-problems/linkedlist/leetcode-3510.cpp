/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                          LEETCODE PROBLEM SOLUTION                           ║
╠══════════════════════════════════════════════════════════════════════════════╣
║ Problem ID    : 3510                                                         ║
║ Problem Name  : Minimum Pair Removal to Sort Array II                        ║
║ Difficulty    : Hard                                                         ║
║ Topic         : Heap, Linked List, Simulation, Greedy                        ║
╚══════════════════════════════════════════════════════════════════════════════╝

📋 PROBLEM STATEMENT:
You are given an integer array nums.

You can perform the following operation any number of times:

1. Select the adjacent pair with the minimum sum.
2. If multiple such pairs exist, choose the leftmost one.
3. Replace the pair with their sum.

Return the minimum number of operations needed to make the
array non-decreasing.

An array is non-decreasing if every element is greater than or
equal to the previous element.

📝 EXAMPLES:

Input: nums = [5,2,3,1]
Output: 2

Explanation:
(3,1) has minimum sum = 4
nums = [5,2,4]

(2,4) has minimum sum = 6
nums = [5,6]

Array becomes non-decreasing after 2 operations.

🎯 CONSTRAINTS:
- 1 <= nums.length <= 10^5
- -10^9 <= nums[i] <= 10^9

⏰ TIME COMPLEXITY: O(n log n)
💾 SPACE COMPLEXITY: O(n)
*/

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();

        if (n <= 1)
            return 0;

        vector<long long> a(nums.begin(), nums.end());

        vector<int> prev(n), next(n);
        vector<bool> alive(n, true);

        for (int i = 0; i < n; i++) {
            prev[i] = i - 1;
            next[i] = i + 1;
        }

        next[n - 1] = -1;

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;

        for (int i = 0; i + 1 < n; i++) {
            pq.push({a[i] + a[i + 1], i});
        }

        int bad = 0;

        for (int i = 0; i + 1 < n; i++) {
            if (a[i] > a[i + 1])
                bad++;
        }

        int operations = 0;

        while (bad > 0) {

            auto [sum, i] = pq.top();
            pq.pop();

            if (!alive[i])
                continue;

            int j = next[i];

            if (j == -1 || !alive[j])
                continue;

            if (a[i] + a[j] != sum)
                continue;

            int pi = prev[i];
            int nj = next[j];

            if (pi != -1 && a[pi] > a[i]) bad--;
            if (a[i] > a[j]) bad--;
            if (nj != -1 && a[j] > a[nj]) bad--;

            a[i] += a[j];

            alive[j] = false;

            next[i] = nj;

            if (nj != -1)
                prev[nj] = i;

            if (pi != -1 && a[pi] > a[i]) bad++;
            if (nj != -1 && a[i] > a[nj]) bad++;

            if (pi != -1)
                pq.push({a[pi] + a[i], pi});

            if (nj != -1)
                pq.push({a[i] + a[nj], i});

            operations++;
        }

        return operations;
    }
};