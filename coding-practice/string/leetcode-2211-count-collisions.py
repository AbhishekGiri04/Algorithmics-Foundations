"""
╔══════════════════════════════════════════════════════════════════════════════╗
║                          LEETCODE PROBLEM SOLUTION                          ║
╠══════════════════════════════════════════════════════════════════════════════╣
║ Problem ID    : 2211                                                         ║
║ Problem Name  : Count Collisions on a Road                                  ║
║ Difficulty    : Medium                                                       ║
║ Topic         : String, Simulation, Greedy                                  ║
║ Company Tags  : Amazon, Google                                              ║
╚══════════════════════════════════════════════════════════════════════════════╝

📋 PROBLEM STATEMENT:
Given a string representing car directions ('L', 'R', 'S'), count total collisions.
- 'L': moving left
- 'R': moving right  
- 'S': stationary

Collision rules:
- Opposite directions: +2 collisions
- Moving hits stationary: +1 collision

📝 EXAMPLES:
Input:  directions = "RLRSLL"
Output: 5
Explanation: Multiple collisions occur as cars meet.

Input:  directions = "LLRR"
Output: 0
Explanation: No cars collide (all moving away).

🎯 CONSTRAINTS:
- 1 <= directions.length <= 10^5
- directions[i] is 'L', 'R', or 'S'

💡 APPROACH:
Greedy String Processing
1. Remove leading 'L' (cars moving left from start - no collision)
2. Remove trailing 'R' (cars moving right to end - no collision)
3. Count remaining non-'S' cars (all will collide and become stationary)

Key Insight: After removing edge cases, all moving cars in middle will collide.

⏰ TIME COMPLEXITY:  O(n) - Single pass through string
💾 SPACE COMPLEXITY: O(n) - String operations create new strings
"""

class Solution(object):
    def countCollisions(self, directions):
        """
        @brief Counts total collisions on the road
        @param directions: String of car directions ('L', 'R', 'S')
        @return: Total number of collisions
        
        Algorithm:
        1. Strip leading 'L' - cars moving left from start never collide
        2. Strip trailing 'R' - cars moving right to end never collide
        3. Count remaining non-'S' cars - all will collide
        
        Logic:
        - Leading 'L': No car ahead to collide with
        - Trailing 'R': No car behind to collide with
        - Middle cars: All moving cars will eventually collide
        """
        # Remove cars that never collide
        directions = directions.lstrip('L')  # Remove leading left-moving cars
        directions = directions.rstrip('R')  # Remove trailing right-moving cars
        
        # Count remaining moving cars (all will collide)
        return sum(c != 'S' for c in directions)


def test_solution():
    """Comprehensive test cases"""
    solution = Solution()
    
    # Test Case 1: Multiple collisions
    directions1 = "RLRSLL"
    result1 = solution.countCollisions(directions1)
    print("Test 1: {} (Expected: 5)".format(result1))
    assert result1 == 5
    
    # Test Case 2: No collisions
    directions2 = "LLRR"
    result2 = solution.countCollisions(directions2)
    print("Test 2: {} (Expected: 0)".format(result2))
    assert result2 == 0
    
    # Test Case 3: All stationary
    directions3 = "SSS"
    result3 = solution.countCollisions(directions3)
    print("Test 3: {} (Expected: 0)".format(result3))
    assert result3 == 0
    
    # Test Case 4: Simple collision
    directions4 = "RL"
    result4 = solution.countCollisions(directions4)
    print("Test 4: {} (Expected: 2)".format(result4))
    assert result4 == 2
    
    # Test Case 5: Edge case with leading L
    directions5 = "LLRS"
    result5 = solution.countCollisions(directions5)
    print("Test 5: {} (Expected: 1)".format(result5))
    assert result5 == 1
    
    print("\nAll tests passed!")


def explain_solution():
    """Step-by-step explanation"""
    print("\nAlgorithm Explanation:")
    print("=" * 50)
    
    example = "RLRSLL"
    print("Input: '{}'".format(example))
    
    step1 = example.lstrip('L')
    print("\nStep 1: Remove leading 'L'")
    print("  Result: '{}'".format(step1))
    print("  Reason: Cars moving left from start never collide")
    
    step2 = step1.rstrip('R')
    print("\nStep 2: Remove trailing 'R'")
    print("  Result: '{}'".format(step2))
    print("  Reason: Cars moving right to end never collide")
    
    collisions = sum(c != 'S' for c in step2)
    print("\nStep 3: Count non-'S' cars")
    print("  Remaining: '{}'".format(step2))
    print("  Non-stationary: {}".format(collisions))
    print("  Result: {} collisions".format(collisions))
    
    print("\nKey Insight:")
    print("All remaining moving cars will collide and become stationary.")


if __name__ == "__main__":
    print("🚀 LeetCode 2211: Count Collisions on a Road")
    print("=" * 50)
    
    # Run tests
    test_solution()
    
    # Explain solution
    explain_solution()
    
    print("\n📊 Complexity Analysis:")
    print("Time: O(n) - Single pass through string")
    print("Space: O(n) - String operations")

"""
🎯 KEY LEARNINGS:
1. Greedy approach: Remove edge cases first
2. Leading 'L' and trailing 'R' never collide
3. All middle moving cars will eventually collide
4. String strip operations simplify logic

🚀 RELATED PROBLEMS:
- LeetCode 735: Asteroid Collision
- LeetCode 844: Backspace String Compare
- LeetCode 1047: Remove All Adjacent Duplicates

📚 CONCEPTS PRACTICED:
- String manipulation
- Greedy algorithm
- Edge case handling
- Pattern recognition
"""
