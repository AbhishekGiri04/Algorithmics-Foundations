/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                          LEETCODE PROBLEM SOLUTION                           ║
╠══════════════════════════════════════════════════════════════════════════════╣
║ Problem ID    : 33                                                           ║
║ Problem Name  : Search in Rotated Sorted Array                               ║
║ Difficulty    : Medium                                                       ║
║ Topic         : Array, Binary Search                                         ║
╚══════════════════════════════════════════════════════════════════════════════╝

📋 PROBLEM STATEMENT:
There is an integer array nums sorted in ascending order 
(with distinct values).

Before being passed to your function, nums is possibly rotated 
at an unknown pivot index.

Given the array nums after rotation and an integer target,
return the index of target if it exists in nums,
otherwise return -1.

You must write an algorithm with O(log n) runtime complexity.

📝 EXAMPLES:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Input: nums = [1], target = 0
Output: -1

🎯 CONSTRAINTS:
- 1 <= nums.length <= 5000
- -10^4 <= nums[i] <= 10^4
- All values of nums are unique
- nums is sorted and possibly rotated
- -10^4 <= target <= 10^4

⏰ TIME COMPLEXITY: O(log n)
💾 SPACE COMPLEXITY: O(1)
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {

            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            if (nums[left] <= nums[mid]) {

                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }

            else {

                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};