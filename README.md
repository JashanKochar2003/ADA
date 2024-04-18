**README: Analysis and Design of Quick Sort Algorithm**

### Overview
This repository explores the Quick Sort algorithm, a highly efficient sorting algorithm commonly used in computer science. Quick Sort sorts an unsorted list of elements in an optimal way by employing a divide-and-conquer strategy.

### Quick Sort Algorithm
The Quick Sort algorithm operates as follows:

1. Choose a pivot element from the list.
2. Partition the list into two sublists based on the pivot: elements less than the pivot and elements greater than the pivot.
3. Recursively apply Quick Sort to each sublist.
4. Combine the sorted sublists to obtain the final sorted list.

### Source Code
The provided source code (`quickSort.cpp`) implements the Quick Sort algorithm and measures its execution time for lists of varying sizes. It utilizes the partitioning technique to efficiently sort the elements.

### Execution and Output
The code sorts unsorted lists of different sizes using the Quick Sort algorithm and records the average execution time. Here's a summary of the output:

- Average time taken for size of array = 10 is 0 microseconds
- Average time taken for size of array = 100 is 0 microseconds
- Average time taken for size of array = 1000 is 299 microseconds
- ...
- Average time taken for size of array = 100000 is 172376 microseconds

### Conclusion
- Quick Sort demonstrates a time complexity of O(n log n) in the best and average cases, making it highly efficient for sorting large lists.
- However, in the worst case scenario where elements are already sorted, Quick Sort's time complexity increases to O(n^2).
- Despite the worst-case scenario, Quick Sort typically outperforms other sorting algorithms due to its efficient partitioning strategy.
- The space complexity of Quick Sort is O(1), indicating that it has a constant space requirement regardless of the input size.
- graph for this code is in time complexity graph

Feel free to explore the source code and results further. If you have any questions or suggestions, please don't hesitate to reach out.
