## Searching Algorithm
### [Linear Search](/search/linearSearch.cpp)
- Time Complexity: `O(n)`
- Linear search is rarely used practically because other search     algorithms such as the binary search algorithm and hash tables allow significantly faster-searching comparison to Linear search

### [Binary Search](/search/binarySearch.cpp)
- Time Complexity: `O(log n)`
- Binary search is used to find an element in a sorted array.
### [Binary Search Tree](/search/binarySearchTree.cpp)
- Time Complexity: `O(log n)`
- Binary search tree is a binary tree data structure that is used to store a sorted list of elements.

## Sorting Algorithm
### [Selection Sort](/sort/selectionSort.cpp)
- Time Complexity: `O(n^2)`
- Selection sort is a simple sorting algorithm that works by repeatedly finding the minimum element (considering ascending order) from unsorted list and putting it at the beginning.
- The good thing about selection sort is it never makes more than `O(n)` swaps and can be useful when memory write is a costly operation. 
- Best case, worst case and averange case: `O(n^2)`
- In-place: `true`
- Stable: `false`
### [Bubble Sort](/sort/bubbleSort.cpp)
- Time Complexity: `O(n^2)`
- Bubble sort is a simple sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.
- Best case: `O(n)` (already sorted)
- Worst case: `O(n^2)` (reverse sorted)
- Average case: `O(n^2)`
- In-place: `true`
- Stable: `true`
### [Insertion Sort](/sort/insertionSort.cpp)
- Time Complexity: `O(n^2)`
- Insertion sort is a simple sorting algorithm that works by iterating through each element and placing it in the correct position.
- Best case: `O(n)` (already sorted)
- Worst case: `O(n^2)` (reverse sorted)
- Average case: `O(n^2)`
- In-place: `true`
- Stable: `true`
### [Merge Sort](/sort/mergeSort.cpp)
- Time Complexity: `O(n log n)`
- Merge sort is a divide and conquer algorithm that works by breaking down the array into smaller sub-arrays and then merging them in sorted order.
- Best case, worst case and averange case: `O(n log n)`
- Slower comparative to the other sort algorithms for smaller tasks.
- Merge sort algorithm requires an additional memory space of 0(n) for the temporary array.
- It goes through the whole process even if the array is sorted.
- In-place: `false`
- Stable: `true`
### [Quick Sort](/sort/quickSort.cpp)
- Time Complexity: `O(n log n)`
- Analysis of Quick Sort: `T(n) = T(k) + T(n-k-1) + Θ(n)`
- Worst case: `O(n^2)` (reverse sorted or sorted) 
- Best case: `O(n log n)` (The best case occurs when the partition process always picks the middle element as pivot. Following is recurrence for best case.)
- Average case: `O(n log n)`
- Quick sort is a divide and conquer algorithm that works by selecting a pivot element and partitioning the array around the pivot.
- In-place: `true`
- Stable: `false`


Ngẫu nhiên: 
Heap sort, Merge sort. `O(nlogn) `| Bubble sort, Insertion sort. `O(n^2)`

Sắp xếp: 
Bubble sort, Insertion sort. `O(n)` | Quick sort. `O(n^2)`

Sắp xếp ngược: 
Heap sort, Merge sort. `O(nlogn)` | Bubble sort, Insertion sort. `O(n^2)`

Bằng nhau: 
Insertion sort, Bubble sort. `O(n)`

Chỉ một hằng số phần tử sai vị trí: 
Heap sort, Merge sort. `O(nlogn)` | Insertion sort 

## Graph Algorithm
### [Depth First Search](/graph/depthFirstSearch.cpp)
- Time Complexity: `O(n)`
- Depth first search is a graph traversal algorithm that traverses a graph from a given source vertex.
### [Breadth First Search](/graph/breadthFirstSearch.cpp)
- Time Complexity: `O(n)`
- Breadth first search is a graph traversal algorithm that traverses a graph from a given source vertex.
### [Dijkstra's Algorithm](/graph/dijkstra.cpp)
- Time Complexity: `O(n^2)` (adjacency matrix)
- Time complexity of Dijkstra's algorithm is `O(E log V)` where `E` is the number of edges and `V` is the number of vertices. (adjacent List)
## Greedy Algorithm
### [Kruskal's Minimum Spanning Tree](/greedy/kruskal.cpp)
- Time Complexity: `O(E log V)` (E is the number of edges and V is the number of vertices)
- Kruskal's algorithm is used to find the minimum spanning tree of a given connected, undirected and weighted graph.
### [Knapsack Problem](/greedy/knapsack.cpp)

## Divide and Conquer Algorithm
### [Binary Search](/search/binarySearch.cpp)
- Time Complexity: `O(log n)`
- Binary search is used to find an element in a sorted array.
### [Quick Sort](/sort/quickSort.cpp)
- Time Complexity: `O(n log n)`
- Analysis of Quick Sort: `T(n) = T(k) + T(n-k-1) + Θ(n)`
- Worst case: `O(n^2)` (reverse sorted or sorted) 
- Best case: `O(n log n)` (The best case occurs when the partition process always picks the middle element as pivot. Following is recurrence for best case.)
- Average case: `O(n log n)`
- Quick sort is a divide and conquer algorithm that works by selecting a pivot element and partitioning the array around the pivot.
- In-place: `true`
- Stable: `false`

## Dynamic Programming
### [Longest Increasing Subsequence](/dp/longestIncreasingSubsequence.cpp)
- Time Complexity: `O(n^2)`
### [Knapsack Problem](/dp/knapsack.cpp)
- Recurrence: `f(i, w) = max(f(i-1, w), f(i-1, w-w_i) + v_i)`
- Time Complexity: `O(2^n)`
- Dynamic Programming:
- Time Complexity: `O(N*W)` (N is the number of items and W is the weight capacity)
