"""
╔══════════════════════════════════════════════════════════════════════════════╗
║                          LEETCODE PROBLEM SOLUTION                           ║
╠══════════════════════════════════════════════════════════════════════════════╣
║ Problem ID    : 2141                                                         ║
║ Problem Name  : Maximum Running Time of N Computers                          ║
║ Difficulty    : Hard                                                         ║
║ Topic         : Array, Binary Search, Greedy                                 ║
╚══════════════════════════════════════════════════════════════════════════════╝

📋 PROBLEM STATEMENT:
You have n computers and batteries array where batteries[i] can run a computer
for batteries[i] minutes. You can swap batteries freely.

Return maximum time all n computers can run simultaneously.

⏰ TIME COMPLEXITY: O(m log(sum/n))
💾 SPACE COMPLEXITY: O(1)
"""

def maxRunTime(n, batteries):
    left, right = 0, sum(batteries) // n

    def can_run(time):
        total = 0
        for b in batteries:
            total += min(b, time)
        return total >= time * n

    while left < right:
        mid = (left + right + 1) // 2

        if can_run(mid):
            left = mid
        else:
            right = mid - 1

    return left