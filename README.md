**README: Analysis and Design of Selection Sort Algorithm**

### Overview
This repository presents an analysis and implementation of the Selection Sort algorithm, a simple and efficient sorting technique. Selection Sort works by repeatedly selecting the smallest (or largest) element from the unsorted portion of the list and moving it to the sorted portion.

### Selection Sort Algorithm
The algorithm can be described as follows:
```cpp
Selection_sort(a, n){
    For (i=0 to n-1){
        t = i;
        for(j = i+1 to n-1){
            if a[t] > a[j] then
                t = j
        }
        Swap(a[i],a[t])
    }
}
```

### Source Code
The provided source code (`selection_sort.cpp`) includes the implementation of the Selection Sort algorithm along with code for generating random arrays and measuring execution time for different array sizes.

### Execution
To execute the code:
1. Compile the source code.
2. Run the compiled executable.
3. The program will generate random arrays of increasing sizes and measure the average execution time for each size.

### Output
The program output provides insights into the execution time for various array sizes. Here's a sample output:
```
avg time taken for size of array = 0 is 0 microseconds  
avg time taken for size of array = 500 is 0 microseconds
avg time taken for size of array = 1000 is 1643 microseconds
avg time taken for size of array = 1500 is 5185 microseconds
...
avg time taken for size of array = 10000 is 116515 microseconds
```

### Conclusion
Based on the observed execution times, it can be concluded that the time complexity of the Selection Sort algorithm is O(n^2), where n is the size of the array. This quadratic time complexity is consistent with the nested loops used in the algorithm for scanning and swapping elements.

### Graphical Representation
For a graphical representation of the execution times, you can refer to the time complexity folder.

### Files
- `selection_sort.cpp`: Contains the source code for the algorithm implementation and execution time analysis.
- `unsorted.txt`: Output file containing recorded execution times for different array sizes.

Feel free to explore and analyze the provided code and results further. If you have any questions or suggestions, please don't hesitate to reach out.
