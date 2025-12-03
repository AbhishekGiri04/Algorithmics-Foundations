<div align="center">

# 🚀 Day 14: Heap & Priority Queue Fundamentals

*Mastering Efficient Priority-Based Data Management*

---

![Heap](https://img.shields.io/badge/Topic-Heap_Priority_Queue-FF6B6B?style=for-the-badge&logo=databricks&logoColor=white)
![Difficulty](https://img.shields.io/badge/Level-Intermediate-4ECDC4?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Completed-45B7D1?style=for-the-badge)

</div>

---

## 🎯 **Learning Objectives**

> *Achieve efficient priority management through heap data structures*

- 📦 Understand heap structure and properties
- ⚡ Master heap operations and heapify
- 🎯 Implement priority queues efficiently
- 🔧 Apply heaps to solve real problems

---

## 📖 **1. What is a Heap?**

<table>
<tr>
<td width="50%">

### 📦 **Core Concept**
*Complete binary tree with heap property*

**Key Properties:**
- 🌳 Complete binary tree
- 📊 Heap property maintained
- 🚀 Efficient operations

</td>
<td width="50%">

### ⚡ **Heap Types**
*Two main variants based on ordering*

**Max Heap:** Parent ≥ Children  
**Min Heap:** Parent ≤ Children

**Complete Tree:** All levels filled except last (left-aligned)

</td>
</tr>
</table>

### 🌟 **Visual Representation**

<table>
<tr>
<td width="50%">

#### **Max Heap**
```
        100
       /   \
     50     90
    /  \   / \
   20  40 30  10
```

**Property:** Root = Maximum

</td>
<td width="50%">

#### **Min Heap**
```
        10
       /   \
     20     30
    /  \   / \
   40  50 90  100
```

**Property:** Root = Minimum

</td>
</tr>
</table>

---

## 🏗️ **2. Heap Operations**

### 📊 **Core Operations**

<div align="center">

| Operation | Description | Time Complexity | Use Case |
|:----------|:------------|:----------------|:---------|
| **➕ Insert** | Add element and bubble up | O(log n) | Add priority item |
| **➖ Delete** | Remove root and heapify down | O(log n) | Extract max/min |
| **👁️ Peek** | View root element | O(1) | Check priority |
| **🔧 Heapify** | Build heap from array | O(n) | Initialize heap |

</div>

### 🔄 **Operation Details**

<table>
<tr>
<td width="50%">

#### **1️⃣ Insertion (Bubble Up)**

**Process:**
1. Add element at end
2. Compare with parent
3. Swap if heap property violated
4. Repeat until property satisfied

**Example (Max Heap):**
```
Insert 95:
   100          100          100
   / \    →    / \     →    / \
  50  90      50  90       95  90
 /           / \          / \
20          20  95       50  20
```

</td>
<td width="50%">

#### **2️⃣ Deletion (Bubble Down)**

**Process:**
1. Replace root with last element
2. Compare with children
3. Swap with larger child (max heap)
4. Repeat until property satisfied

**Example (Max Heap):**
```
Delete 100:
   100          20          90
   / \    →    / \     →   / \
  90  50      90  50      20  50
```

</td>
</tr>
</table>

---

## ⚡ **3. Heapify Algorithm**

### 🔧 **Building a Heap**

<table>
<tr>
<td width="50%">

#### **Max Heap Heapify**

```cpp
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && arr[left] > arr[largest])
        largest = left;
    
    if (right < n && arr[right] > arr[largest])
        largest = right;
    
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
```

</td>
<td width="50%">

#### **Build Heap**

```cpp
void buildHeap(int arr[], int n) {
    // Start from last non-leaf node
    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}
```

**Key Insight:**
- Start from last non-leaf: `n/2 - 1`
- Work backwards to root
- Time: O(n) not O(n log n)!

</td>
</tr>
</table>

---

## 🎯 **4. Priority Queue**

### 📊 **Abstract Data Type**

<div align="center">

| Feature | Description | Implementation |
|:--------|:------------|:---------------|
| **🎯 Priority-Based** | Elements served by priority | Heap |
| **⚡ Efficient** | O(log n) operations | Binary Heap |
| **🔄 Dynamic** | Insert/delete anytime | Flexible |

</div>

### 💻 **Implementation in C++**

<table>
<tr>
<td width="50%">

#### **Max Heap (Default)**

```cpp
#include <queue>
using namespace std;

// Max Heap
priority_queue<int> maxHeap;

maxHeap.push(10);
maxHeap.push(30);
maxHeap.push(20);

cout << maxHeap.top(); // 30
maxHeap.pop();
```

</td>
<td width="50%">

#### **Min Heap**

```cpp
#include <queue>
using namespace std;

// Min Heap
priority_queue<int, vector<int>, 
               greater<int>> minHeap;

minHeap.push(10);
minHeap.push(30);
minHeap.push(20);

cout << minHeap.top(); // 10
minHeap.pop();
```

</td>
</tr>
</table>

---

## ⏱️ **5. Time & Space Complexity**

### 📊 **Performance Analysis**

<div align="center">

| Operation | Time Complexity | Space Complexity | Notes |
|:----------|:----------------|:-----------------|:------|
| **Insert** | O(log n) | O(1) | Bubble up |
| **Delete** | O(log n) | O(1) | Bubble down |
| **Peek** | O(1) | O(1) | Direct access |
| **Heapify** | O(n) | O(1) | Build heap |
| **Heap Sort** | O(n log n) | O(1) | In-place |

</div>

### 📈 **Array Representation**

**Index Relationships:**
- Parent of `i`: `(i-1)/2`
- Left child of `i`: `2*i + 1`
- Right child of `i`: `2*i + 2`

---

## 🌟 **6. Applications of Heap**

<table>
<tr>
<td width="50%">

### 🌍 **Real-World Uses**
- 🖥️ CPU task scheduling
- 🎮 Game AI priority systems
- 📊 Event-driven simulation
- 🚦 Traffic management
- 📞 Call center routing

</td>
<td width="50%">

### 💻 **Algorithm Applications**
- 🔄 Heap Sort (O(n log n))
- 🗺️ Dijkstra's shortest path
- 🌳 Prim's MST algorithm
- 🔢 Kth largest/smallest
- 📊 Median in stream

</td>
</tr>
</table>

---

## 🎯 **7. Classic Heap Problems**

### 📘 **Must-Solve Problems**

<div align="center">

| Difficulty | Problem | Pattern | Priority |
|:-----------|:--------|:--------|:---------|
| **🟢 Easy** | Kth Largest Element | Max Heap | ⭐⭐⭐ |
| **🟢 Easy** | Last Stone Weight | Max Heap | ⭐⭐⭐ |
| **🟡 Medium** | Top K Frequent Elements | Min Heap | ⭐⭐⭐ |
| **🟡 Medium** | Kth Largest in Stream | Min Heap | ⭐⭐⭐ |
| **🟡 Medium** | Find Median from Data Stream | Two Heaps | ⭐⭐⭐ |
| **🟡 Medium** | Merge K Sorted Lists | Min Heap | ⭐⭐ |
| **🔴 Hard** | Sliding Window Median | Two Heaps | ⭐⭐ |
| **🔴 Hard** | IPO | Max + Min Heap | ⭐ |

</div>

---

## 🧠 **8. Heap vs Other Structures**

<div align="center">

| Structure | Insert | Delete | Find Min/Max | Use Case |
|:----------|:-------|:-------|:-------------|:---------|
| **Heap** | O(log n) | O(log n) | O(1) | Priority queue |
| **BST** | O(log n) | O(log n) | O(log n) | Ordered data |
| **Array (sorted)** | O(n) | O(n) | O(1) | Static data |
| **Array (unsorted)** | O(1) | O(n) | O(n) | No priority |

</div>

---

## 🎯 **9. Key Takeaways**

<div align="center">

### 💡 **Essential Insights**

</div>

> 📦 **Heap = Complete Binary Tree**: Efficient array representation  
> ⚡ **O(log n) Operations**: Fast insert and delete  
> 🎯 **Priority Queue**: Best implemented with heap  
> 🔧 **Heapify is O(n)**: Not O(n log n)!  

---

## 📚 **10. Next Steps**

<table>
<tr>
<td width="50%">

### 🎯 **Immediate Goals**
- [ ] Implement heap from scratch
- [ ] Solve Kth largest problem
- [ ] Practice heapify algorithm
- [ ] Master priority_queue STL

</td>
<td width="50%">

### 🚀 **Long-term Objectives**
- [ ] Solve 15+ heap problems
- [ ] Implement heap sort
- [ ] Master two-heap pattern
- [ ] Learn advanced heap variants

</td>
</tr>
</table>

---

<div align="center">

### 📊 **Learning Progress**

![Progress](https://img.shields.io/badge/Completion-100%25-success?style=for-the-badge)
![Time](https://img.shields.io/badge/Study_Time-2_Hours-blue?style=for-the-badge)
![Difficulty](https://img.shields.io/badge/Difficulty-Intermediate-orange?style=for-the-badge)

---

**📅 Session Date**: Day 14 | **🎯 Focus**: Heap & Priority Queue | **⏰ Duration**: Deep Learning Session

*"Heap: Where priority meets efficiency"*

</div>
