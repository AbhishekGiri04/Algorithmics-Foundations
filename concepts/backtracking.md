<div align="center">

# 🚀 Backtracking Fundamentals

*Mastering Exhaustive Search with Intelligent Pruning*

---

![Backtracking](https://img.shields.io/badge/Topic-Backtracking-FF6B6B?style=for-the-badge&logo=databricks&logoColor=white)
![Difficulty](https://img.shields.io/badge/Level-Advanced-4ECDC4?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Reference-45B7D1?style=for-the-badge)

</div>

---

## 🎯 **Learning Objectives**

> *Master the art of exploring all possibilities with intelligent pruning*

- 🔍 Understand backtracking principles
- 🌳 Master recursive exploration patterns
- ✂️ Learn effective pruning techniques
- 🎯 Solve constraint satisfaction problems

---

## 📖 **1. What is Backtracking?**

<table>
<tr>
<td width="50%">

### 🔍 **Core Concept**
*Depth-first search with state reversal*

**Key Principle:**
- 🌳 Try all possibilities
- ✂️ Prune invalid paths
- ↩️ Undo and try alternatives

</td>
<td width="50%">

### ⚡ **The Backtracking Formula**
*Explore → Validate → Recurse → Undo*

**Process:**
- 🎯 Make a choice
- 🔍 Explore recursively
- ↩️ Undo the choice
- 🔄 Try next option

</td>
</tr>
</table>

### 🌟 **General Template**

```cpp
void backtrack(state, choices) {
    // Base case - goal achieved
    if (isGoal(state)) {
        storeResult(state);
        return;
    }
    
    // Try each possible choice
    for (choice in choices) {
        if (isValid(choice, state)) {
            makeChoice(choice);      // Choose
            backtrack(newState);     // Explore
            undoChoice(choice);      // Unchoose (Backtrack)
        }
    }
}
```

---

## 🧱 **2. Key Components**

### 📊 **Essential Elements**

<div align="center">

| Component | Description | Purpose | Example |
|:----------|:------------|:--------|:--------|
| **🎯 Choice** | Decision at current state | Explore options | Place queen at column i |
| **✅ Constraint** | Validity check | Prune invalid paths | Check diagonal attacks |
| **🔄 Recursion** | Explore next state | Build solution | Move to next row |
| **↩️ Backtrack** | Undo choice | Try alternatives | Remove queen |

</div>

---

## 🎯 **3. Classic Problems**

### 👑 **N-Queens Problem**

<table>
<tr>
<td width="50%">

**Problem:**  
Place N queens on N×N board so no two queens attack each other.

**Constraints:**
- ❌ Same row
- ❌ Same column
- ❌ Same diagonal

**Approach:**
1. Place one queen per row
2. Try each column
3. Check if safe
4. Recurse to next row
5. Backtrack if needed

</td>
<td width="50%">

**Implementation:**
```cpp
void solveNQueens(int row) {
    if (row == n) {
        result.push_back(board);
        return;
    }
    
    for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 'Q';
            solveNQueens(row + 1);
            board[row][col] = '.';
        }
    }
}
```

**Time:** O(N!)  
**Space:** O(N²)

</td>
</tr>
</table>

---

### 🔢 **Sudoku Solver**

<table>
<tr>
<td width="50%">

**Problem:**  
Fill 9×9 grid with digits 1-9 following Sudoku rules.

**Constraints:**
- Each row: 1-9 once
- Each column: 1-9 once
- Each 3×3 box: 1-9 once

**Approach:**
1. Find empty cell
2. Try digits 1-9
3. Check validity
4. Recurse if valid
5. Backtrack if stuck

</td>
<td width="50%">

**Validation:**
```cpp
bool isValid(int row, int col, char num) {
    // Check row
    for (int i = 0; i < 9; i++)
        if (board[row][i] == num) return false;
    
    // Check column
    for (int i = 0; i < 9; i++)
        if (board[i][col] == num) return false;
    
    // Check 3×3 box
    int startRow = (row/3) * 3;
    int startCol = (col/3) * 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[startRow+i][startCol+j] == num)
                return false;
    
    return true;
}
```

</td>
</tr>
</table>

---

### 🐀 **Rat in a Maze**

<table>
<tr>
<td width="50%">

**Problem:**  
Find all paths from (0,0) to (n-1,n-1) in a maze.

**Moves:**
- D (Down)
- R (Right)
- U (Up)
- L (Left)

**Constraints:**
- Stay in bounds
- Only visit open cells (1)
- Don't revisit cells

</td>
<td width="50%">

**Implementation:**
```cpp
void findPaths(int x, int y, string path) {
    if (x == n-1 && y == n-1) {
        result.push_back(path);
        return;
    }
    
    visited[x][y] = true;
    
    // Try all 4 directions
    if (isValid(x+1, y)) {
        findPaths(x+1, y, path + "D");
    }
    if (isValid(x, y+1)) {
        findPaths(x, y+1, path + "R");
    }
    if (isValid(x-1, y)) {
        findPaths(x-1, y, path + "U");
    }
    if (isValid(x, y-1)) {
        findPaths(x, y-1, path + "L");
    }
    
    visited[x][y] = false; // Backtrack
}
```

</td>
</tr>
</table>

---

## 📊 **4. Common Patterns**

### 🎯 **Problem Categories**

<div align="center">

| Pattern | Description | Examples | Complexity |
|:--------|:------------|:---------|:-----------|
| **🔢 Permutations** | All arrangements | Generate permutations | O(N!) |
| **🎲 Combinations** | Choose k from n | Subsets, combinations | O(2ⁿ) |
| **🧩 Constraint Satisfaction** | Meet all constraints | N-Queens, Sudoku | Exponential |
| **🗺️ Path Finding** | Find all paths | Maze, word search | O(4ⁿ) |
| **🎨 Coloring** | Assign colors | Graph coloring | Exponential |

</div>

---

## ⏱️ **5. Time Complexity Analysis**

### 📊 **Complexity Table**

<div align="center">

| Problem | Time Complexity | Space Complexity | Pruning Impact |
|:--------|:----------------|:-----------------|:---------------|
| **N-Queens** | O(N!) | O(N²) | High |
| **Sudoku** | O(9^m) where m = empty cells | O(1) | Very High |
| **Rat in Maze** | O(4^(n²)) | O(n²) | Medium |
| **Permutations** | O(N! × N) | O(N) | Low |
| **Subsets** | O(2ⁿ × N) | O(N) | Low |

</div>

---

## ✂️ **6. Pruning Techniques**

<table>
<tr>
<td width="50%">

### 🎯 **Early Termination**

**Stop exploring when:**
- Constraint violated
- Goal impossible to reach
- Better solution already found

**Example:**
```cpp
if (!isValid(choice)) {
    continue; // Skip this branch
}
```

</td>
<td width="50%">

### 🔍 **Constraint Propagation**

**Reduce search space by:**
- Checking constraints early
- Maintaining validity state
- Using heuristics

**Example:**
```cpp
if (col[i] || diag1[i] || diag2[i]) {
    continue; // Already occupied
}
```

</td>
</tr>
</table>

---

## 🎯 **7. Applications**

<table>
<tr>
<td width="50%">

### 🌍 **Real-World Uses**
- 🧩 Puzzle solving (Sudoku, crosswords)
- 🎮 Game AI (chess, checkers)
- 📅 Scheduling problems
- 🗺️ Route planning
- 🎨 Resource allocation

</td>
<td width="50%">

### 💻 **Algorithm Applications**
- 🔢 Generating permutations/combinations
- 🔍 Word search in grid
- 🎯 Subset sum problems
- 🌳 Tree/graph traversal
- 🧮 Constraint satisfaction

</td>
</tr>
</table>

---

## 💡 **8. Backtracking Mindset**

<div align="center">

### 🧠 **Key Questions to Ask**

</div>

> 🎯 **What choices can I make at this step?**  
> ✅ **Is this choice valid given current constraints?**  
> 🔍 **What happens after I make this choice?**  
> ↩️ **How do I undo this choice to try alternatives?**  
> 🏁 **When have I reached a complete solution?**  

---

## ⚖️ **9. Strengths & Weaknesses**

<table>
<tr>
<td width="50%">

### ✅ **Strengths**

- **🎯 Complete:** Finds all solutions
- **📝 Simple:** Easy to implement
- **🔍 Systematic:** Explores all possibilities
- **✂️ Prunable:** Can optimize with constraints
- **🧩 Versatile:** Works for many problems

</td>
<td width="50%">

### ❌ **Weaknesses**

- **⏱️ Slow:** Exponential time complexity
- **💾 Memory:** Can use significant stack space
- **📈 Scalability:** Poor for large inputs
- **🔄 Redundancy:** May revisit states
- **⚠️ Optimization:** Requires good pruning

</td>
</tr>
</table>

---

## 📘 **10. Problem Summary**

<div align="center">

| Problem | Goal | Key Checks | Time Complexity |
|:--------|:-----|:-----------|:----------------|
| **N-Queens** | Place queens safely | Column, diagonals | O(N!) |
| **Sudoku** | Fill grid 1-9 | Row, column, box | O(9^m) |
| **Rat Maze** | Find all paths | Bounds, visited, open | O(4^(n²)) |
| **Permutations** | All arrangements | Used elements | O(N!) |
| **Subsets** | All combinations | Index tracking | O(2ⁿ) |

</div>

---

## 🎯 **11. Key Takeaways**

<div align="center">

### 💡 **Essential Insights**

</div>

> 🌳 **Backtracking = DFS + Undo**: Explore and reverse  
> ✂️ **Pruning is Critical**: Skip invalid branches early  
> 🎯 **State Management**: Track choices and constraints  
> ↩️ **Always Undo**: Restore state after exploration  
> 🧠 **Think Recursively**: Break into smaller decisions  

---

<div align="center">

### 📊 **Learning Progress**

![Progress](https://img.shields.io/badge/Completion-Reference-success?style=for-the-badge)
![Difficulty](https://img.shields.io/badge/Difficulty-Advanced-red?style=for-the-badge)

---

**📅 Topic**: Backtracking | **🎯 Focus**: Exhaustive Search | **⏰ Level**: Advanced

*"Backtracking: Try everything, but intelligently"*

</div>
