**AIM: Analysis and Design of Sum of Array Algorithm**

### Overview
This repository provides an implementation and analysis of the "Sum of Array" algorithm, which is used to linearly calculate the sum of all elements present in an array. The algorithm follows a recursive approach to compute the sum.

### Algorithm
The algorithm is defined as follows:
```cpp
Sum(a,n){
    If(n == 1)
        Return a[1];
    Else
        Return a[n] + Sum(a, n-1);
}
```

### Source Code
The provided source code (`sum_of_array.cpp`) contains the implementation of the algorithm along with code for generating arrays and measuring the execution time for different array sizes.

### Execution
To execute the code:
1. Compile the source code.
2. Run the compiled executable.
3. The program will generate arrays of increasing sizes and measure the average execution time for each size.

### Output
The output of the program provides insights into the execution time for different array sizes. Here's a sample output:
```
avg time taken for size of array = 10 is 0 microseconds
avg time taken for size of array = 100 is 0 microseconds
avg time taken for size of array = 1000 is 0 microseconds
avg time taken for size of array = 5000 is 94.5 microseconds
avg time taken for size of array = 25000 is 313.5 microseconds
avg time taken for size of array = 50000 is 449.5 microseconds
```

### Conclusion
Based on the observed execution times, it can be concluded that the time complexity of the "Sum of Array" algorithm is O(n), where n is the size of the array. This linear time complexity is consistent with the recursive nature of the algorithm.

### Graphical Representation
For a graphical representation of the execution times, you can refer to the time complexity folder.

### Files
- `sum_of_array.cpp`: Contains the source code for the algorithm implementation and execution time analysis.
- `sum_of_array_result.txt`: Output file containing the recorded execution times for different array sizes.

Feel free to explore and analyze the provided code and results further. If you have any questions or suggestions, please don't hesitate to reach out.
