/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                          LEETCODE PROBLEM SOLUTION                           ║
╠══════════════════════════════════════════════════════════════════════════════╣
║ Problem ID    : 34                                                           ║
║ Problem Name  : Find First and Last Position of Element in Sorted Array      ║
║ Difficulty    : Medium                                                       ║
║ Topic         : Array, Binary Search                                         ║
╚══════════════════════════════════════════════════════════════════════════════╝

📋 PROBLEM STATEMENT:
Given an array of integers nums sorted in non-decreasing order,
find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

📝 EXAMPLES:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Input: nums = [], target = 0
Output: [-1,-1]

🎯 CONSTRAINTS:
- 0 <= nums.length <= 10^5
- -10^9 <= nums[i] <= 10^9
- nums is sorted in non-decreasing order
- -10^9 <= target <= 10^9

⏰ TIME COMPLEXITY: O(log n)
💾 SPACE COMPLEXITY: O(1)
*/

class Solution {
public:

    int findFirst(vector<int>& nums, int target) {

        int left = 0;
        int right = nums.size() - 1;
        int first = -1;

        while (left <= right) {

            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                first = mid;
                right = mid - 1;   
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return first;
    }

    int findLast(vector<int>& nums, int target) {

        int left = 0;
        int right = nums.size() - 1;
        int last = -1;

        while (left <= right) {

            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                last = mid;
                left = mid + 1;  
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return last;
    }

    vector<int> searchRange(vector<int>& nums, int target) {

        int first = findFirst(nums, target);
        int last = findLast(nums, target);

        return {first, last};
    }
};