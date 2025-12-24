/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                          LEETCODE PROBLEM SOLUTION                          ║
╠══════════════════════════════════════════════════════════════════════════════╣
║ Problem ID    : 3625                                                         ║
║ Problem Name  : Count Number of Trapezoids II                               ║
║ Difficulty    : Hard                                                         ║
║ Topic         : Geometry, Hash Map, Math, Combinatorics                     ║
║ Company Tags  : Google, Meta                                                ║
╚══════════════════════════════════════════════════════════════════════════════╝

📋 PROBLEM STATEMENT:
Given a 2D array of points, count the number of unique trapezoids that can be formed 
by choosing any four distinct points. A trapezoid has at least one pair of parallel 
sides (same slope).

📝 EXAMPLES:
Input:  points = [[-3,2],[3,0],[2,3],[3,2],[2,-3]]
Output: 2

Input:  points = [[0,0],[1,0],[0,1],[2,1]]
Output: 1

🎯 CONSTRAINTS:
- 4 <= points.length <= 500
- -1000 <= xi, yi <= 1000
- All points are pairwise distinct

💡 APPROACH:
Advanced Geometry + Combinatorics
1. Group point pairs by slope (parallel lines)
2. Count trapezoids from pairs of parallel lines
3. Subtract parallelograms (opposite sides parallel)
4. Use midpoint technique to identify parallelograms

⏰ TIME COMPLEXITY:  O(n²) for pair generation + O(k²) for slope processing
💾 SPACE COMPLEXITY: O(n²) for storing line information
*/

import java.util.*;

class Solution {
    /**
     * @brief Counts all trapezoids from given points
     * @param points 2D array of point coordinates
     * @return Number of unique trapezoids
     * 
     * Algorithm:
     * 1. For each pair of points, compute slope and line equation
     * 2. Group points by line (same slope and intercept)
     * 3. Count combinations of parallel lines
     * 4. Subtract parallelograms using midpoint detection
     */
    public int countTrapezoids(int[][] points) {
        int n = points.length;
        if (n < 4) return 0;

        // Step 1: Group points by line (slope + intercept)
        Map<String, BitSet> linePoints = new HashMap<>();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];

                // Compute normalized slope
                int dx = x2 - x1;
                int dy = y2 - y1;
                int g = gcd(dx, dy);
                dx /= g;
                dy /= g;
                
                // Normalize direction
                if (dx < 0) {
                    dx = -dx;
                    dy = -dy;
                } else if (dx == 0) {
                    dy = 1;
                }

                // Compute line equation: dy*x - dx*y = c
                long c = (long) dy * x1 - (long) dx * y1;

                String lineKey = dy + "_" + dx + "#" + c;

                linePoints.computeIfAbsent(lineKey, k -> new BitSet(n)).set(i);
                linePoints.get(lineKey).set(j);
            }
        }

        // Step 2: Count combinations for each slope
        Map<String, long[]> slopeStats = new HashMap<>();

        for (Map.Entry<String, BitSet> entry : linePoints.entrySet()) {
            String lineKey = entry.getKey();
            BitSet bs = entry.getValue();
            int cnt = bs.cardinality();
            if (cnt < 2) continue;

            long comb = (long) cnt * (cnt - 1) / 2;
            int hashIdx = lineKey.indexOf('#');
            String slope = lineKey.substring(0, hashIdx);

            long[] stats = slopeStats.computeIfAbsent(slope, k -> new long[2]);
            stats[0] += comb;
            stats[1] += comb * comb;
        }

        // Step 3: Count trapezoids from parallel lines
        long trapezoidCount = 0;
        for (long[] stats : slopeStats.values()) {
            long sumComb = stats[0];
            long sumCombSq = stats[1];
            if (sumComb > 0) {
                trapezoidCount += (sumComb * sumComb - sumCombSq) / 2;
            }
        }

        // Step 4: Subtract parallelograms
        long parallelograms = countParallelograms(points);

        return (int) Math.max(0, trapezoidCount - parallelograms);
    }

    /**
     * @brief Counts parallelograms using midpoint technique
     */
    private long countParallelograms(int[][] points) {
        int n = points.length;
        Map<Long, List<int[]>> midMap = new HashMap<>();

        // Group pairs by midpoint
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int sx = points[i][0] + points[j][0];
                int sy = points[i][1] + points[j][1];
                long key = (((long) sx) << 32) | (sy & 0xffffffffL);
                midMap.computeIfAbsent(key, k -> new ArrayList<>()).add(new int[]{i, j});
            }
        }

        long parallelograms = 0;

        for (List<int[]> pairs : midMap.values()) {
            int P = pairs.size();
            if (P < 2) continue;

            long totalPairs = (long) P * (P - 1) / 2;

            // Count shared vertices
            Map<Integer, Integer> degree = new HashMap<>();
            for (int[] pair : pairs) {
                degree.merge(pair[0], 1, Integer::sum);
                degree.merge(pair[1], 1, Integer::sum);
            }

            long sharedPairs = 0;
            for (int deg : degree.values()) {
                sharedPairs += (long) deg * (deg - 1) / 2;
            }

            long disjointPairs = totalPairs - sharedPairs;
            if (disjointPairs <= 0) continue;

            // Subtract collinear pairs
            long collinearDisjoint = countCollinearPairs(pairs, points);
            long validPairs = disjointPairs - collinearDisjoint;

            if (validPairs > 0) {
                parallelograms += validPairs;
            }
        }

        return parallelograms;
    }

    /**
     * @brief Counts collinear pairs with same slope
     */
    private long countCollinearPairs(List<int[]> pairs, int[][] points) {
        Map<String, List<int[]>> slopeBuckets = new HashMap<>();

        for (int[] pair : pairs) {
            int a = pair[0], b = pair[1];
            int dx = points[b][0] - points[a][0];
            int dy = points[b][1] - points[a][1];
            int g = gcd(dx, dy);
            dx /= g;
            dy /= g;

            if (dx < 0) {
                dx = -dx;
                dy = -dy;
            } else if (dx == 0) {
                dy = 1;
            }

            String slope = dy + "_" + dx;
            slopeBuckets.computeIfAbsent(slope, k -> new ArrayList<>()).add(pair);
        }

        long collinearDisjoint = 0;

        for (List<int[]> slopePairs : slopeBuckets.values()) {
            int t = slopePairs.size();
            if (t < 2) continue;

            long total = (long) t * (t - 1) / 2;

            Map<Integer, Integer> degree = new HashMap<>();
            for (int[] pair : slopePairs) {
                degree.merge(pair[0], 1, Integer::sum);
                degree.merge(pair[1], 1, Integer::sum);
            }

            long shared = 0;
            for (int deg : degree.values()) {
                shared += (long) deg * (deg - 1) / 2;
            }

            collinearDisjoint += (total - shared);
        }

        return collinearDisjoint;
    }

    /**
     * @brief Computes GCD of two numbers
     */
    private int gcd(int a, int b) {
        if (a == 0 && b == 0) return 1;
        a = Math.abs(a);
        b = Math.abs(b);
        if (a == 0) return b;
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }
}

/*
🎯 KEY LEARNINGS:
1. Trapezoid = 4 points with at least one pair of parallel sides
2. Parallel lines have same slope (normalized)
3. Parallelogram = special trapezoid (both pairs parallel)
4. Midpoint technique identifies parallelograms efficiently

🚀 RELATED PROBLEMS:
- LeetCode 149: Max Points on a Line
- LeetCode 3623: Count Number of Trapezoids I
- LeetCode 356: Line Reflection
- LeetCode 447: Number of Boomerangs

📚 CONCEPTS PRACTICED:
- Computational geometry
- Slope normalization
- Combinatorics
- Hash map optimization
*/
