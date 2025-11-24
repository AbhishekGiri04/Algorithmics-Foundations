/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                          LEETCODE PROBLEM SOLUTION                          ║
╠══════════════════════════════════════════════════════════════════════════════╣
║ Problem ID    : 9                                                            ║
║ Problem Name  : Palindrome Number                                           ║
║ Difficulty    : Easy                                                         ║
║ Topic         : Math, Number Manipulation                                   ║
║ Company Tags  : Amazon, Apple, Microsoft, Google, Facebook                  ║
╚══════════════════════════════════════════════════════════════════════════════╝

📋 PROBLEM STATEMENT:
Given an integer x, return true if x is a palindrome, and false otherwise.
A palindrome number reads the same backward as forward.

📝 EXAMPLES:
Input:  x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.

Input:  x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-.

Input:  x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

🎯 CONSTRAINTS:
- -2^31 <= x <= 2^31 - 1

💡 APPROACHES:
1. String Conversion: Convert to string and check palindrome - O(log n) time, O(log n) space
2. Number Reversal: Reverse the number and compare - O(log n) time, O(1) space
3. Half Reversal: Reverse only half digits - O(log n) time, O(1) space (OPTIMAL)

⏰ OPTIMAL SOLUTION: Half reversal approach
💾 TIME COMPLEXITY:  O(log n) - Process each digit once
💾 SPACE COMPLEXITY: O(1) - Only using variables
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <cassert>
#include <climits>
using namespace std;

class Solution {
public:
    /**
     * @brief Checks if number is palindrome using half reversal (OPTIMAL)
     * @param x Input integer to check
     * @return bool True if palindrome, false otherwise
     * 
     * Algorithm:
     * 1. Handle negative numbers (always false)
     * 2. Handle single digits (always true)
     * 3. Reverse only half the digits
     * 4. Compare original half with reversed half
     */
    bool isPalindrome(int x) {
        // Negative numbers are not palindromes
        if (x < 0) return false;
        
        // Single digit numbers are palindromes
        if (x < 10) return true;
        
        // Numbers ending with 0 (except 0) are not palindromes
        if (x % 10 == 0) return false;
        
        int reversed = 0;
        
        // Reverse half the number
        while (x > reversed) {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }
        
        // For even digits: x == reversed
        // For odd digits: x == reversed / 10 (ignore middle digit)
        return x == reversed || x == reversed / 10;
    }
    
    /**
     * @brief Full number reversal approach (for comparison)
     * @param x Input integer to check
     * @return bool True if palindrome, false otherwise
     */
    bool isPalindromeFullReversal(int x) {
        if (x < 0) return false;
        
        long long original = x;
        long long reversed = 0;
        
        while (x > 0) {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }
        
        return original == reversed;
    }
    
    /**
     * @brief String conversion approach (for comparison)
     * @param x Input integer to check
     * @return bool True if palindrome, false otherwise
     */
    bool isPalindromeString(int x) {
        if (x < 0) return false;
        
        string s = to_string(x);
        string reversed = s;
        reverse(reversed.begin(), reversed.end());
        
        return s == reversed;
    }
    
    /**
     * @brief Two-pointer approach on string (for comparison)
     * @param x Input integer to check
     * @return bool True if palindrome, false otherwise
     */
    bool isPalindromeTwoPointer(int x) {
        if (x < 0) return false;
        
        string s = to_string(x);
        int left = 0, right = s.length() - 1;
        
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        
        return true;
    }
};

/**
 * @brief Utility function to test a single case
 */
void testCase(int x, bool expected, const string& description) {
    Solution solution;
    bool result = solution.isPalindrome(x);
    string status = (result == expected) ? "✅ PASSED" : "❌ FAILED";
    cout << status << ": " << description << " -> " << (result ? "true" : "false") << endl;
    assert(result == expected);
}

/**
 * @brief Comprehensive test function
 */
void runTests() {
    cout << "🧪 Running Comprehensive Tests:" << endl;
    cout << "===============================" << endl;
    
    // Test Case 1: Positive palindrome
    testCase(121, true, "x = 121 (positive palindrome)");
    
    // Test Case 2: Negative number
    testCase(-121, false, "x = -121 (negative number)");
    
    // Test Case 3: Number ending with 0
    testCase(10, false, "x = 10 (ends with 0)");
    
    // Test Case 4: Single digit
    testCase(7, true, "x = 7 (single digit)");
    
    // Test Case 5: Zero
    testCase(0, true, "x = 0 (zero)");
    
    // Test Case 6: Large palindrome
    testCase(1221, true, "x = 1221 (even digits palindrome)");
    
    // Test Case 7: Large non-palindrome
    testCase(1234, false, "x = 1234 (not palindrome)");
    
    // Test Case 8: Edge case
    testCase(1000021, false, "x = 1000021 (large non-palindrome)");
    
    // Test Case 9: Another palindrome
    testCase(12321, true, "x = 12321 (odd digits palindrome)");
    
    cout << "\n🎉 All tests passed!" << endl;
}

/**
 * @brief Performance comparison demonstration
 */
void performanceComparison() {
    cout << "\n📊 Performance Comparison:" << endl;
    cout << "=========================" << endl;
    cout << "Approach           | Time     | Space | Pros & Cons" << endl;
    cout << "-------------------|----------|-------|-------------" << endl;
    cout << "Half Reversal      | O(log n) | O(1)  | Optimal, no overflow risk" << endl;
    cout << "Full Reversal      | O(log n) | O(1)  | Simple, but overflow risk" << endl;
    cout << "String Conversion  | O(log n) | O(log n) | Easy to understand" << endl;
    cout << "Two Pointer String | O(log n) | O(log n) | Intuitive approach" << endl;
    cout << "                   |          |       |" << endl;
    cout << "Recommendation: Use Half Reversal for optimal solution!" << endl;
}

/**
 * @brief Step-by-step walkthrough
 */
void stepByStepDemo() {
    cout << "\n💡 Step-by-step Walkthrough (Half Reversal):" << endl;
    cout << "============================================" << endl;
    
    int x = 12321;
    cout << "Input: x = " << x << endl;
    cout << "Goal: Check if palindrome using half reversal" << endl << endl;
    
    cout << "Step 1: x = 12321, reversed = 0" << endl;
    cout << "  x > reversed? 12321 > 0 ✓" << endl;
    cout << "  reversed = 0 * 10 + 12321 % 10 = 1" << endl;
    cout << "  x = 12321 / 10 = 1232" << endl << endl;
    
    cout << "Step 2: x = 1232, reversed = 1" << endl;
    cout << "  x > reversed? 1232 > 1 ✓" << endl;
    cout << "  reversed = 1 * 10 + 1232 % 10 = 12" << endl;
    cout << "  x = 1232 / 10 = 123" << endl << endl;
    
    cout << "Step 3: x = 123, reversed = 12" << endl;
    cout << "  x > reversed? 123 > 12 ✓" << endl;
    cout << "  reversed = 12 * 10 + 123 % 10 = 123" << endl;
    cout << "  x = 123 / 10 = 12" << endl << endl;
    
    cout << "Step 4: x = 12, reversed = 123" << endl;
    cout << "  x > reversed? 12 > 123 ✗ (Stop)" << endl << endl;
    
    cout << "Final Check:" << endl;
    cout << "  x == reversed / 10? 12 == 123 / 10 = 12 ✓" << endl;
    cout << "  Result: true (palindrome)" << endl;
}

/**
 * @brief Demonstrate different approaches
 */
void demonstrateApproaches() {
    Solution solution;
    int testNum = 1221;
    
    cout << "\n🔄 Comparing Different Approaches for x = " << testNum << ":" << endl;
    cout << "========================================================" << endl;
    
    cout << "Half Reversal:     " << (solution.isPalindrome(testNum) ? "true" : "false") << endl;
    cout << "Full Reversal:     " << (solution.isPalindromeFullReversal(testNum) ? "true" : "false") << endl;
    cout << "String Conversion: " << (solution.isPalindromeString(testNum) ? "true" : "false") << endl;
    cout << "Two Pointer:       " << (solution.isPalindromeTwoPointer(testNum) ? "true" : "false") << endl;
}

/**
 * @brief Main function demonstrating the solution
 */
int main() {
    cout << "🔢 LeetCode 9: Palindrome Number" << endl;
    cout << "================================" << endl;
    
    // Run comprehensive tests
    runTests();
    
    // Performance comparison
    performanceComparison();
    
    // Step-by-step demonstration
    stepByStepDemo();
    
    // Demonstrate different approaches
    demonstrateApproaches();
    
    cout << "\n🚀 Interactive Examples:" << endl;
    cout << "========================" << endl;
    
    Solution solution;
    vector<int> examples = {121, -121, 10, 0, 12321, 1234};
    
    for (int x : examples) {
        bool result = solution.isPalindrome(x);
        cout << "isPalindrome(" << x << ") = " << (result ? "true" : "false") << endl;
    }
    
    return 0;
}

/*
🎯 KEY LEARNINGS:
1. Half reversal is more efficient than full reversal
2. Handle edge cases: negative numbers, numbers ending with 0
3. Avoid integer overflow by using half reversal technique
4. Mathematical approach is more space-efficient than string conversion

🚀 RELATED PROBLEMS:
- LeetCode 7: Reverse Integer
- LeetCode 234: Palindrome Linked List
- LeetCode 125: Valid Palindrome
- LeetCode 680: Valid Palindrome II

📚 CONCEPTS PRACTICED:
- Number manipulation and digit extraction
- Mathematical palindrome checking
- Edge case handling
- Space-time complexity optimization
- Multiple solution approaches comparison
*/