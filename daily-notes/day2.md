# Day 2 - Array Data Structure (DSA) - Organized Notes

## 📚 1. Introduction to Arrays

Arrays are **linear data structures** that store elements in **contiguous memory locations**. They allow fast access using indices and are widely used in almost every algorithm and application.

### 🎯 Why Arrays Matter?

* ⚡ Fast random access (O(1))
* 🔧 Simple and efficient structure
* 🏗️ Foundation for advanced structures like matrices, heaps, hashing
* 💼 Most interview DSA problems start with arrays

---

## 🧩 2. Characteristics of Arrays

* **Indexed structure** → each element accessed via index
* **Fixed size** (in static arrays like C/C++)
* **Contiguous memory allocation**
* **Homogeneous data** → same data type elements

### ▶️ Example

```cpp
int arr[5] = {10, 20, 30, 40, 50};
```

---

## ⚙️ 3. Array Operations & Time Complexity

| Operation     | Description              | Time Complexity |
| ------------- | ------------------------ | --------------- |
| **Access**    | arr[i]                   | O(1)            |
| **Search**    | Find an element          | O(n)            |
| **Insertion** | Insert at specific index | O(n)            |
| **Deletion**  | Delete at specific index | O(n)            |

### 🚀 Why insertion/deletion is O(n)?

Because shifting of elements is required.

---

## 📝 4. Types of Arrays

### A. **One-Dimensional Array**

Basic linear list.

```cpp
int arr[4] = {1,2,3,4};
```

### B. **Multi-Dimensional Array**

Mostly used: **2D Arrays (Matrix)**

```cpp
int matrix[2][3] = {{1,2,3},{4,5,6}};
```

### C. **Dynamic Arrays (in C++ → vector)**

Resizable arrays.

```cpp
vector<int> nums = {1,2,3};
nums.push_back(4);
```

---

## 🧠 5. Common Array-Based Problems

* Running Sum
* Prefix Sum
* Kadane's Algorithm
* Two Pointer Problems
* Sliding Window Problems
* Searching (Linear / Binary Search)
* Sorting

These problems help build strong foundation and pattern recognition.

---

## 🧪 6. Applications of Arrays

* Used for storing sequential data
* Basis of strings, matrices
* Implement stacks & heaps internally
* Used in hashing (hash table buckets)
* Essential for DP (dp[] arrays)

---

## 🛠️ 7. Important Concepts Linked with Arrays

### ⭐ **Prefix Sum**

Used for fast range queries.

### ⭐ **Sliding Window Technique**

Used for subarray problems.

### ⭐ **Two Pointers**

Used for sorted arrays or pair problems.

### ⭐ **Kadane's Algorithm**

Maximum subarray sum.

---

## 🧩 8. Advantages & Disadvantages

### ✅ Advantages

* Fast access
* Easy to use
* Memory-efficient

### ❌ Disadvantages

* Fixed size (static arrays)
* Expensive insert/delete
* Inefficient memory usage if array mostly empty

---

## 📈 9. Visual Representation

```
Index:   0   1   2   3   4
Value:  10  20  30  40  50
```

Each index directly maps to memory location using:

```
Address = Base Address + (Index * Size of datatype)
```

---

## 🔥 10. Interview-Level Topics for Arrays

* Prefix Sum and Difference Arrays
* Sliding Window Optimization
* Dutch National Flag (3-way partition)
* Kadanes + Variants
* Rotate Array
* Two Sum / Three Sum
* Binary Search on Answer

---

## 🎯 Key Takeaways

* Arrays are the simplest yet most powerful data structure.
* Mastering them is essential before moving to linked lists or trees.
* 70% of beginner-level DSA problems are array-based.
* Practice pattern-based approaches (two pointers, prefix sum, sliding window).

---

**📅 Date**: Day 2 Learning Session  
**🎯 Focus**: Arrays - Fundamentals, Operations & Patterns  
**⏰ Duration**: Deep dive session