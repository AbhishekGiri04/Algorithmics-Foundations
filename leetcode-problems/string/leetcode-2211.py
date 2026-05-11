/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                          LEETCODE PROBLEM SOLUTION                           ║
╠══════════════════════════════════════════════════════════════════════════════╣
║ Problem ID    : 2211                                                         ║
║ Problem Name  : Count Collisions on a Road                                   ║
║ Difficulty    : Medium                                                       ║
║ Topic         : String, Stack, Simulation                                    ║
╚══════════════════════════════════════════════════════════════════════════════╝

📋 PROBLEM STATEMENT:
Count total collisions among cars moving Left (L), Right (R), or Stationary (S).

⏰ TIME COMPLEXITY: O(n)
💾 SPACE COMPLEXITY: O(1)
*/

class Solution:
    def countCollisions(self, directions: str) -> int:

        stack = []
        collisions = 0

        for c in directions:

            if c == 'R':
                stack.append('R')

            elif c == 'S':
                while stack and stack[-1] == 'R':
                    stack.pop()
                    collisions += 1
                stack.append('S')

            else:  
                while stack and stack[-1] == 'R':
                    stack.pop()
                    collisions += 2

                if stack and stack[-1] == 'S':
                    collisions += 1
                else:
                    collisions += len(stack)

                stack = ['S']

        return collisions