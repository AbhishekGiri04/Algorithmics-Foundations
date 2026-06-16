/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                          LEETCODE PROBLEM SOLUTION                           ║
╠══════════════════════════════════════════════════════════════════════════════╣
║ Problem ID    : 153                                                          ║
║ Problem Name  : Find Minimum in Rotated Sorted Array                         ║
║ Difficulty    : Medium                                                       ║
║ Topic         : Array, Binary Search                                         ║
╚══════════════════════════════════════════════════════════════════════════════╝

📋 PROBLEM STATEMENT:
Suppose an array of length n sorted in ascending order
is rotated between 1 and n times.

Given the sorted rotated array nums containing unique
elements, return the minimum element.

You must implement a solution with:
- O(log n) time complexity

📝 EXAMPLES:

Input:
nums = [3,4,5,1,2]

Output:
1

Input:
nums = [4,5,6,7,0,1,2]

Output:
0

Input:
nums = [11,13,15,17]

Output:
11

⏰ TIME COMPLEXITY:
- O(log n)

💾 SPACE COMPLEXITY:
- O(1)
*/

class Solution {
public:
    int findMin(vector<int>& nums) {

        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {

            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right]) {

                left = mid + 1;

            } else {

                right = mid;
            }
        }

        return nums[left];
    }
};