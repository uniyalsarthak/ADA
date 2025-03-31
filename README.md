# Analysis and Design of Algorithm


## Bubble Sort
Bubble sort is a sorting algorithm that repeatedly steps through the list to be sorted, compares each pair of adjacent items, and swaps them if they are in the wrong order.

It can be useful for sorting small datasets or in scenarios where simplicity of implementation is more important than speed.

![alt text](image.png)

Time Complexity:
Best Case: O(n) - This occurs when the list is already sorted.

Average Case: O(n^2) - On average, bubble sort will make n^2/2 comparisons

Worst Case: O(n^2) - This happens when the list is sorted in reverse order

## Selection Sort
Selection Sort is a simple comparison-based sorting algorithm that works by repeatedly selecting the smallest (or largest) element from the unsorted portion of the list and swapping it with the first element of the unsorted portion.

Can be used in cases where the number of swaps should be minimized (compared to Bubble Sort, which swaps more frequently).

Its best case, average case and worst case time complexity is O(n^2) as even if the array is already sorted, selection sort still scans and selects the minimum in each pass.

## Merge Sort
Merge Sort is a divide and conquer sorting algorithm that works by dividing an array into smaller subarrays, sorting them, and then merging them back together. 

Preferred when stable sorting (preserving the order of equal elements) is required. Used in sorting large datasets due to its efficient O(n log n) time complexity.

Its best case, average case and worst case time complexity is O(n*logn) as even if the array is already sorted, Merge Sort still divides and merges the elements.

## Quick Sort
Quick Sort is a divide and conquer sorting algorithm that works by selecting a "pivot" element, partitioning the array into two subarrays based on the pivot, and then recursively sorting the subarrays.

Commonly used in in-place sorting due to its O(1) space complexity.

Best Case: O(n log n), Average Case: O(n log n), Worst Case: O(n²)

## Magic Sqaure
A magic square is a square grid of distinct numbers arranged in such a way that the sum of numbers in each row, each column, and both main diagonals is the same. This constant sum is called the magic constant or magic sum.

Time complexity:O(n^2)

## 1D Array Peak element
A peak element in a 1D array is an element that is greater than or equal to its neighbors.

Time Complexity:O(log n) (Efficient Approach)

## Matrix Multiplication Iterative 
Matrix multiplication is the process of multiplying two matrices A (m × n) and B (n × p) to produce a resultant matrix C (m × p)

Matrix multiplication is widely used in various fields, including:

Computer Graphics & Image Processing: Used for transformations, scaling, and rotation of images.

Machine Learning & AI: Core operation in neural networks, deep learning, and data transformations.

Time Complexity:O(m*n*p)

## Min and Max element in an Array using Divide and conquer
The Min-Max problem is about finding the minimum and maximum elements in an array. Instead of using a simple linear scan (which takes 
O(n) time), we can use the Divide and Conquer approach to optimize it.

Used in:
Game Theory: Minimax algorithm in decision-making and AI (e.g., Chess, Tic-Tac-Toe) & Computational Geometry: Finding bounding box (smallest and largest points) in a dataset.

The iterative approach takes 2(n-1) comparisons in the worst case.
The divide-and-conquer approach takes only ~3n/2 comparisons, making it more efficient.

## Cosine Similarity
Cosine Similarity is a measure of similarity between two non-zero vectors in an inner product space.
Used in:Text Analysis & NLP: Used to compare the similarity of documents & Image Recognition: Measures similarity between feature vectors of images.

Time Complexity:O(n)

## Matrix Multiplication Divide and Conquer
The Divide and Conquer approach for matrix multiplication is based on recursively breaking down large matrices into smaller submatrices, multiplying them, and combining the results. This method is particularly useful for large matrices because it reduces the number of computations compared to the traditional iterative method.

Used in large-scale simulations, physics, and engineering problems where high-speed matrix operations are required.

Time Complexity:O(n^3)

## Strassen Matrix Multiplication
Strassen’s algorithm divides each matrix into four submatrices and reduces the number of multiplications from 8 to 7

Time Complexity:O(n^2.81)

## Activity Selection
The Activity Selection Problem is a greedy algorithm problem where we need to select the maximum number of activities that don’t overlap, given their start and end times.

Sorting takes O(n log n), and selecting activities takes O(n), so total time is O(n log n).

Used in CPU scheduling, conference room scheduling, and event planning to maximize task completion.

## Dijkstra algorithm
Dijkstra’s Algorithm is a greedy algorithm used to find the shortest path from a single source vertex to all other vertices in a weighted graph (with non-negative edge weights). It is widely used in network routing, mapping applications, and AI pathfinding.

Time Complexity:O((V+E)logV)

## Knapsack Problem
The Greedy Approach is used specifically for the Fractional Knapsack Problem, where we can take fractions of an item instead of the whole item. It works by selecting items based on their value-to-weight ratio.

Used for selecting stocks or projects with the highest return under budget constraints & Optimizing storage space for maximum efficiency.

Time Complexity:O(nlogn)

## Kruskal Algorithm
Kruskal’s Algorithm is a greedy algorithm used to find the Minimum Spanning Tree (MST) of a graph. It selects edges in increasing order of weight while ensuring that no cycles are formed.

Used in designing efficient networks like roads, electrical grids, and telecommunications.

Time Complexity:O(Elogv)

## Prim Algorithm
Prim’s Algorithm is a greedy algorithm used to find the Minimum Spanning Tree (MST) of a graph. The MST is a subset of edges that connects all vertices with the minimum total weight and without forming any cycles.

Helps in designing minimum-cost road/railway connections between cities.

Time Complexity:O(Elogv)

## Multistage Graph Algorithm

A multistage graph is a directed weighted graph where nodes are divided into multiple stages, and the goal is to find the shortest (or longest) path from a source node in the first stage to a destination node in the last stage. This problem is efficiently solved using Dynamic Programming (DP).

Time Complexity:O(V^2)

## All Pair Shortest Path Algorithm
The All-Pairs Shortest Path (APSP) problem involves finding the shortest path between every pair of nodes in a weighted graph. This is useful in various real-world applications such as network routing, transportation planning, and urban navigation systems.

Time Complexity:O(n^3)


