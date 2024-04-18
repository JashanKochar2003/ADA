**README: Analysis and Design of Permutation Generation Algorithm**

### Overview
This repository provides an analysis and implementation of the Permutation Generation algorithm. The algorithm systematically generates every possible permutation of elements using a swapping technique. Each permutation is produced exactly once, making it a comprehensive method for generating permutations.

### Permutation Generation Algorithm
The algorithm can be described as follows:
```cpp
PG(n, L =1){
    If(L == n+1) then print
    Else{
        For(j=L to n){
            Swap(a[j],a[L])
            PG(n, L+1)
            Swap(a[j],a[L])
        }
    }
}
```
Where `n` is the number of elements and `a` is the array containing the elements to be permuted.

### Source Code
The provided source code (`permutation_generation.cpp`) contains the implementation of the Permutation Generation algorithm along with code for measuring the execution time for different sizes of input.

### Execution
To execute the code:
1. Compile the source code.
2. Run the compiled executable.
3. The program will generate permutations for various sizes of input and measure the average execution time.

### Output
The program output provides insights into the execution time for different sizes of input. Here's a sample output:
```
avg time taken for size of array = 1 is 0 microseconds
avg time taken for size of array = 2 is 0 microseconds
avg time taken for size of array = 3 is 0 microseconds
...
avg time taken for size of array = 10 is 120882 microseconds
avg time taken for size of array = 11 is 1445554 microseconds
```

### Conclusion
Based on the observed execution times, it can be concluded that the time complexity of the Permutation Generation algorithm is O(n!), where n is the number of elements. This factorial time complexity arises due to the exponential growth in the number of permutations as the input size increases.

### Graphical Representation
For a graphical representation of the execution times, you can refer to the time complexity folder.

### Files
- `permutation_generation.cpp`: Contains the source code for the algorithm implementation and execution time analysis.
- `permutation_generation_result.txt`: Output file containing recorded execution times for different sizes of input.

Feel free to explore and analyze the provided code and results further. If you have any questions or suggestions, please don't hesitate to reach out.
