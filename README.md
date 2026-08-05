<div align="center">

<!-- Animated Banner -->
<img src="https://capsule-render.vercel.app/api?type=waving&color=0:00599C,100:0080FF&height=200&section=header&text=C%2B%2B%20Algorithms&fontSize=52&fontColor=white&animation=fadeIn&fontAlignY=38&desc=Sorting%20%7C%20Graphs%20%7C%20Trees%20%7C%20DP%20%7C%20Data%20Structures&descAlignY=56&descSize=17" />

<br/>

<!-- Badges -->
<img src="https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white"/>
<img src="https://img.shields.io/badge/Topics-Algorithms%20%26%20DSA-0080FF?style=for-the-badge"/>
<img src="https://img.shields.io/badge/Level-Beginner%20to%20Advanced-green?style=for-the-badge"/>
<img src="https://img.shields.io/github/last-commit/Sahil-K-Y/Cpp-Algorithms?style=for-the-badge&color=blue&label=Last%20Updated"/>

<br/><br/>

<img src="https://readme-typing-svg.demolab.com?font=Fira+Code&size=20&pause=1000&color=00599C&center=true&vCenter=true&width=700&lines=Comprehensive+C%2B%2B+DSA+Library+%F0%9F%92%A1;Sorting+%7C+Searching+%7C+Graph+%7C+DP;Trees+%7C+Heaps+%7C+Hashing+%7C+Greedy;Clean+%26+Well-documented+Code+%E2%9C%85" alt="Typing SVG"/>

</div>

---

## 📋 Repository Overview

Welcome! This repository serves as a **comprehensive collection of C++ implementations** covering all major algorithms and data structures. It maps local C++ source files directly to their theoretical foundations and corresponding LeetCode/GFG practice problems.

Use this README as a master guide to revise code, review concepts, and track solving progress.

---

## 🗺️ Master Curriculum: Theory, Files & LeetCode Tracker

---

### 1. Sorting & Basic Searching
* **Theory:** Sorting rearranges elements into a monotonic order. Binary Search utilizes this order to repeatedly bisect the search space, reducing lookup times from $O(N)$ to $O(\log N)$.
* **In-Repo C++ Implementations:**
  * [bubble_sorting.cpp](./DSA/sorting/bubble_sorting.cpp) — Bubble Sort ($O(N^2)$ average/worst).
  * [selection_sort.cpp](./DSA/sorting/selection_sort.cpp) — Selection Sort ($O(N^2)$ comparisons).
  * [insertion_sort.cpp](./DSA/sorting/insertion_sort.cpp) — Insertion Sort ($O(N^2)$ worst, $O(N)$ best).
  * [merge_sorted_array.cpp](./DSA/sorting/merge_sorted_array.cpp) — Merge Sort ($O(N \log N)$ stable sorting).
  * [quick_sort.cpp](./DSA/sorting/quick_sort.cpp) — Quick Sort ($O(N \log N)$ average in-place sorting).
  * [binary_search.cpp](./DSA/array/binary_search.cpp) — Iterative & Recursive Binary Search ($O(\log N)$).
  * [book_allocation.cpp](./DSA/sorting/book_allocation.cpp) — Binary Search on Answer / Search Space partitioning.
* **Practice Tracker:**
  - [ ] Binary Search (LeetCode 704) 🔗 `binary_search.cpp`
  - [ ] Search in Rotated Sorted Array (LeetCode 33) 🔗 `rotated.cpp`
  - [ ] Find Peak Element (LeetCode 162) 🔗 `peak_index.cpp`
  - [ ] Single Element in Sorted Array (LeetCode 540) 🔗 `single_element.cpp`
  - [ ] Book Allocation Problem (GFG) 🔗 `book_allocation.cpp`

---

### 2. Arrays, Vectors & Two Pointers
* **Theory:** Arrays store elements contiguously in memory. Two pointers optimize searches by traversing from opposite boundaries (e.g. target sums) or moving at different speeds (e.g. partition boundaries) in $O(N)$ time.
* **In-Repo C++ Implementations:**
  * [two_sum.cpp](./DSA/array/two_sum.cpp) — Hash-based element checking.
  * [pair_sum.cpp](./DSA/array/pair_sum.cpp) / [triple_sum.cpp](./DSA/array/triple_sum.cpp) / [forth_sum.cpp](./DSA/array/forth_sum.cpp) — Multi-pointer checks for target sums.
  * [kadane.cpp](./DSA/array/kadane.cpp) — Maximum Subarray Sum using dynamic greed.
  * [majority.cpp](./DSA/array/majority.cpp) — Boyer-Moore Voting Algorithm.
  * [next_parmutation.cpp](./DSA/array/next_parmutation.cpp) — lexicographical next permutation permutation sequence.
  * [most_water_contain.cpp](./DSA/array/most_water_contain.cpp) — Two pointers container maximization.
  * [stock.cpp](./DSA/array/stock.cpp) — Single-pass min-valley tracking.
* **Practice Tracker:**
  - [ ] Two Sum (LeetCode 1) 🔗 `two_sum.cpp`
  - [ ] 3Sum (LeetCode 15) 🔗 `triple_sum.cpp`
  - [ ] 4Sum (LeetCode 18) 🔗 `forth_sum.cpp`
  - [ ] Next Permutation (LeetCode 31) 🔗 `next_parmutation.cpp`
  - [ ] Maximum Subarray (LeetCode 53) 🔗 `kadane.cpp`
  - [ ] Majority Element (LeetCode 169) 🔗 `majority.cpp`
  - [ ] Container With Most Water (LeetCode 11) 🔗 `most_water_contain.cpp`

---

### 3. Linked Lists
* **Theory:** Dynamically allocated node blocks linked via pointer memory addresses. Operations focus on redirection, maintaining dummy pointers to manage head mutations, and two-pointer slow/fast cycles.
* **In-Repo C++ Implementations:**
  * [reverse_linked_list.cpp](./DSA/linked%20list/reverse_linked_list.cpp) — In-place pointer reversal ($O(1)$ space).
  * [middle.cpp](./DSA/linked%20list/middle.cpp) — Finding list midpoint via fast/slow pointers.
  * [detect_cycle.cpp](./DSA/linked%20list/detect_cycle.cpp) — Floyd's cycle checking.
  * [mergeTwo.cpp](./DSA/linked%20list/mergeTwo.cpp) — Merging sorted lists recursively or iteratively.
  * [rev_k_node.cpp](./DSA/linked%20list/rev_k_node.cpp) — Reversing nodes in sets of K.
  * [rotated_ll.cpp](./DSA/linked%20list/rotated_ll.cpp) — Rotating lists around an index.
  * [intersection.cpp](./DSA/linked%20list/intersection.cpp) — Finding node intersections.
* **Practice Tracker:**
  - [ ] Reverse Linked List (LeetCode 206) 🔗 `reverse_linked_list.cpp`
  - [ ] Linked List Cycle (LeetCode 141) 🔗 `detect_cycle.cpp`
  - [ ] Merge Two Sorted Lists (LeetCode 21) 🔗 `mergeTwo.cpp`
  - [ ] Reverse Nodes in k-Group (LeetCode 25) 🔗 `rev_k_node.cpp`
  - [ ] Rotate List (LeetCode 61) 🔗 `rotated_ll.cpp`

---

### 4. Stacks & Queues
* **Theory:** Stacks follow LIFO (Last In First Out), optimal for backtracking, parentheses, and Monotonic Stack updates. Queues follow FIFO (First In First Out), optimal for BFS.
* **In-Repo C++ Implementations:**
  * [valid_paranthesis.cpp](./DSA/stack/valid_paranthesis.cpp) — Stack-based matching invariants.
  * [next_greater_element.cpp](./DSA/stack/next_greater_element.cpp) — Monotonic Stack next greater index check.
  * [histogram.cpp](./DSA/stack/histogram.cpp) / [largest_rectangle.cpp](./DSA/stack/largest_rectangle.cpp) — Stack-based area calculation.
  * [circularQueue.cpp](./DSA/queue/circularQueue.cpp) — Array-based queue checking.
  * [queue_using_stack.cpp](./DSA/queue/queue_using_stack.cpp) — Two-stack FIFO queue simulation.
  * [slidingwindowmaximum.cpp](./DSA/queue/slidingwindowmaximum.cpp) — Monotonic Deque index checking.
* **Practice Tracker:**
  - [ ] Valid Parentheses (LeetCode 20) 🔗 `valid_paranthesis.cpp`
  - [ ] Next Greater Element I (LeetCode 496) 🔗 `next_greater_element.cpp`
  - [ ] Sliding Window Maximum (LeetCode 239) 🔗 `slidingwindowmaximum.cpp`
  - [ ] Largest Rectangle in Histogram (LeetCode 84) 🔗 `largest_rectangle.cpp`

---

### 5. Binary Trees & BSTs (with Morris Traversal)
* **Theory:** Hierarchical structures. BSTs enforce `left < root < right`. Morris Traversal uses temporary threaded leaves to traverse tree inputs in $O(N)$ time and $O(1)$ space.
* **In-Repo C++ Implementations:**
  * [morris_traversal.cpp](./DSA/tree/morris_traversal.cpp) — $O(1)$ space Inorder traversal.
  * [validate_bst.cpp](./DSA/tree/validate_bst.cpp) — Recursive boundary validation.
  * [recover_bst.cpp](./DSA/tree/recover_bst.cpp) — Reordering swapped nodes.
  * [lca.cpp](./DSA/tree/lca.cpp) — Lowest Common Ancestor.
  * [largest_bst_in_bt.cpp](./DSA/tree/largest_bst_in_bt.cpp) — Validating BST sub-trees.
  * [bst_from_preorder.cpp](./DSA/tree/bst_from_preorder.cpp) — Constructing trees recursively.
* **Practice Tracker:**
  - [ ] Validate Binary Search Tree (LeetCode 98) 🔗 `validate_bst.cpp`
  - [ ] Recover Binary Search Tree (LeetCode 99) 🔗 `recover_bst.cpp`
  - [ ] Lowest Common Ancestor of a Binary Tree (LeetCode 236) 🔗 `lca.cpp`
  - [ ] BST Iterator (LeetCode 173) 🔗 `binary_search_tree.cpp`

---

### 6. Graph Algorithms
* **Theory:** Representation using adjacency list vectors. BFS uses queues for shortest paths; DFS uses recursion. Topological Sort resolves dependencies. Dijkstra relaxes node distances using min-heaps.
* **In-Repo C++ Implementations:**
  * [bfs.cpp](./DSA/graph/bfs.cpp) / [dfs.cpp](./DSA/graph/dfs.cpp) — Graph traversals.
  * [cycle_bfs.cpp](./DSA/graph/cycle_bfs.cpp) / [cycle_dfs.cpp](./DSA/graph/cycle_dfs.cpp) — Detecting cycles in undirected graphs.
  * [detect_cycle_directed.cpp](./DSA/graph/detect_cycle_directed.cpp) — DFS recursion-stack cycle checks.
  * [kann's_algorithm.cpp](./DSA/graph/kann's_algorithm.cpp) — In-degree BFS Topological Sort.
  * [topological_sort.cpp](./DSA/graph/topological_sort.cpp) — DFS Stack Topological Sort.
  * [dijkstra.cpp](./DSA/graph/dijkstra.cpp) — Single-source shortest path.
* **Practice Tracker:**
  - [ ] Course Schedule II (LeetCode 210) 🔗 `kann's_algorithm.cpp`
  - [ ] Network Delay Time (LeetCode 743) 🔗 `dijkstra.cpp`
  - [ ] Is Graph Bipartite? (LeetCode 785) 🔗 `dfs.cpp`
  - [ ] Find Eventual Safe States (LeetCode 802) 🔗 `detect_cycle_directed.cpp`

---

### 7. Heaps & Mathematical Invariants
* **Theory:** Heaps are array-based complete trees. Number theory covers modular arithmetic, divisor finding, and the Sieve of Eratosthenes for prime verification.
* **In-Repo C++ Implementations:**
  * [kthlarger.cpp](./DSA/array/kthlarger.cpp) — Finding Kth element.
  * [eratosthenes.cpp](./DSA/array/eratosthenes.cpp) — Sieve of Eratosthenes prime generator ($O(N \log \log N)$).
* **Practice Tracker:**
  - [ ] Kth Largest Element in an Array (LeetCode 215) 🔗 `kthlarger.cpp`
  - [ ] Count Primes (LeetCode 204) 🔗 `eratosthenes.cpp`

---

## 🚀 Compilation & Run Commands

To compile and execute any file locally:

```bash
# Compile with C++17 optimization
g++ -std=c++17 -O2 -o output_program DSA/tree/morris_traversal.cpp

# Run the binary
./output_program
```

---

## 👨‍💻 Author

<div align="center">

**Sahil Kumar**

[![GitHub](https://img.shields.io/badge/GitHub-Sahil--K--Y-181717?style=for-the-badge&logo=github)](https://github.com/Sahil-K-Y)

*"Master the fundamentals. The rest follows."* 💡

</div>

---

<div align="center">
<img src="https://capsule-render.vercel.app/api?type=waving&color=0:00599C,100:0080FF&height=100&section=footer"/>
</div>
