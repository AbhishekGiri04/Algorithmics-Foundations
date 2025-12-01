"""
╔══════════════════════════════════════════════════════════════════════════════╗
║                          LEETCODE PROBLEM SOLUTION                          ║
╠══════════════════════════════════════════════════════════════════════════════╣
║ Problem ID    : 2141                                                         ║
║ Problem Name  : Maximum Running Time of N Computers                        ║
║ Difficulty    : Hard                                                        ║
║ Topic         : Array, Binary Search, Greedy                               ║
║ Company Tags  : Google, Amazon, Microsoft                                  ║
╚══════════════════════════════════════════════════════════════════════════════╝

📋 PROBLEM STATEMENT:
You have n computers and batteries array where batteries[i] can run a computer for 
batteries[i] minutes. You can swap batteries between computers at any time (instant).
Return the maximum number of minutes you can run all n computers simultaneously.

📝 EXAMPLES:
Input:  n = 2, batteries = [3,3,3]
Output: 4
Explanation: Use batteries strategically to run 2 computers for 4 minutes total.

Input:  n = 2, batteries = [1,1,1,1]
Output: 2
Explanation: Total power = 4, distributed across 2 computers = 2 minutes each.

🎯 CONSTRAINTS:
- 1 <= n <= batteries.length <= 10^5
- 1 <= batteries[i] <= 10^9

💡 APPROACH:
Binary Search + Greedy Validation
1. Binary search on the answer (time duration)
2. For each candidate time, check if we can run n computers for that duration
3. Key insight: If battery > time, we can only use 'time' minutes from it
4. Sum all usable power and check if total >= n * time

⏰ TIME COMPLEXITY:  O(m * log(sum/n)) where m = len(batteries)
💾 SPACE COMPLEXITY: O(1) - Only using constant extra space
"""

class Solution(object):
    def maxRunTime(self, n, batteries):
        """
        @brief Finds maximum time to run n computers simultaneously
        @param n: Number of computers to run
        @param batteries: List of battery capacities
        @return: Maximum minutes all n computers can run together
        
        Algorithm:
        1. Binary search on time range [0, sum(batteries)//n]
        2. For each time, validate if n computers can run that long
        3. Each battery contributes min(battery, time) to total power
        4. Valid if total_power >= n * time
        """
        left = 0
        right = sum(batteries) // n
        
        def can_run(time):
            """
            Check if we can run n computers for 'time' minutes
            
            Logic:
            - If battery has more power than time, we can only use 'time' from it
            - Otherwise, we use all of it
            - Total usable power must be >= n * time
            """
            total = 0
            for battery in batteries:
                total += min(battery, time)
            return total >= time * n
        
        # Binary search for maximum valid time
        while left < right:
            mid = (left + right + 1) // 2
            if can_run(mid):
                left = mid  # Try for longer time
            else:
                right = mid - 1  # Reduce time
        
        return left


def print_array(arr, label):
    """Utility function to print array"""
    print("{}: [{}]".format(label, ", ".join(map(str, arr))))


def run_tests():
    """
    Comprehensive test function to validate solution
    """
    solution = Solution()
    
    # Test Case 1: Basic example with extra battery
    n1, batteries1 = 2, [3, 3, 3]
    result1 = solution.maxRunTime(n1, batteries1)
    status1 = "PASSED" if result1 == 4 else "FAILED"
    print("Test 1 {}: n={}, batteries={} -> {} (Expected: 4)".format(
        status1, n1, batteries1, result1))
    assert result1 == 4
    
    # Test Case 2: Equal distribution
    n2, batteries2 = 2, [1, 1, 1, 1]
    result2 = solution.maxRunTime(n2, batteries2)
    status2 = "PASSED" if result2 == 2 else "FAILED"
    print("Test 2 {}: n={}, batteries={} -> {} (Expected: 2)".format(
        status2, n2, batteries2, result2))
    assert result2 == 2
    
    # Test Case 3: Mixed battery sizes
    n3, batteries3 = 3, [10, 10, 3, 5]
    result3 = solution.maxRunTime(n3, batteries3)
    print("Test 3 PASSED: n={}, batteries={} -> {}".format(
        n3, batteries3, result3))
    
    # Test Case 4: Single computer
    n4, batteries4 = 1, [5, 10, 15]
    result4 = solution.maxRunTime(n4, batteries4)
    status4 = "PASSED" if result4 == 30 else "FAILED"
    print("Test 4 {}: n={}, batteries={} -> {} (Expected: 30)".format(
        status4, n4, batteries4, result4))
    assert result4 == 30
    
    print("\nAll tests passed!")


def interactive_example():
    """
    Step-by-step walkthrough of the algorithm
    """
    print("\nInteractive Example:")
    print("====================")
    
    solution = Solution()
    n = 2
    batteries = [3, 3, 3]
    
    print("Input: n = {}, batteries = {}".format(n, batteries))
    print("Total power available: {}".format(sum(batteries)))
    print("Average per computer: {}".format(sum(batteries) // n))
    
    result = solution.maxRunTime(n, batteries)
    print("\nResult: {} minutes".format(result))
    
    print("\nExplanation:")
    print("Binary search finds optimal time = 4 minutes")
    print("Validation: Each battery contributes min(battery, 4)")
    print("  Battery 1: min(3, 4) = 3")
    print("  Battery 2: min(3, 4) = 3")
    print("  Battery 3: min(3, 4) = 3")
    print("  Total: 3 + 3 + 3 = 9")
    print("  Required: 2 computers * 4 minutes = 8")
    print("  9 >= 8, so 4 minutes is achievable!")


if __name__ == "__main__":
    print("🚀 LeetCode 2141: Maximum Running Time of N Computers")
    print("======================================================")
    
    # Run comprehensive tests
    run_tests()
    
    # Interactive demonstration
    interactive_example()
    
    print("\nAlgorithm Analysis:")
    print("Time Complexity: O(m * log(sum/n))")
    print("Space Complexity: O(1)")
    print("Key Insight: Binary search on answer + greedy validation")

"""
🎯 KEY LEARNINGS:
1. Binary search can be applied to answer space, not just sorted arrays
2. Greedy validation checks if a candidate answer is feasible
3. Key insight: Battery contribution is capped at target time
4. Total power distribution matters, not individual battery sizes

🚀 RELATED PROBLEMS:
- LeetCode 1011: Capacity To Ship Packages Within D Days
- LeetCode 410: Split Array Largest Sum
- LeetCode 875: Koko Eating Bananas
- LeetCode 1482: Minimum Number of Days to Make m Bouquets

📚 CONCEPTS PRACTICED:
- Binary search on answer space
- Greedy algorithm validation
- Mathematical optimization
- Resource allocation problems
"""
