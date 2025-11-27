/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                          LEETCODE PROBLEM SOLUTION                          ║
╠══════════════════════════════════════════════════════════════════════════════╣
║ Problem ID    : 75                                                           ║
║ Problem Name  : Sort Colors                                                  ║
║ Difficulty    : Medium                                                       ║
║ Topic         : Array, Two Pointers, Sorting                                ║
║ Company Tags  : Amazon, Microsoft, Google, Facebook, Apple                  ║
╚══════════════════════════════════════════════════════════════════════════════╝

📋 PROBLEM STATEMENT:
Given an array nums with n objects colored red, white, or blue, sort them in-place 
so that objects of the same color are adjacent, with the colors in the order red, 
white, and blue. We will use the integers 0, 1, and 2 to represent the color red, 
white, and blue, respectively. You must solve this problem without using the 
library's sort function.

📝 EXAMPLES:
Input:  nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Input:  nums = [2,0,1]
Output: [0,1,2]

🎯 CONSTRAINTS:
- n == nums.length
- 1 <= n <= 300
- nums[i] is either 0, 1, or 2

💡 APPROACHES:
1. Counting Sort: Count occurrences and reconstruct - O(n) time, O(1) space
2. Two-Pass: First pass for 0s, second for 1s - O(n) time, O(1) space
3. Dutch National Flag: Single pass with three pointers - O(n) time, O(1) space (OPTIMAL)
4. Bubble Sort: Your approach - O(n²) time, O(1) space

⏰ OPTIMAL SOLUTION: Dutch National Flag Algorithm
💾 TIME COMPLEXITY:  O(n) - Single pass through array
💾 SPACE COMPLEXITY: O(1) - Only using pointer variables
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    /**
     * @brief Sorts colors using Dutch National Flag algorithm (OPTIMAL)
     * @param nums Array of colors (0, 1, 2)
     * 
     * Algorithm (Three-way partitioning):
     * 1. Use three pointers: low (0s), mid (current), high (2s)
     * 2. Process elements: 0 → swap with low, 1 → move mid, 2 → swap with high
     * 3. Continue until mid crosses high
     */
    void sortColors(vector<int>& nums) {
        int low = 0;           // Boundary for 0s
        int mid = 0;           // Current element
        int high = nums.size() - 1;  // Boundary for 2s
        
        while (mid <= high) {
            if (nums[mid] == 0) {
                // Found 0: swap with low boundary and move both pointers
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                // Found 1: it's in correct position, just move mid
                mid++;
            } else { // nums[mid] == 2
                // Found 2: swap with high boundary, move high back
                swap(nums[mid], nums[high]);
                high--;
                // Don't increment mid as we need to check swapped element
            }
        }
    }
    
    /**
     * @brief Counting sort approach (for comparison)
     * @param nums Array of colors (0, 1, 2)
     */
    void sortColorsCountingSort(vector<int>& nums) {
        int count[3] = {0}; // count[0], count[1], count[2]
        
        // Count occurrences
        for (int num : nums) {
            count[num]++;
        }
        
        // Reconstruct array
        int index = 0;
        for (int color = 0; color < 3; color++) {
            for (int i = 0; i < count[color]; i++) {
                nums[index++] = color;
            }
        }
    }
    
    /**
     * @brief Two-pass approach (for comparison)
     * @param nums Array of colors (0, 1, 2)
     */
    void sortColorsTwoPass(vector<int>& nums) {
        int n = nums.size();
        
        // First pass: move all 0s to front
        int writeIndex = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                swap(nums[i], nums[writeIndex]);
                writeIndex++;
            }
        }
        
        // Second pass: move all 1s after 0s
        for (int i = writeIndex; i < n; i++) {
            if (nums[i] == 1) {
                swap(nums[i], nums[writeIndex]);
                writeIndex++;
            }
        }
        // 2s are automatically in correct position
    }
    
    /**
     * @brief Bubble sort approach (your original - for comparison)
     * @param nums Array of colors (0, 1, 2)
     */
    void sortColorsBubbleSort(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    swap(nums[j], nums[j + 1]);
                }
            }
        }
    }
    
    /**
     * @brief STL sort approach (violates constraint but for reference)
     * @param nums Array of colors (0, 1, 2)
     */
    void sortColorsSTL(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    }
};

/**
 * @brief Utility function to print array
 */
void printArray(const vector<int>& nums, const string& label) {
    cout << label << ": [";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

/**
 * @brief Test function for a single case
 */
void testCase(vector<int> nums, vector<int> expected, const string& description) {
    Solution solution;
    vector<int> original = nums;
    solution.sortColors(nums);
    
    string status = (nums == expected) ? "✅ PASSED" : "❌ FAILED";
    cout << status << ": " << description << endl;
    printArray(original, "  Input ");
    printArray(nums, "  Output");
    cout << endl;
    assert(nums == expected);
}

/**
 * @brief Comprehensive test function
 */
void runTests() {
    cout << "🧪 Running Comprehensive Tests:" << endl;
    cout << "===============================" << endl;
    
    // Test Case 1: Mixed colors
    testCase({2,0,2,1,1,0}, {0,0,1,1,2,2}, "Mixed colors example");
    
    // Test Case 2: Simple case
    testCase({2,0,1}, {0,1,2}, "Simple three colors");
    
    // Test Case 3: All same color
    testCase({0,0,0}, {0,0,0}, "All red (0s)");
    testCase({1,1,1}, {1,1,1}, "All white (1s)");
    testCase({2,2,2}, {2,2,2}, "All blue (2s)");
    
    // Test Case 4: Already sorted
    testCase({0,1,2}, {0,1,2}, "Already sorted");
    
    // Test Case 5: Reverse sorted
    testCase({2,1,0}, {0,1,2}, "Reverse sorted");
    
    // Test Case 6: Single element
    testCase({1}, {1}, "Single element");
    
    // Test Case 7: Two elements
    testCase({1,0}, {0,1}, "Two elements");
    
    // Test Case 8: Complex case
    testCase({2,0,2,1,1,0,1,2,0}, {0,0,0,1,1,1,2,2,2}, "Complex mixed case");
    
    cout << "🎉 All tests passed!" << endl;
}

/**
 * @brief Performance comparison demonstration
 */
void performanceComparison() {
    cout << "\n📊 Performance Comparison:" << endl;
    cout << "=========================" << endl;
    cout << "Approach              | Time     | Space | Passes | Optimal" << endl;
    cout << "----------------------|----------|-------|--------|--------" << endl;
    cout << "Dutch National Flag   | O(n)     | O(1)  |   1    |   ✅   " << endl;
    cout << "Counting Sort         | O(n)     | O(1)  |   2    |   ✅   " << endl;
    cout << "Two Pass              | O(n)     | O(1)  |   2    |   🟡   " << endl;
    cout << "Bubble Sort (yours)   | O(n²)    | O(1)  |  n-1   |   ❌   " << endl;
    cout << "STL Sort (violates)   | O(n log n)| O(1) |   1    |   ❌   " << endl;
    cout << "                      |          |       |        |        " << endl;
    cout << "Recommendation: Use Dutch National Flag for optimal O(n) solution!" << endl;
}

/**
 * @brief Step-by-step walkthrough of Dutch National Flag
 */
void stepByStepDemo() {
    cout << "\n💡 Step-by-step Walkthrough (Dutch National Flag):" << endl;
    cout << "==================================================" << endl;
    
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    cout << "Input: [2, 0, 2, 1, 1, 0]" << endl;
    cout << "Goal: Sort in single pass using three pointers" << endl << endl;
    
    cout << "Initial: low=0, mid=0, high=5" << endl;
    cout << "Array:   [2, 0, 2, 1, 1, 0]" << endl;
    cout << "          ^  ^           ^" << endl;
    cout << "         low mid        high" << endl << endl;
    
    cout << "Step 1: nums[mid]=2, swap with high, high--" << endl;
    cout << "Array:   [0, 0, 2, 1, 1, 2]" << endl;
    cout << "          ^  ^        ^" << endl;
    cout << "         low mid     high" << endl << endl;
    
    cout << "Step 2: nums[mid]=0, swap with low, low++, mid++" << endl;
    cout << "Array:   [0, 0, 2, 1, 1, 2]" << endl;
    cout << "             ^     ^" << endl;
    cout << "            low   mid" << endl << endl;
    
    cout << "Continue until mid > high..." << endl;
    cout << "Final:   [0, 0, 1, 1, 2, 2]" << endl;
}

/**
 * @brief Demonstrate different approaches
 */
void demonstrateApproaches() {
    Solution solution;
    vector<int> original = {2, 0, 2, 1, 1, 0};
    
    cout << "\n🔄 Comparing Different Approaches:" << endl;
    cout << "==================================" << endl;
    
    printArray(original, "Original");
    
    // Dutch National Flag
    vector<int> nums1 = original;
    solution.sortColors(nums1);
    printArray(nums1, "Dutch Flag");
    
    // Counting Sort
    vector<int> nums2 = original;
    solution.sortColorsCountingSort(nums2);
    printArray(nums2, "Counting  ");
    
    // Two Pass
    vector<int> nums3 = original;
    solution.sortColorsTwoPass(nums3);
    printArray(nums3, "Two Pass  ");
    
    // Bubble Sort
    vector<int> nums4 = original;
    solution.sortColorsBubbleSort(nums4);
    printArray(nums4, "Bubble    ");
}

/**
 * @brief Main function demonstrating the solution
 */
int main() {
    cout << "🎨 LeetCode 75: Sort Colors" << endl;
    cout << "===========================" << endl;
    
    // Run comprehensive tests
    runTests();
    
    // Performance comparison
    performanceComparison();
    
    // Step-by-step demonstration
    stepByStepDemo();
    
    // Demonstrate different approaches
    demonstrateApproaches();
    
    cout << "\n🚀 Key Insight:" << endl;
    cout << "===============" << endl;
    cout << "Dutch National Flag algorithm partitions array in single pass:" << endl;
    cout << "[0s region] [1s region] [unknown] [2s region]" << endl;
    cout << "     low        mid                  high" << endl;
    
    return 0;
}

/*
🎯 KEY LEARNINGS:
1. Dutch National Flag algorithm achieves O(n) time with single pass
2. Three-way partitioning is optimal for problems with 3 distinct values
3. Counting sort works well when range of values is small and known
4. Always consider if problem constraints allow for specialized algorithms

🚀 RELATED PROBLEMS:
- LeetCode 215: Kth Largest Element in Array
- LeetCode 324: Wiggle Sort II
- LeetCode 280: Wiggle Sort
- LeetCode 148: Sort List

📚 CONCEPTS PRACTICED:
- Dutch National Flag algorithm
- Three-way partitioning
- In-place array manipulation
- Multiple sorting approaches
- Time complexity optimization
*/