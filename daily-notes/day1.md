# Day 1 - Data Structures & Algorithms (DSA) - Organized Notes

## 📚 1. Introduction

**Data Structures**: Ways to store and organize data efficiently.  
**Algorithms**: Step-by-step procedures to solve computational problems.

### 🎯 Importance of DSA:
- ⚡ Optimizes performance of code
- 🧩 Solves complex problems efficiently  
- 💼 Core skill for coding interviews and real-world applications

---

## 🗂️ 2. Classification of Data Structures

### A. Linear Data Structures
*Elements stored in a sequential manner.*

#### 📊 **Array**
- Fixed size, contiguous memory
- **Operations**: traversal, insertion, deletion, search
- **Example**: `int arr[5] = {1,2,3,4,5};`

#### 🔗 **Linked List**
- Dynamic size, nodes connected via pointers
- **Types**: Singly, Doubly, Circular
- **Operations**: traversal, insertion, deletion

#### 📚 **Stack (LIFO)**
- Last In First Out
- **Operations**: `push()`, `pop()`, `peek()`
- **Applications**: Undo mechanism, expression evaluation

#### 🚶 **Queue (FIFO)**
- First In First Out
- **Types**: Simple Queue, Circular Queue, Priority Queue, Deque
- **Applications**: Task scheduling, buffering

### B. Non-Linear Data Structures
*Elements stored in hierarchical / graph form.*

#### 🌳 **Tree**
- Root-based hierarchical structure
- **Types**: Binary Tree, Binary Search Tree (BST), AVL Tree, Heap, Trie
- **Applications**: Search optimization, indexing, compiler design

#### 🕸️ **Graph**
- Nodes (vertices) connected via edges
- **Types**: Directed/Undirected, Weighted/Unweighted
- **Representation**: Adjacency List, Adjacency Matrix
- **Applications**: Social networks, shortest path problems, routing

### C. Hashing
- Store data with key-value mapping for fast access
- Uses hash functions
- **Applications**: Databases, caching, password storage

---

## ⚙️ 3. Algorithm Classification

### 🔍 **Searching Algorithms**
- Linear Search, Binary Search
- **Applications**: Find element in data

### 🔄 **Sorting Algorithms**
- Bubble, Selection, Insertion, Merge, Quick, Heap Sort
- **Applications**: Efficient data organization

### 🔁 **Recursive Algorithms**
- Function calls itself
- **Applications**: Tree traversal, factorial, Fibonacci

### ⚡ **Divide and Conquer**
- Break problem into subproblems, solve recursively
- **Examples**: Merge Sort, Quick Sort

### 🎯 **Greedy Algorithms**
- Make locally optimal choice at each step
- **Examples**: Kruskal's MST, Huffman Coding

### 🧮 **Dynamic Programming**
- Solve problems by breaking into subproblems and storing solutions
- **Examples**: Knapsack, Longest Common Subsequence

### 🌐 **Graph Algorithms**
- BFS, DFS, Dijkstra, Bellman-Ford, Floyd-Warshall

---

## 📈 4. Big-O Notation (Complexity Analysis)

**Time Complexity**: How execution time grows with input size  
**Space Complexity**: How memory usage grows with input size

### 📊 Common DS Operations Complexity:

| Data Structure | Access | Search | Insertion | Deletion |
|:---------------|:-------|:-------|:----------|:---------|
| **Array** | O(1) | O(n) | O(n) | O(n) |
| **Linked List** | O(n) | O(n) | O(1) | O(1) |
| **Stack/Queue** | O(n) | O(n) | O(1) | O(1) |
| **BST** | O(log n) avg, O(n) worst | O(log n) | O(log n) | O(log n) |

### 🚀 Common Time Complexities (Best to Worst):
- **O(1)** - Constant
- **O(log n)** - Logarithmic  
- **O(n)** - Linear
- **O(n log n)** - Linearithmic
- **O(n²)** - Quadratic
- **O(2ⁿ)** - Exponential

---

## 💡 Key Takeaways
- Choose appropriate data structure based on use case
- Understand trade-offs between time and space complexity
- Practice implementation and analysis of common algorithms
- Master Big-O notation for performance optimization

---

**📅 Date**: Day 1 Learning Session  
**🎯 Focus**: DSA Fundamentals and Classification  
**⏰ Duration**: Comprehensive overview session