**README: Analysis and Design of Truth Table Algorithm**

### Overview
This repository presents an analysis and implementation of the Truth Table algorithm, which generates all possible Boolean combinations for a given number of variables (n). The algorithm recursively explores all possible truth values for each variable and prints the corresponding truth table.

### Truth Table Algorithm
The algorithm can be described as follows:
```cpp
TT(n, k=0){
    If(k == (n+1)) then write (x[1….n]);
    Else{
        X[k] = T ;
        TT(n, k+1);
        X[k] = F;
        TT(n, k+1);
    }
}
```
Where `T` represents `True`, `F` represents `False`, and `x[1….n]` represents the Boolean combination.

### Source Code
The provided source code (`truth_table.cpp`) contains the implementation of the Truth Table algorithm along with code for measuring the execution time for different numbers of variables.

### Execution
To execute the code:
1. Compile the source code.
2. Run the compiled executable.
3. The program will generate truth tables for various numbers of variables and measure the average execution time.

### Output
The program output provides insights into the execution time for different numbers of variables. Here's a sample output:
```
avg time taken for size of array = 1 is 0 microseconds
avg time taken for size of array = 2 is 0 microseconds
avg time taken for size of array = 3 is 0 microseconds
...
avg time taken for size of array = 23 is 396884 microseconds
avg time taken for size of array = 24 is 859050 microseconds
avg time taken for size of array = 25 is 1881992 microseconds
```

### Conclusion
Based on the observed execution times, it can be concluded that the time complexity of the Truth Table algorithm is O(2^n), where n is the number of variables. This exponential time complexity arises from the exponential growth in the number of possible Boolean combinations as the number of variables increases.

### Graphical Representation
For a graphical representation of the execution times, you can refer to the time complexity folder.

### Files
- `truth_table.cpp`: Contains the source code for the algorithm implementation and execution time analysis.
- `truth_table_result.txt`: Output file containing recorded execution times for different numbers of variables.

Feel free to explore and analyze the provided code and results further. If you have any questions or suggestions, please don't hesitate to reach out.
