/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                          LEETCODE PROBLEM SOLUTION                           ║
╠══════════════════════════════════════════════════════════════════════════════╣
║ Problem ID    : 74                                                           ║
║ Problem Name  : Search a 2D Matrix                                           ║
║ Difficulty    : Medium                                                       ║
║ Topic         : Array, Binary Search, Matrix                                 ║
╚══════════════════════════════════════════════════════════════════════════════╝

📋 PROBLEM STATEMENT:
You are given an m x n integer matrix matrix with the following properties:

- Each row is sorted in non-decreasing order
- The first integer of each row is greater than the last integer 
  of the previous row

Given an integer target, return true if target is in matrix 
or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

📝 EXAMPLES:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false

🎯 CONSTRAINTS:
- m == matrix.length
- n == matrix[i].length
- 1 <= m, n <= 100
- -10^4 <= matrix[i][j], target <= 10^4

⏰ TIME COMPLEXITY: O(log(m * n))
💾 SPACE COMPLEXITY: O(1)
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();
        int n = matrix[0].size();

        int low = 0;
        int high = m * n - 1;

        while (low <= high) {

            int mid = (low + high) / 2;

            int row = mid / n;
            int col = mid % n;

            if (matrix[row][col] == target) {
                return true;
            }

            else if (matrix[row][col] < target) {
                low = mid + 1;
            }

            else {
                high = mid - 1;
            }
        }

        return false;
    }
};