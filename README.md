**README: Analysis and Design of Iterative Quick Sort Algorithm**

### Overview
The Iterative Quick Sort Algorithm aims to sort an unsorted list of elements using the partitioning technique and the Quick Sort algorithm iteratively, instead of the typical recursive approach. This implementation employs a stack to manage the iterative process efficiently.

### Quick Sort Iterative Algorithm
The algorithm follows these steps:
1. Initialize a stack to keep track of subarrays to be sorted.
2. Push the initial bounds (low and high indices) of the entire array onto the stack.
3. While the stack is not empty, pop the bounds of a subarray.
4. Apply the partitioning technique to the subarray.
5. If the partitioned subarrays are small enough, sort them using the traditional recursive Quick Sort.
6. If the partitioned subarrays are large, push their bounds onto the stack for further processing.
7. Repeat until all subarrays have been sorted.

### Source Code
The provided source code (`quickSort_ite.cpp`) implements the Iterative Quick Sort Algorithm and measures the number of steps required for sorting lists of varying sizes. It utilizes a stack to manage the iterative process efficiently and ensures proper sorting of subarrays.

### Execution and Output
The code computes the average number of steps taken for sorting different sizes of unsorted lists. Here's a summary of the output:
- Average steps taken for size of array = 10 is 4
- Average steps taken for size of array = 100 is 6
- Average steps taken for size of array = 1000 is 6
- ...
- Average steps taken for size of array = 100000 is 6

### Conclusion
- The Iterative Quick Sort Algorithm efficiently sorts unsorted lists by iteratively applying the partitioning technique and Quick Sort.
- Utilizing a stack to manage the iterative process ensures efficient memory usage and avoids potential stack overflow issues associated with recursive algorithms.
- The algorithm demonstrates consistent performance, with the number of steps required for sorting remaining constant regardless of the size of the input list.
- By avoiding recursion, the algorithm enhances clarity and simplifies the implementation while maintaining the efficiency of the Quick Sort algorithm.

Feel free to explore the source code and results further. If you have any questions or suggestions, please don't hesitate to reach out.
