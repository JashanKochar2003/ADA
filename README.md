**README: Analysis and Design of Kth Smallest Algorithm**

### Overview
The Kth Smallest Problem involves finding the Kth smallest element in an unsorted list of elements. This repository explores a solution to this problem by combining the concepts of partitioning and binary search. The algorithm aims to efficiently identify the Kth smallest element in the list.

### Kth Smallest Algorithm
The algorithm operates as follows:
1. Apply the partitioning technique to the list, similar to Quick Sort, to rearrange elements around a chosen pivot.
2. Determine the position of the pivot element after partitioning.
3. If the position of the pivot is less than K, recursively apply the algorithm to the right subarray.
4. If the position of the pivot is equal to K, return the pivot element as the Kth smallest.
5. If the position of the pivot is greater than K, recursively apply the algorithm to the left subarray.

### Source Code
The provided source code (`kth_smallest.cpp`) implements the Kth Smallest Algorithm and measures its execution time for lists of varying sizes. It utilizes the partitioning technique to efficiently find the Kth smallest element.

### Execution and Output
The code computes the average execution time for different sizes of unsorted lists. Here's a summary of the output:
- Average time taken for size of array = 10 is 0 microseconds
- Average time taken for size of array = 100 is 0 microseconds
- Average time taken for size of array = 1000 is 0 microseconds
- ...
- Average time taken for size of array = 100000 is 1329 microseconds

### Conclusion
- The Kth Smallest Algorithm demonstrates efficient performance, with execution times scaling reasonably well as the size of the input list increases.
- By combining partitioning and binary search techniques, the algorithm efficiently identifies the Kth smallest element without the need for sorting the entire list.
- The algorithm's time complexity depends on the partitioning step, which is typically O(n) on average.
- The space complexity of the algorithm is O(1), as it operates in-place without requiring additional memory.
- Graph for this code is in time complexity folder.

Feel free to explore the source code and results further. If you have any questions or suggestions, please don't hesitate to reach out.
