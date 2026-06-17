/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                          LEETCODE PROBLEM SOLUTION                           ║
╠══════════════════════════════════════════════════════════════════════════════╣
║ Problem ID    : 154                                                          ║
║ Problem Name  : Find Minimum in Rotated Sorted Array II                      ║
║ Difficulty    : Hard                                                         ║
║ Topic         : Array, Binary Search                                         ║
╚══════════════════════════════════════════════════════════════════════════════╝

📋 PROBLEM STATEMENT:
Suppose an array of length n sorted in ascending order
is rotated between 1 and n times.

Given the sorted rotated array nums that may contain
duplicate elements, return the minimum element.

You must decrease the overall operation steps as much
as possible.

📝 EXAMPLES:

Input:
nums = [1,3,5]

Output:
1

Input:
nums = [2,2,2,0,1]

Output:
0

⚠️ NOTE:
Because duplicates exist, in the worst case
(e.g. [1,1,1,1,1]), the algorithm may degrade
to O(n).

⏰ TIME COMPLEXITY:
- Average: O(log n)
- Worst Case: O(n)

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

            }
            else if (nums[mid] < nums[right]) {

                right = mid;

            }
            else {

                right--;
            }
        }

        return nums[left];
    }
};