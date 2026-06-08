/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                          LEETCODE PROBLEM SOLUTION                           ║
╠══════════════════════════════════════════════════════════════════════════════╣
║ Problem ID    : 48                                                           ║
║ Problem Name  : Rotate Image                                                 ║
║ Difficulty    : Medium                                                       ║
║ Topic         : Array, Matrix                                                ║
╚══════════════════════════════════════════════════════════════════════════════╝

📋 PROBLEM STATEMENT:
You are given an n x n 2D matrix representing an image.
Rotate the image by 90 degrees clockwise.

The rotation must be done in-place, meaning you cannot create
another 2D matrix for the result.

📝 EXAMPLES:
Input: matrix = [[1,2,3],
                 [4,5,6],
                 [7,8,9]]

Output: [[7,4,1],
         [8,5,2],
         [9,6,3]]

Input: matrix = [[5,1,9,11],
                 [2,4,8,10],
                 [13,3,6,7],
                 [15,14,12,16]]

Output: [[15,13,2,5],
         [14,3,4,1],
         [12,6,8,9],
         [16,7,10,11]]

🎯 CONSTRAINTS:
- n == matrix.length == matrix[i].length
- 1 <= n <= 20
- -1000 <= matrix[i][j] <= 1000

⏰ TIME COMPLEXITY: O(n²)
💾 SPACE COMPLEXITY: O(1)
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};