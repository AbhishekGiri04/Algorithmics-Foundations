/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                          LEETCODE PROBLEM SOLUTION                           ║
╠══════════════════════════════════════════════════════════════════════════════╣
║ Problem ID    : 3623                                                         ║
║ Problem Name  : Count Number of Trapezoids I                                 ║
║ Difficulty    : Medium                                                       ║
║ Topic         : Array, Hash Map, Math, Combinatorics                         ║
╚══════════════════════════════════════════════════════════════════════════════╝

📋 PROBLEM STATEMENT:
Given points in 2D plane, count number of horizontal trapezoids.

A horizontal trapezoid needs at least one pair of horizontal sides
(points on same y-coordinate form a horizontal segment).

Return result modulo 1e9+7.

⏰ TIME COMPLEXITY: O(n)
💾 SPACE COMPLEXITY: O(k) where k = unique y-values
*/

import java.util.*;

class Solution {
    public int countTrapezoids(int[][] points) {

        final long MOD = 1000000007L;

        Map<Integer, Long> freq = new HashMap<>();

        for (int[] p : points) {
            freq.put(p[1], freq.getOrDefault(p[1], 0L) + 1);
        }

        List<Long> ways = new ArrayList<>();

        for (long cnt : freq.values()) {
            if (cnt >= 2) {
                long c = cnt * (cnt - 1) / 2;
                ways.add(c % MOD);
            }
        }

        long sum = 0;
        for (long x : ways) {
            sum = (sum + x) % MOD;
        }

        long ans = 0;

        for (long x : ways) {
            sum = (sum - x + MOD) % MOD;
            ans = (ans + (x * sum) % MOD) % MOD;
        }

        return (int) ans;
    }
}