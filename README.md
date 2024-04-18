**README: Analysis and Design of Merge Sort Algorithm**

### Overview
This repository explores the Merge Sort algorithm, which is used to sort an unsorted list efficiently. The algorithm utilizes the concept of merging sorted lists to achieve optimal sorting.

### Merge Sort Algorithm
Merge Sort divides the unsorted list into sublists, sorts each sublist recursively, and then merges the sorted sublists to produce the final sorted list. The process is as follows:

1. Divide the list into two halves.
2. Recursively sort each half.
3. Merge the sorted halves to produce a single sorted list.

### Source Code
The provided source code (`merge_sort.cpp`) implements the Merge Sort algorithm and measures its execution time for sorting lists of varying sizes.

### Execution and Output
The code sorts lists of different sizes using the Merge Sort algorithm and records the average execution time. Here's a summary of the output:

- Average time taken for size of array = 10 is 0 microseconds
- Average time taken for size of array = 100 is 0 microseconds
- Average time taken for size of array = 1000 is 0 microseconds
- ...
- Average time taken for size of array = 100000 is 13224 microseconds

### Conclusion
- The Merge Sort algorithm demonstrates a time complexity of O(nlogn) in all cases, making it highly efficient for sorting large lists.
- The space complexity of Merge Sort is O(n), where n is the size of the input list.
- Graph for the code is in time complexity folder.

### Files
- `merge_sort.cpp`: Contains the source code for the Merge Sort algorithm and its execution time analysis.
- `mergeSort.txt`: Output file containing recorded execution times for Merge Sort.

Feel free to explore the source code and results further. If you have any questions or suggestions, please don't hesitate to reach out.
