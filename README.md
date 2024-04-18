**README: Analysis and Design of MaxMin Algorithm**

### Overview
This repository investigates the Max Min algorithm, which efficiently finds the maximum and minimum elements in an unsorted list. The algorithm employs a divide-and-conquer approach to achieve optimal performance.

### Max Min Algorithm
The Max Min algorithm operates as follows:

1. Divide the list into smaller segments.
2. Recursively find the maximum and minimum elements in each segment.
3. Combine the results to determine the overall maximum and minimum.

### Source Code
The provided source code (`maxMin.cpp`) implements the Max Min algorithm and measures its execution time for lists of varying sizes.

### Execution and Output
The code determines the maximum and minimum elements in unsorted lists of different sizes using the Max Min algorithm and records the average execution time. Here's a summary of the output:

- Average time taken for size of array = 10 is 0 microseconds
- Average time taken for size of array = 100 is 0 microseconds
- Average time taken for size of array = 1000 is 0 microseconds
- ...
- Average time taken for size of array = 100000 is 1637 microseconds

### Conclusion
- The Max Min algorithm demonstrates a time complexity of O(n) in all cases, making it highly efficient for finding the maximum and minimum elements in large lists.
- The space complexity of Max Min is O(1), indicating that it has a constant space requirement regardless of the input size.

### Files
- `maxMin.cpp`: Contains the source code for the Max Min algorithm and its execution time analysis.
- `maxMin.txt`: Output file containing recorded execution times for Max Min.

Feel free to explore the source code and results further. If you have any questions or suggestions, please don't hesitate to reach out.
