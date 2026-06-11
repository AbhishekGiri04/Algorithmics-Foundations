/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                          LEETCODE PROBLEM SOLUTION                           ║
╠══════════════════════════════════════════════════════════════════════════════╣
║ Problem ID    : 81                                                           ║
║ Problem Name  : Search in Rotated Sorted Array II                            ║
║ Difficulty    : Medium                                                       ║
║ Topic         : Array, Binary Search                                         ║
╚══════════════════════════════════════════════════════════════════════════════╝

📋 PROBLEM STATEMENT:
There is an integer array nums sorted in non-decreasing order
(not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown
pivot index k.

Given the array nums after the rotation and an integer target,
return true if target is in nums, or false if it is not.

You must decrease the overall operation steps as much as possible.

📝 EXAMPLES:
Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false

🎯 CONSTRAINTS:
- 1 <= nums.length <= 5000
- -10^4 <= nums[i] <= 10^4
- nums is guaranteed to be rotated at some pivot
- -10^4 <= target <= 10^4

⏰ TIME COMPLEXITY:
- Average Case : O(log n)
- Worst Case   : O(n) (because of duplicates)

💾 SPACE COMPLEXITY:
- O(1)
*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return true;
            }

            if (nums[low] == nums[mid] &&
                nums[mid] == nums[high]) {

                low++;
                high--;
            }

            else if (nums[low] <= nums[mid]) {

                if (nums[low] <= target &&
                    target < nums[mid]) {

                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }

            else {

                if (nums[mid] < target &&
                    target <= nums[high]) {

                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }

        return false;
    }
};