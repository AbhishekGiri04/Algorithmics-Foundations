/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                          LEETCODE PROBLEM SOLUTION                          ║
╠══════════════════════════════════════════════════════════════════════════════╣
║ Problem ID    : 540                                                          ║
║ Problem Name  : Single Element in a Sorted Array                            ║
║ Difficulty    : Medium                                                       ║
║ Topic         : Array, Binary Search, Bit Manipulation                      ║
║ Company Tags  : Amazon, Microsoft, Google, Facebook                         ║
╚══════════════════════════════════════════════════════════════════════════════╝

📋 PROBLEM STATEMENT:
Given a sorted array where every element appears exactly twice except for one element 
which appears exactly once, find that single element.
Must run in O(log n) time and O(1) space.

📝 EXAMPLES:
Input:  nums = [1,1,2,3,3,4,4,8,8]
Output: 2

Input:  nums = [3,3,7,7,10,11,11]
Output: 10

🎯 CONSTRAINTS:
- 1 <= nums.length <= 10^5
- 0 <= nums[i] <= 10^5

💡 APPROACHES:

Approach 1: XOR (O(n) time, O(1) space)
- XOR all elements: duplicates cancel out
- Simple but doesn't meet O(log n) requirement

Approach 2: Binary Search (O(log n) time, O(1) space) - OPTIMAL
- Key insight: Before single element, pairs start at even indices
- After single element, pairs start at odd indices
- Use binary search to find the transition point

⏰ TIME COMPLEXITY:  O(log n) - Binary search
💾 SPACE COMPLEXITY: O(1) - Constant extra space
*/

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    /**
     * @brief Finds single element using XOR (Simple approach)
     * @param nums Sorted array with duplicates
     * @return Single non-duplicate element
     * 
     * Algorithm:
     * XOR has property: a ^ a = 0, a ^ 0 = a
     * XOR all elements, duplicates cancel out
     * 
     * Time: O(n), Space: O(1)
     */
    int singleNonDuplicateXOR(vector<int>& nums) {
        int result = 0;
        for (int num : nums) {
            result ^= num;
        }
        return result;
    }
    
    /**
     * @brief Finds single element using Binary Search (Optimal)
     * @param nums Sorted array with duplicates
     * @return Single non-duplicate element
     * 
     * Algorithm:
     * Key Observation:
     * - Before single element: pairs at (even, odd) indices
     * - After single element: pairs at (odd, even) indices
     * 
     * Binary Search:
     * - If mid is even and nums[mid] == nums[mid+1]: single is on right
     * - If mid is even and nums[mid] != nums[mid+1]: single is on left
     * - If mid is odd: check with mid-1
     * 
     * Time: O(log n), Space: O(1)
     */
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            // Ensure mid is even for consistent comparison
            if (mid % 2 == 1) {
                mid--;
            }
            
            // Check if pair starts at mid
            if (nums[mid] == nums[mid + 1]) {
                // Pair is intact, single element is on right
                left = mid + 2;
            } else {
                // Pair is broken, single element is on left (or at mid)
                right = mid;
            }
        }
        
        return nums[left];
    }
};

/**
 * @brief Test function to validate solution
 */
void runTests() {
    Solution solution;
    
    // Test Case 1: Single element in middle
    vector<int> test1 = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    assert(solution.singleNonDuplicate(test1) == 2);
    cout << "✅ Test 1 Passed: [1,1,2,3,3,4,4,8,8] -> 2" << endl;
    
    // Test Case 2: Single element near end
    vector<int> test2 = {3, 3, 7, 7, 10, 11, 11};
    assert(solution.singleNonDuplicate(test2) == 10);
    cout << "✅ Test 2 Passed: [3,3,7,7,10,11,11] -> 10" << endl;
    
    // Test Case 3: Single element at start
    vector<int> test3 = {1, 2, 2, 3, 3};
    assert(solution.singleNonDuplicate(test3) == 1);
    cout << "✅ Test 3 Passed: [1,2,2,3,3] -> 1" << endl;
    
    // Test Case 4: Single element at end
    vector<int> test4 = {1, 1, 2, 2, 3};
    assert(solution.singleNonDuplicate(test4) == 3);
    cout << "✅ Test 4 Passed: [1,1,2,2,3] -> 3" << endl;
    
    // Test Case 5: Only one element
    vector<int> test5 = {1};
    assert(solution.singleNonDuplicate(test5) == 1);
    cout << "✅ Test 5 Passed: [1] -> 1" << endl;
    
    cout << "\n🎉 All tests passed!" << endl;
}

/**
 * @brief Utility function to print array
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
    cout << "🚀 LeetCode 540: Single Element in a Sorted Array" << endl;
    cout << "===================================================" << endl;
    
    // Run comprehensive tests
    runTests();
    
    cout << "\n📊 Interactive Example:" << endl;
    Solution solution;
    
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    printArray(nums, "Input Array");
    
    int result = solution.singleNonDuplicate(nums);
    cout << "Single Element: " << result << endl;
    
    cout << "\n💡 Explanation:" << endl;
    cout << "Before index 2: pairs at (0,1), (3,4), (5,6), (7,8)" << endl;
    cout << "At index 2: single element breaks the pattern" << endl;
    cout << "Binary search finds the transition point efficiently" << endl;
    
    return 0;
}

/*
🎯 KEY LEARNINGS:
1. XOR approach is simple but O(n) - doesn't meet requirement
2. Binary search exploits sorted array property
3. Pair pattern changes at single element position
4. Always ensure mid is even for consistent comparison
5. O(log n) solution possible due to sorted nature

🚀 RELATED PROBLEMS:
- LeetCode 136: Single Number
- LeetCode 137: Single Number II
- LeetCode 260: Single Number III
- LeetCode 287: Find the Duplicate Number

📚 CONCEPTS PRACTICED:
- Binary search variations
- Bit manipulation (XOR)
- Pattern recognition
- Index manipulation
- Sorted array properties
*/
