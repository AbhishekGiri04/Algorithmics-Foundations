/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                          LEETCODE PROBLEM SOLUTION                           ║
╠══════════════════════════════════════════════════════════════════════════════╣
║ Problem ID    : 85                                                           ║
║ Problem Name  : Maximal Rectangle                                            ║
║ Difficulty    : Hard                                                         ║
║ Topic         : Array, Stack, Dynamic Programming, Matrix                    ║
╚══════════════════════════════════════════════════════════════════════════════╝

📋 PROBLEM STATEMENT:
Given a rows x cols binary matrix filled with '0's and '1's,
find the largest rectangle containing only '1's and return its area.

📝 EXAMPLES:
Input:
matrix =
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]

Output: 6

Input: matrix = [["0"]]
Output: 0

Input: matrix = [["1"]]
Output: 1

⏰ TIME COMPLEXITY:
- O(rows × cols)

💾 SPACE COMPLEXITY:
- O(cols)
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        stack<int> st;
        heights.push_back(0);

        int maxArea = 0;

        for (int i = 0; i < heights.size(); i++) {

            while (!st.empty() &&
                   heights[st.top()] > heights[i]) {

                int height = heights[st.top()];
                st.pop();

                int width = st.empty()
                                ? i
                                : i - st.top() - 1;

                maxArea = max(maxArea,
                              height * width);
            }

            st.push(i);
        }

        heights.pop_back();

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {

        if (matrix.empty()) {
            return 0;
        }

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> heights(cols, 0);

        int maxRectangle = 0;

        for (int i = 0; i < rows; i++) {

            for (int j = 0; j < cols; j++) {

                if (matrix[i][j] == '1') {
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }

            maxRectangle = max(
                maxRectangle,
                largestRectangleArea(heights)
            );
        }

        return maxRectangle;
    }
};