/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                          LEETCODE PROBLEM SOLUTION                           ║
╠══════════════════════════════════════════════════════════════════════════════╣
║ Problem ID    : 3625                                                         ║
║ Problem Name  : Count Number of Trapezoids II                                ║
║ Difficulty    : Hard                                                         ║
║ Topic         : Geometry, Hash Map, Math, Combinatorics                      ║
╚══════════════════════════════════════════════════════════════════════════════╝

📋 IDEA:
- A trapezoid is formed by choosing 2 points from one line (same slope group)
  and 2 points from another parallel line (same slope group)
- So we:
  1. Group all lines by slope
  2. For each slope group, count how many segments can be formed
  3. Combine pairs of different lines with same slope

⏰ TIME COMPLEXITY: O(n^2)
💾 SPACE COMPLEXITY: O(n^2)
*/

import java.util.*;

class Solution {

    static class Line {
        long slopeX, slopeY, c;

        Line(int x1, int y1, int x2, int y2) {
            long dx = x2 - x1;
            long dy = y2 - y1;

            long g = gcd(dx, dy);
            dx /= g;
            dy /= g;

            if (dx < 0) {
                dx = -dx;
                dy = -dy;
            }
            if (dx == 0) dy = 1;

            slopeX = dx;
            slopeY = dy;

            c = dy * x1 - dx * y1;
        }
    }

    public int countTrapezoids(int[][] points) {
        int n = points.length;

        Map<String, List<Long>> map = new HashMap<>();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                Line ln = new Line(
                    points[i][0], points[i][1],
                    points[j][0], points[j][1]
                );

                String key = ln.slopeX + "#" + ln.slopeY;
                map.computeIfAbsent(key, k -> new ArrayList<>()).add(ln.c);
            }
        }

        long ans = 0;

        for (List<Long> lines : map.values()) {

            Map<Long, Integer> freq = new HashMap<>();

            for (long c : lines) {
                freq.put(c, freq.getOrDefault(c, 0) + 1);
            }

            List<Long> counts = new ArrayList<>();

            for (int val : freq.values()) {
                if (val >= 2) {
                    long ways = (long) val * (val - 1) / 2;
                    counts.add(ways);
                }
            }

            long sum = 0;

            for (long x : counts) sum += x;

            for (long x : counts) {
                sum -= x;
                ans += x * sum;
            }
        }

        return (int) ans;
    }

    private static long gcd(long a, long b) {
        a = Math.abs(a);
        b = Math.abs(b);
        if (b == 0) return a;
        return gcd(b, a % b);
    }
}