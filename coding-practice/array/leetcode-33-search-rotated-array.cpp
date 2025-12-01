/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                          LEETCODE PROBLEM SOLUTION                          ║
╠══════════════════════════════════════════════════════════════════════════════╣
║ Problem ID    : 33                                                           ║
║ Problem Name  : Search in Rotated Sorted Array                              ║
║ Difficulty    : Medium                                                       ║
║ Topic         : Array, Binary Search                                        ║
║ Company Tags  : Amazon, Microsoft, Facebook, Google, Apple                  ║
╚══════════════════════════════════════════════════════════════════════════════╝

📋 PROBLEM STATEMENT:
Given a rotated sorted array and a target value, return the index of target.
If target is not found in the array, return -1.
You must write an algorithm with O(log n) runtime complexity.

📝 EXAMPLES:
Input:  nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Input:  nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Input:  nums = [1], target = 0
Output: -1

🎯 CONSTRAINTS:
- 1 <= nums.length <= 5000
- -10^4 <= nums[i] <= 10^4
- All values of nums are unique
- nums is an ascending array that is possibly rotated
- -10^4 <= target <= 10^4

💡 APPROACH:
Modified Binary Search - Key insight: At least one half is always sorted.
1. Find mid element
2. Determine which half is sorted (left or right)
3. Check if target lies in the sorted half's range
4. Eliminate the half that cannot contain target
5. Repeat until found or search space exhausted

⏰ TIME COMPLEXITY:  O(log n) - Binary search elimination
💾 SPACE COMPLEXITY: O(1) - Constant extra space
*/

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    /**
     * @brief Searches for target in rotated sorted array
     * @param nums Rotated sorted array with distinct values
     * @param target Value to search for
     * @return Index of target if found, -1 otherwise
     * 
     * Algorithm:
     * 1. Use binary search with left and right pointers
     * 2. At each iteration, determine which half is properly sorted
     * 3. Check if target lies in the sorted half's range
     * 4. Adjust boundaries to eliminate impossible half
     */
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Target found at mid
            if (nums[mid] == target) {
                return mid;
            }
            
            // Determine which half is sorted
            if (nums[left] <= nums[mid]) {
                // Left half is sorted: [left...mid]
                if (nums[left] <= target && target < nums[mid]) {
                    // Target is in left sorted portion
                    right = mid - 1;
                } else {
                    // Target is in right portion
                    left = mid + 1;
                }
            } else {
                // Right half is sorted: [mid...right]
                if (nums[mid] < target && target <= nums[right]) {
                    // Target is in right sorted portion
                    left = mid + 1;
                } else {
                    // Target is in left portion
                    right = mid - 1;
                }
            }
        }
        
        return -1; // Target not found
    }
};

/**
 * @brief Test function to validate solution with multiple test cases
 */
void runTests() {
    Solution solution;
    
    // Test Case 1: Target in rotated portion
    vector<int> test1 = {4, 5, 6, 7, 0, 1, 2};
    assert(solution.search(test1, 0) == 4);
    cout << "✅ Test 1 Passed: [4,5,6,7,0,1,2], target=0 -> 4" << endl;
    
    // Test Case 2: Target not in array
    vector<int> test2 = {4, 5, 6, 7, 0, 1, 2};
    assert(solution.search(test2, 3) == -1);
    cout << "✅ Test 2 Passed: [4,5,6,7,0,1,2], target=3 -> -1" << endl;
    
    // Test Case 3: Single element, target not found
    vector<int> test3 = {1};
    assert(solution.search(test3, 0) == -1);
    cout << "✅ Test 3 Passed: [1], target=0 -> -1" << endl;
    
    // Test Case 4: Target in sorted portion
    vector<int> test4 = {4, 5, 6, 7, 0, 1, 2};
    assert(solution.search(test4, 5) == 1);
    cout << "✅ Test 4 Passed: [4,5,6,7,0,1,2], target=5 -> 1" << endl;
    
    // Test Case 5: No rotation
    vector<int> test5 = {1, 2, 3, 4, 5};
    assert(solution.search(test5, 3) == 2);
    cout << "✅ Test 5 Passed: [1,2,3,4,5], target=3 -> 2" << endl;
}

/**
 * @brief Utility function to print array elements
 */
void printArray(const vector<int>& arr, const string& label) {
    cout << label << ": [";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

/**
 * @brief Main function demonstrating the solution
 */
int main() {
    cout << "🚀 LeetCode 33: Search in Rotated Sorted Array" << endl;
    cout << "===============================================" << endl;
    
    // Run comprehensive tests
    runTests();
    
    cout << "\n📊 Interactive Example:" << endl;
    Solution solution;
    
    // Interactive example
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    printArray(nums, "Rotated Array");
    cout << "Target: " << target << endl;
    
    int result = solution.search(nums, target);
    cout << "Result: " << result << endl;
    
    cout << "\n💡 Explanation:" << endl;
    cout << "Array was originally [0,1,2,4,5,6,7], rotated at index 4" << endl;
    cout << "Using binary search, we identify sorted halves and narrow search" << endl;
    cout << "Target 0 found at index 4" << endl;
    
    return 0;
}

/*
🎯 KEY LEARNINGS:
1. Modified binary search works on rotated sorted arrays
2. At least one half is always properly sorted
3. Use sorted half to determine search direction
4. O(log n) complexity maintained despite rotation

🚀 RELATED PROBLEMS:
- LeetCode 81: Search in Rotated Sorted Array II
- LeetCode 153: Find Minimum in Rotated Sorted Array
- LeetCode 154: Find Minimum in Rotated Sorted Array II

📚 CONCEPTS PRACTICED:
- Binary search variations
- Array rotation handling
- Sorted array properties
- Search space elimination
*/